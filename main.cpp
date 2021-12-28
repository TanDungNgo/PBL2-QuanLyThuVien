#include "SinhVien.h"
#include "NguoiQuanLy.h"
#include "Dohoa.h"
SinhVien sv;
NguoiQuanLy ql;
Dohoa dh;
void Menu()
{
    char c;
    dh.textcolor(3);
    cout << "\n\t\t\t\t============> HE THONG QUAN LY THU VIEN <============";
    cout << "\n\t\t\t\t|| 1. SINH VIEN DANG NHAP                          ||";
    cout << "\n\t\t\t\t|| 2. NGUOI QUAN LY DANG NHAP                      ||";
    cout << "\n\t\t\t\t|| 3. SINH VIEN DANG KY                            ||";
    cout << "\n\t\t\t\t|| 0. THOAT KHOI CHUONG TRINH                      ||";
    cout << "\n\t\t\t\t=====================================================\n";
    dh.textcolor(13);
    printf("\n\t%c", 16);
    cout << "Nhap su lua chon cua ban: ";
    c = getch();
    switch (c)
    {
    case '1':
        sv.DangNhap();
        system("cls");
        Menu();
        break;
    case '2':
        ql.DangNhap();
        system("cls");
        Menu();
        break;
    case '3':
        sv.DangKy();
        system("cls");
        Menu();
        break;
    case '0':
        system("cls");
        cout << endl;
        dh.textcolor(2);
        cout << "\t\t\tKET";
        dh.textcolor(3);
        cout << " THUC";
        dh.textcolor(6);
        cout << " CHUONG";
        dh.textcolor(4);
        cout << " TRINH !";
        getch();
        break;
    default:
        dh.textcolor(4);
        cout << "\nLua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        Menu();
        break;
    }
}
int main()
{
    system("cls");
    dh.textcolor(12);
    cout << "\t\t\t\t_________________________________________________________________________\n";
    cout << "\t\t\t\t*\t--------*****===[DO AN LAP TRINH CO SO]===*****--------\t\t*\n";
    cout << "\t\t\t\t*\t   -------*****<DE TAI QUAN LY THU VIEN>*****-------\t\t*\n";
    cout << "\t\t\t\t*\t\t\t GV Huong dan: PHAN THANH TAO \t\t\t*\n";
    cout << "\t\t\t\t*\t\tSV Thuc hien\t\tLOP          NHOM    \t\t*\n";
    cout << "\t\t\t\t*\t\tDAO THUY TRANG\t\t20TCLC-Nhat2 2 \t\t\t*\n";
    cout << "\t\t\t\t*\t\tNGO TAN DUNG\t\t20TCLC-Nhat1 2 \t\t\t*\n";
    cout << "\t\t\t\t_________________________________________________________________________\n";
    getch();
    system("cls");
    Menu();
    return 0;
}