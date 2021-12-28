#include "NguoiQuanLy.h"
#include "Dohoa.h"
Dohoa dhql;

NguoiQuanLy::NguoiQuanLy(string admin, string pass)
    : _admin(admin), _pass(pass)
{
}
NguoiQuanLy::~NguoiQuanLy()
{
}
void NguoiQuanLy::DangNhap()
{
    system("cls");
    string Username, Password;
    ifstream FileQL;
    FileQL.open("pass_ql.txt");
    dhql.textcolor(2);
    cout << "\n\t\t\t----QUAN LY DANG NHAP----" << endl;
    dhql.textcolor(13);
    printf("\t%c", 16);
    cout << "Ten dang nhap: ";
    cin >> this->_admin;
    printf("\t%c", 16);
    cout << "Mat khau: ";
    cin >> this->_pass;
    bool found = false;
    string line = " ";
    while (getline(FileQL, line))
    {
        stringstream in(line);
        in >> Username >> Password;
        if (this->_admin == Username && this->_pass == Password)
        {
            found = true;
            Menu();
            break;
        }
    }
    if (!found)
    {
        dhql.textcolor(4);
        cout << "\n\tTen dang nhap hoac mat khau khong chinh xac" << endl;
        getch();
        DangNhap();
    }
    FileQL.close();
}
void NguoiQuanLy::DangXuat()
{
    system("cls");
    dhql.textcolor(2);
    cout << "\n\t\t\t----QUAN LY DANG XUAT----" << endl;
    cout << "\t\t\tBan chac chan muon dang xuat? " << endl;
    cout << "\t\t\t1. Co" << endl;
    cout << "\t\t\t2. Khong" << endl;
    dhql.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap lua chon cua ban: ";
    char c;
    c = getch();
    switch (c)
    {
    case '1':
    {
        break;
    }
    case '2':
    {
        system("cls");
        Menu();
        break;
    }
    default:
    {
        dhql.textcolor(4);
        cout << "Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        DangXuat();
    }
    }
}
void NguoiQuanLy::Back()
{
    char c;
    dhql.textcolor(2);
    printf("\n\t\t%c", 16);
    cout << "Ban muon lam gi?";
    cout << "\n\t\t1.Quay lai menu ql ";
    cout << "\n\t\t2.Dong ung dung";
    dhql.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap lua chon cua ban: ";
    c = getch();
    switch (c)
    {
    case '1':
        system("cls");
        Menu();
        break;
    case '2':
        exit(0);
        break;
    default:
        cout << "\nHay nhap lua chon dung!";
        getch();
        system("cls");
        Back();
        break;
    }
}
void NguoiQuanLy::ThayDoiMatKhau()
{
    system("cls");
    string mk_hientai, mk_moi, mk_nhaplai, _Password, _Username, user[100], pass[100];
    int n = 0;
    dhql.textcolor(2);
    cout << "\n\t\t\t----THAY DOI MAT KHAU QUAN LY----\t" << endl;
    dhql.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap mat khau hien tai: ";
    cin >> mk_hientai;
    if (mk_hientai == this->_pass)
    {
        dhql.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Nhap mat khau moi: ";
        cin >> mk_moi;
        printf("\n\t%c", 16);
        cout << "Nhap lai mat khau moi: ";
        cin >> mk_nhaplai;
        if (mk_moi == mk_nhaplai)
        {
            ifstream in("pass_ql.txt");
            while (in >> _Username >> _Password)
            {
                if (_Username == this->_admin)
                {
                    user[n] = _Username;
                    pass[n] = mk_moi;
                    n++;
                }
                else
                {
                    user[n] = _Username;
                    pass[n] = _Password;
                    n++;
                }
            }
            in.close();
            ofstream out("pass_ql.txt", ios::out | ios::trunc);
            for (int i = 0; i < n; i++)
            {
                out << user[i] << " " << pass[i] << endl;
            }
            out.close();
            dhql.textcolor(7);
            cout << "\nThay doi mat khau thanh cong! Moi ban dang nhap lai";
            getch();
        }
        else
        {
            dhql.textcolor(4);
            cout << "\nMat khau nhap lai khong dung. Hay nhap lai...";
            getch();
            system("cls");
            ThayDoiMatKhau();
        }
    }
    else
    {
        dhql.textcolor(4);
        cout << "\nMat khau hien tai khong dung. Hay nhap lai...";
        getch();
        system("cls");
        ThayDoiMatKhau();
    }
}
bool checkql = true;
void NguoiQuanLy::Menu()
{
    system("cls");
    char c;
    if (checkql == true)
        FileIn();
    checkql = false;
    dhql.textcolor(2);
    cout << "\n\t\t\t=====================> MENU QL <====================";
    cout << "\n\t\t\t|| 1. Xem sach                                    ||";
    cout << "\n\t\t\t|| 2. Tim sach                                    ||";
    cout << "\n\t\t\t|| 3. Dieu chinh                                  ||";
    cout << "\n\t\t\t|| 4. Xem phieu muon                              ||";
    cout << "\n\t\t\t|| 5. Tra sach                                    ||";
    cout << "\n\t\t\t|| 6. Thay doi mat khau                           ||";
    cout << "\n\t\t\t|| 0. Dang xuat                                   ||";
    cout << "\n\t\t\t====================================================\n";
    dhql.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap su lua chon cua ban: ";
    c = getch();
    switch (c)
    {
    case '1':
    {
        system("cls");
        Display();
        getch();
        Back();
        break;
    }
    case '2':
    {
        Menu_TimSach();
        Back();
        break;
    }
    case '3':
    {
        Menu_DieuChinh();
        Back();
        break;
    }
    case '4':
    {
        system("cls");
        string mp;
        dhql.textcolor(2);
        cout << "\n\t\t\t----XEM PHIEU MUON----\t" << endl;
        dhql.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Nhap ma phieu:";
        fflush(stdin);
        getline(cin, mp);
        XemPhieuMuon(mp);
        getch();
        Back();
        break;
    }
    case '5':
    {
        Trasach();
        getch();
        Back();
        break;
    }
    case '6':
    {
        ThayDoiMatKhau();
        break;
    }
    case '0':
    {
        checkql = true;
        Erase();
        DangXuat();
        break;
    }
    default:
    {
        dhql.textcolor(4);
        cout << "Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        Menu();
        break;
    }
    }
}
