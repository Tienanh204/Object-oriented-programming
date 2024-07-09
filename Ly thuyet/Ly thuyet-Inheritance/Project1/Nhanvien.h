#pragma once
#define _NHANVIEN_H_


#include <iostream>
#include <string>
using namespace std;


class NhanVien
{
protected:
    int maNV;
    string hoTen;
    string phanLoai;
public:
    void nhap();
    void xuat();
    int tinhLuong() {
        return 0;
    }


    // // v2
    // int tinhLuong(int heSo, int soLuong){
    //     return heSo * soLuong;
    // }


    // // ban ao xanh
    // int tinhLuong(){
    //     return 1000000;
    // }


    // int tinhLuong(string phanLoai, int heSo){
    //     return phanLoai * heSo;
    // }


    NhanVien();
    NhanVien(int pMaNV);
    NhanVien(int pMaNV, string pHoTen);

};




class NVSanXuat : public NhanVien
{
private:
    int soSP;
public:
    // override
    void nhap();
    // void nhapSX(); // ko phai la override
    void xuat();
    int tinhLuong();


    NVSanXuat();
    NVSanXuat(int pMaNV, string pHoTen);
};


class NVCongNhat : public NhanVien
{
private:
    int soNgayLam;
};
