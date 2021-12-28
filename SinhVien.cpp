#include "SinhVien.h"
#include "Dohoa.h"
Dohoa dhsv;
SinhVien::SinhVien(string MSSV, string pass)
    : _MSSV(MSSV), _pass(pass)
{
}
SinhVien::~SinhVien()
{
}
string SinhVien::MSSV()
{
    return this->_MSSV;
}
void SinhVien::DangNhap()
{
    system("cls");
    string Username, Password;
    ifstream FileSV;
    FileSV.open("pass_sv.txt");
    dhsv.textcolor(2);
    cout << "\n\t\t\t----SINH VIEN DANG NHAP----" << endl;
    dhsv.textcolor(13);
    printf("\t%c", 16);
    cout << "Ten dang nhap: ";
    cin >> this->_MSSV;
    printf("\t%c", 16);
    cout << "Mat khau: ";
    cin >> this->_pass;
    bool found = false;
    string line = " ";
    while (getline(FileSV, line))
    {
        stringstream in(line);
        in >> Username >> Password;
        if (this->_MSSV == Username && this->_pass == Password)
        {
            found = true;
            Menu();
            break;
        }
    }
    if (!found)
    {
        dhsv.textcolor(4);
        cout << "\n\tTen dang nhap hoac mat khau khong chinh xac" << endl;
        getch();
        DangNhap();
    }
    FileSV.close();
}
void SinhVien::DangXuat()
{
    system("cls");
    dhsv.textcolor(2);
    cout << "\t\t\t----SINH VIEN DANG XUAT----" << endl;
    cout << "\t\t\tBan chac chan muon dang xuat? " << endl;
    cout << "\t\t\t1. Co" << endl;
    cout << "\t\t\t2. Khong" << endl;
    dhsv.textcolor(5);
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
        Menu();
        break;
    }
    default:
    {
        dhsv.textcolor(4);
        cout << "Lua chon khong hop le. Hay nhap lai...";
        getch();
        DangXuat();
    }
    }
}
void SinhVien::Back()
{
    char c;
    dhsv.textcolor(2);
    printf("\n\t\t%c", 16);
    cout << "Ban muon lam gi?";
    cout << "\n\t\t1.Quay lai menu sv";
    cout << "\n\t\t2.Dong ung dung";
    dhsv.textcolor(5);
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
        dhsv.textcolor(4);
        cout << "\nHay nhap lua chon dung!";
        getch();
        system("cls");
        Back();
        break;
    }
}
void SinhVien::ThayDoiMatKhau()
{
    system("cls");
    string mk_hientai, mk_moi, mk_nhaplai, _Password, _Username, user[100], pass[100];
    int n = 0;
    dhsv.textcolor(2);
    cout << "\n\t\t\t----THAY DOI MAT KHAU SINH VIEN----" << endl;
    dhsv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap mat khau hien tai: ";
    cin >> mk_hientai;
    if (mk_hientai == this->_pass)
    {
        dhsv.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Nhap mat khau moi: ";
        cin >> mk_moi;
        printf("\n\t%c", 16);
        cout << "Nhap lai mat khau moi: ";
        cin >> mk_nhaplai;
        if (mk_moi == mk_nhaplai)
        {
            ifstream in("pass_sv.txt");
            while (in >> _Username >> _Password)
            {
                if (_Username == this->_MSSV)
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
            ofstream out("pass_sv.txt", ios::out);
            for (int i = 0; i < n; i++)
            {
                out << user[i] << " " << pass[i] << endl;
            }
            out.close();
            dhsv.textcolor(7);
            cout << "\nThay doi mat khau thanh cong! Moi ban dang nhap lai";
            getch();
        }
        else
        {
            dhsv.textcolor(4);
            cout << "\nMat khau nhap lai khong dung. Hay nhap lai...";
            getch();
            system("cls");
            ThayDoiMatKhau();
        }
    }
    else
    {
        dhsv.textcolor(4);
        cout << "\nMat khau hien tai khong dung. Hay nhap lai...";
        getch();
        system("cls");
        ThayDoiMatKhau();
    }
}
void SinhVien::DangKy()
{
    system("cls");
    string MSSV, pass, pass1;
    dhsv.textcolor(2);
    cout << "\n\t\t\t----DANG KY TAI KHOAN SINH VIEN----" << endl;
    dhsv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap MSSV: ";
    fflush(stdin);
    getline(cin, MSSV);
    dhsv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap mat khau: ";
    fflush(stdin);
    getline(cin, pass);
    if (pass.size() > 15)
    {
        dhsv.textcolor(4);
        cout << "Do dai mat khau phai it hon 15 ki tu";
        getch();
        DangKy();
    }
    else
    {
        dhsv.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Nhap lai mat khau: ";
        fflush(stdin);
        getline(cin, pass1);
        if (pass == pass1)
        {
            dhsv.textcolor(7);
            cout << "Dang ky thanh cong";
            getch();
            fstream fileout;
            fileout.open("pass_sv.txt", ios::app);
            fileout << MSSV << " " << pass << endl;
        }
        else
        {
            dhsv.textcolor(4);
            cout << "Mat khau nhap lai khong trung khop" << endl;
            getch();
            DangKy();
        }
    }
}
bool check = true;
void SinhVien::Menu()
{
    system("cls");
    char c;
    if (check == true)
        FileIn();
    check = false;
    dhsv.textcolor(2);
    cout << "\n\t\t\t=====================> MENU SV <====================";
    cout << "\n\t\t\t|| 1. Xem sach                                    ||";
    cout << "\n\t\t\t|| 2. Tim sach                                    ||";
    cout << "\n\t\t\t|| 3. Muon sach                                   ||";
    cout << "\n\t\t\t|| 4. Thay doi mat khau                           ||";
    cout << "\n\t\t\t|| 0. Dang xuat                                   ||";
    cout << "\n\t\t\t====================================================\n";
    dhsv.textcolor(5);
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
        Muonsach(this->_MSSV);
        Back();
        break;
    }
    case '4':
    {
        ThayDoiMatKhau();
        break;
    }
    case '0':
    {
        check = true;
        Erase();
        DangXuat();
        break;
    }
    default:
    {
        dhsv.textcolor(4);
        cout << "Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        Menu();
        break;
    }
    }
}
