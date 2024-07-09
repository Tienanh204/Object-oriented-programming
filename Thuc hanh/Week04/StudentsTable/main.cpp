#include"StudentsTable.h"
#include"StudentProvider.h"

int main() {
    auto students = StudentProvider::getAll();

    vector<string> headers = { "STT", "MSSV", "Ho va ten", "Email" };
    vector<int> columnSizes = { 3, 4, 20, 20 };
    StudentsToTableConverter table(headers, columnSizes);

    auto info = table.convert(students);
    cout << info;

    return 0;
}