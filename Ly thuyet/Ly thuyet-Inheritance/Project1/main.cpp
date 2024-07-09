#include "NhanVien.h"


void NhanVien::nhap() {
    do {
        cout << "Nhap ma so: ";
        cin >> maNV;
        if (maNV <= 100) {
            cout << "Nhap lai!" << endl;
        }
    } while (maNV <= 100);
    cin.ignore(1);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    phanLoai = "NhanVien";
}


void NVSanXuat::nhap()
{
    // do{
    // cout<<"Nhap ma so: ";
    // cin >> maNV;
    // if(maNV <= 0){
    //     cout<<"Nhap lai!"<<endl;
    // }
    // }while(maNV <= 0);
    // cin.ignore(1);
    // cout<<"Nhap ho ten: ";
    // getline(cin, hoTen);
    NhanVien::nhap();
    phanLoai = "SanXuat";
    // phanLoai = "San Xuat";
    // phanLoai = "sx";
    // phanLoai = "sanxuat";
    cout << "Nhap so san pham: ";
    cin >> soSP;
}


int NVSanXuat::tinhLuong() {
    return soSP * 1000;
}


void NhanVien::xuat() {
    // cout << maNV
    //     << " " << hoTen
    //     << " " << phanLoai
    //     << " " << tinhLuong() + soSP * 1000;
    cout << maNV
        << " " << hoTen
        << " " << phanLoai;
}


void NVSanXuat::xuat() {
    NhanVien::xuat();
    cout << " " << soSP;
    cout << " " << tinhLuong();
}


NhanVien::NhanVien() {
    cout << "NhanVien - Default cons" << endl;
    maNV = 101;
    hoTen = "Ho Tuan Thanh";
    phanLoai = "NhanVien";
}


NhanVien::NhanVien(int pMaNV) {
    cout << "NhanVien - 1-arg cons" << endl;
    maNV = pMaNV;
    hoTen = "Ho Tuan Thanh";
    phanLoai = "NhanVien";
}


NhanVien::NhanVien(int pMaNV, string pHoTen) {
    cout << "NhanVien - 2-args cons" << endl;
    maNV = pMaNV;
    hoTen = pHoTen;
    phanLoai = "NhanVien";
}


NVSanXuat::NVSanXuat() {
    cout << "NVSanXuat - Default cons" << endl;
    soSP = 0;
}

// NVSanXuat::NVSanXuat(int pMaNV, string pHoTen){
//     cout << "NVSanXuat - 2-args cons" << endl;
// }

// // intialization list
// NVSanXuat::NVSanXuat(int pMaNV, string pHoTen): NhanVien(pMaNV, pHoTen){
//     cout << "NVSanXuat - 2-args cons" << endl;
// }


NVSanXuat::NVSanXuat(int pMaNV, string pHoTen) :NhanVien(pMaNV, pHoTen) {
    // anonymous object, another object
    cout << "NVSanXuat - 2-args cons" << endl;
}
//=> Neu khong ke thua constructor cua lop cha thi no se tu goi den default constructor

int main() {
     //cout << "nv1" << endl;
     //NhanVien nv1;
     //nv1.nhap();


     cout << "sx1" << endl;
     NVSanXuat sx1;
     sx1.nhap();


    // sx1.xuat();
    // cout << endl;


    // NVSanXuat sx2;
    // sx2.xuat();


    /*cout << "sx3" << endl;
    NVSanXuat sx3(103, "Son Tung not MTP");
    sx3.xuat();*/


    return 0;
}
