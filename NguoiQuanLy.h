#include <iostream>
#include <fstream>
#include <sstream>
#include "ThuVien.h"
#include "conio.h"
using namespace std;
class NguoiQuanLy : public ThuVien
{
private:
    string _admin;
    string _pass;

public:
    NguoiQuanLy(string = "", string = "");
    ~NguoiQuanLy();
    void DangNhap();
    void DangXuat();
    void Back();
    void Menu();
    void ThayDoiMatKhau();
};