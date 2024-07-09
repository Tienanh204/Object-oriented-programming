#include"RandomProgram.h"
Student::Student()
{
	ID = "";
	count = 0;
}

Student::Student(string _id, int _count)
{
	ID = _id;
	count = _count;
}

void Student::setID(string _id)
{
	ID = _id;
}
void Student::setCount(int _count)
{
	count += _count;
}


string Student::getID()
{
	return ID;
}

int Student::getCount()
{
	return count;
}

//-----------------------
//Constructor
Session::Session(vector<Student> _student)
{
	student = _student;
	randStudent = _student;
}

//Dox thong tin tu file CSV
set<int> speedCount;
void Session::readFromCSV(string filename)
{
	speedCount.clear();
	ifstream fin;
	fin.open(filename + ".csv", ios::in);
	if (!fin)
	{
		cout << "Can't open file" << endl;
		return;
	}

	string line;
	while (getline(fin, line))
	{
		stringstream ss(line);
		string id;
		string cnt;

		getline(ss, id, ',');
		getline(ss, cnt);

		cnt.erase(remove(cnt.begin(), cnt.end(), ' '), cnt.end());
		if (!cnt.empty())
		{
			Student stu = { id, stoi(cnt)};
			student.push_back(stu);//Mang chinh de luu su thay doi
			randStudent.push_back(stu);//Mang phu de thuc hien Random
			speedCount.insert(stoi(cnt));
		}
	}
	fin.close();
}

//Tinh toan phan tram phat bieu cua cac nhom phat bieu va luu vao file
void Session::calculateProbability(string filename)
{
	double rateSpeechCounts = 100 / speedCount.size();

	vector<pair<int, double>>result;//Luu so phat bieu va ty le phan tram tuong ung
	int i = 1;
	for (int x : speedCount)
	{
		double Probability = 100 - i * rateSpeechCounts;
		result.push_back({ x,Probability});
		i++;
	}

	//Ghi ket qau vao file
	ofstream out;
	out.open(filename + ".txt", ios::in);
	if (!out)
	{
		cout << "Can't open file" << endl;
		return;
	}
	out << "So lan phat bieu,Ty le" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		out << result[i].first << ","
			<< fixed << setprecision(2) << result[i].second << endl;
	}
	out.close();
}

//------------------------------------
//Chon 1 hoc sinh bat ki
string Session::chooseRandomStudent()
{
	random_device rd;
	mt19937 gen(rd());//Phat sinh ngau nhien cua he thong
	int minSpeed = randStudent[0].getCount();
	for (int i = 1; i < randStudent.size(); i++)
	{
		//Lay ra so loai phat bieu it nhat
		minSpeed = min(minSpeed, randStudent[i].getCount());
	}
	vector<Student>result;//Gom nhom cac sinh vien co so phat bieu it nhat
	for (int i = 0; i < randStudent.size(); i++)
	{
		if (randStudent[i].getCount() == minSpeed)
		{
			result.push_back(student[i]);
		}
	}

	uniform_int_distribution<> dis(0, result.size() - 1);//Khoi tao phan phoi deu
	int randomIndex = dis(gen);//Tra ve vi tri ngau nhien cua sinh vien trong mang
	string removeID= result[randomIndex].getID();
	removeStudent(removeID);//Xoa sinh vien da goi len bang (Tranh goi lai 2 lan)
	return removeID;
}

//Xoa sinh vien ra khoi mang de tranh goi 2 lan lien tiep
void Session::removeStudent(string removeID)
{
	for (int i = 0; i < randStudent.size(); i++)
	{
		if (randStudent[i].getID() == removeID)
		{
			randStudent.erase(randStudent.begin() + i);
			break;
		}
	}
	int index = 0;
	for (int i = 0; i < student.size(); i++)
	{
		if (student[i].getID() == removeID)
		{
			student[i].setCount(1);
		}
	}
}

//Cap nhap su thay doi vao file CSV sau khi ket thuc 1 Session
void Session::updateFileCSV(string filename)
{
	ofstream out;
	out.open(filename + ".csv", ios::in);
	if (!out)
	{
		cout << "Can't open file" << endl;
		return;
	}
	for (int i = 0; i < student.size(); i++)
	{
		out << student[i].getID() << "," << student[i].getCount() << endl;
	}
	out.close();
}