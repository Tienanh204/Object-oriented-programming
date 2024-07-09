#include "StudentList.h"

map<int, set<string>> StudentList::getRandStudent() {
	return this->randStudent;
}

map<int, set<string>> StudentList::getStudent() {
	return this->student;
}

// Áp dụng hàm nghịch đảo tuyến tính để tăng xác suất cho các giá trị nhỏ hơn
double inverseLinear(double x, double minVal, double maxVal) {
	return minVal + x * x * (maxVal - minVal);
}

void StudentList::readFromCSV(string filename)
{
	Student student;
	string line;
	fstream fin(filename, ios::in);
	if (fin.fail()) {
		cout << "Opening file failed!" << endl;
		return;
	}
	while (!fin.eof()) {
		fin >> line;
		stringstream ss(line);
		string word;
		getline(ss, word, ',');
		student.setStudentCode(word);
		getline(ss, word, ',');
		student.setCount(stoi(word));
		this->student[student.getCount()].insert(student.getStudentCode());
	}
	fin.close();
}

StudentList::StudentList(map<int, set<string>> _student, map<int, set<string>> _randStudent) {
	student = _student;
	randStudent = _randStudent;
}

// Hàm random chuỗi từ một mảng các chuỗi
string randomString(const set<string>& se) {
	vector<string> v(se.begin(), se.end());
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, v.size() - 1);
	int random_index = dis(gen);
	return v[random_index];
}

void StudentList::randomStudentSource(bool replacement) {
	int sum = 0;
	for (int i = 0; i < this->student.size(); i++) 
		sum += (i + 1);
	cout << sum << endl;
	double avg = (double)100 / sum;
	vector<double> v;
	int cnt = this->student.size();
	for (int i = 0; i < this->student.size(); i++) {
		if (i == 0) {
			v.push_back(avg * cnt / 100);
		}
		else {
			v.push_back(v[i - 1] + (avg * cnt / 100));
		}
		cnt--;
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dis(0.0, 1.0);
	double min_val = 0; // Giá trị nhỏ nhất trong dãy
	double max_val = 1; // Giá trị lớn nhất trong dãy
	double random_value = dis(gen);
	double random_number = inverseLinear(random_value, min_val, max_val);
	auto it_v = lower_bound(v.begin(), v.end(), random_number);

	Student s;
	int ans = 0;
	for (auto it : this->student) {
		if (ans == it_v - v.begin()) {
			s.setStudentCode(randomString(it.second));
			s.setCount(it.first);
			break;
		}
		ans++;
	}

	cout <<"Student code: "<< s.getStudentCode() << endl;

	if (replacement)//Cho phep goi lai nhieu lan
	{
		this->randStudent[s.getCount() + 1].insert(s.getStudentCode());
		this->student[s.getCount()].erase(s.getStudentCode());
	}
	else//Khong cho phep goi lai nhieu lan
	{
		if (this->student[s.getCount()].empty()) {
			auto it = this->student.find(s.getCount());
			this->student.erase(it);
		}
	}
}

void StudentList::updateMpNew() {
	if (this->student.empty())
		return;
	for (auto it : student) {
		for (auto x : it.second) {
			this->randStudent[it.first].insert(x);
		}
	}
}

void StudentList::updateFileCSV(string file) {
	updateMpNew();
	fstream out(file, ios::out | ios::trunc);
	if (out.fail()) {
		cout << "Opening file failed!" << endl;
		return;
	}
	for (auto x : this->randStudent) {
		for (auto y : x.second) {
			out << y << "," << x.first << endl;
		}
	}
	out.close();
}

//Random theo file config.txt
//Tinh toan phan tram phat bieu cua cac nhom phat bieu va luu vao file

void StudentList::calculateProbability(string filename)
{
	set<int>speedCount;
	for (auto it : student)
	{
		speedCount.insert(it.first);
	}
	double rateSpeechCounts = 100 / speedCount.size();

	map<int, double> result;
	int i = 1;
	for (int x : speedCount)
	{
		double Probability = 100 - i * rateSpeechCounts;
		result.insert({ x, Probability });
		i++;
	}
	ofstream out;
	out.open(filename, ios::in);
	if (!out)
	{
		cout << "Can't open file" << endl;
		return;
	}
	out << "So lan phat bieu,Ty le" << endl;
	for (auto it : result)
	{
		out << it.first << ","
			<< fixed << setprecision(2) << it.second << endl;
	}
	out.close();
}

void StudentList::randomStudentConfig(bool replacement)
{
	int minSpeed = INT_MAX;
	for (auto it : student)
	{
		minSpeed = min(minSpeed, it.first);
	}
	vector<string>result;//Gom nhom cac sinh vien co so phat bieu it nhat

	for (auto it : student)
	{
		if (it.first == minSpeed)
		{
			for (auto y : it.second)
			{
				result.push_back(y);
			}
		}
	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, result.size() - 1);
	int randomIndex = dis(gen);
	string randID = result[randomIndex];

	cout <<"Student code: "<< randID << endl;

	Student s;
	bool check = false;
	for (auto x : student)
	{
		for (auto y : x.second)
		{
			if (y == randID)
			{
				s.setStudentCode(randID);
				s.setCount(x.first);
				check = true;
				break;
			}
		}
		if (check)
			break;
	}
	if (replacement)//Cho phep goi lai nhieu lan
	{
		this->randStudent[s.getCount() + 1].insert(s.getStudentCode());
		this->student[s.getCount()].erase(s.getStudentCode());
	}
	else//Khong cho phep goi lai nhieu lan
	{
		if (this->student[s.getCount()].empty()) {
			auto it = this->student.find(s.getCount());
			this->student.erase(it);
		}
	}
}
