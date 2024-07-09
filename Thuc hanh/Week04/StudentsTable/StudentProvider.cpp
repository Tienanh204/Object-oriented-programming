#include"StudentProvider.h"
#include"StudentsTable.h"

vector<Student> StudentProvider::getAll() {
    return {
        Student("001", "Nguyen Van Minh", "nvminh@gmail.com"),
        Student("002", "Cao Ha Thang", "chthang@gmail.com"),
        Student("003", "Tran Duc Tri", "tdtri@gmail.com")
    };
}