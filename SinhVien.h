#include <iostream>
#include <fstream>
#include <sstream>
#include "conio.h"
#include "ThuVien.h"
using namespace std;
class SinhVien : public ThuVien
{
private:
    string _MSSV;
    string _pass;

public:
    SinhVien(string = "", string = "");
    ~SinhVien();
    string MSSV();
    void Menu();
    void Back();
    void DangNhap();
    void DangXuat();
    void ThayDoiMatKhau();
    void DangKy();
};