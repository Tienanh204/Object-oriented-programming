#include"StudentsTable.h"

Student::Student()
{
    _id = "";
    _fullname = "";
    _email = "";
}
Student::Student(string id, string fullname, string email)
{
    _id = id;
    _fullname = fullname;
    _email = email;
}

StudentsToTableConverter::StudentsToTableConverter(vector<string> headers, vector<int> columnSizes)
{
    _headers = headers;
    _columnSizes = columnSizes;
}


string StudentsToTableConverter::convert(vector<Student> students) {
    ostringstream oss;

    // Print headers
    oss << "|" << setw(_columnSizes[0]) << right << _headers[0] << "|";
    for (size_t i = 1; i < _headers.size(); ++i) {
        oss << setw(_columnSizes[i]) << right << _headers[i] << "|";
    }
    oss << "\n";

    for (size_t i = 1; i < _headers.size(); ++i) {
        oss << string(_columnSizes[i] + 3, '-');
    }
    oss << "\n";

    // Print data
    //for (size_t i = 0; i < students.size(); ++i) {
    //    oss << "|" <<setw(_columnSizes[0]) << right << i + 1 << "|";
    //    oss << setw(_columnSizes[1]) << right << students[i]._id << "|";
    //    oss << setw(_columnSizes[2]) << right << students[i]._fullname << "|";
    //    oss << setw(_columnSizes[3]) << right << students[i]._email << "|\n";
    //}

    int i = 1;
    for (const auto& student : students) {
        oss << "|" << setw(_columnSizes[0]) << right << i << "|";
        oss << StudentToRowConverter(_columnSizes).convert(student) + "\n";
        i++;
    }

    return oss.str();
}

string StudentsToTableConverter::StudentToRowConverter::convert(Student student) {
    ostringstream oss;
    oss << setw(_columnSizes[1]) << right << student._id << "|";
    oss << setw(_columnSizes[2]) << right << student._fullname << "|";
    oss << setw(_columnSizes[3]) << right << student._email << "|";
    return oss.str();
}
