
#include"main.h"

void IntegersCsv()
{
    vector<int> result; // Changed the vector type to store integers

    ifstream fin;
    fin.open("data.txt", ios::in);
    if (!fin)
    {
        cout << "Can't open file" << endl;
        return;
    }

    int cnt = 0;
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            result.push_back(stoi(token));
            cnt++;
        }
    }
    fin.close();

    sort(result.begin(), result.end());

    cout << "Reading data.txt..." << endl;
    cout << "Found " << cnt << " numbers." << endl;
    for (int x : result)
    {
        cout << x << " ";
    }
}

int main() {
    IntegersCsv();
    return 0;
}
