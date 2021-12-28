#include "ThuVien.h"
#include <time.h>
#include "Dohoa.h"
Dohoa dhtv;
int ThuVien::Length()
{
    return this->_Length;
}
ThuVien::ThuVien()
{
    this->p = nullptr;
    this->_Length = 0;
}
ThuVien::~ThuVien()
{
    delete[] this->p;
}
void ThuVien::Erase()
{
    delete[] this->p;
    this->p = nullptr;
    this->_Length = 0;
}
void ThuVien::Display()
{
    dhtv.textcolor(2);
    cout << "\n\t\t\t----XEM SACH----" << endl;
    dhtv.textcolor(8);
    dhtv.printline(117, '=');
    dhtv.textcolor(6);
    cout << setw(10) << left << "MSS";
    cout << setw(30) << left << "Ten sach";
    cout << setw(30) << left << "Ten tac gia";
    cout << setw(23) << left << "The loai";
    cout << setw(16) << left << "So trang";
    cout << setw(16) << left << "So luong";
    dhtv.textcolor(8);
    dhtv.printline(117, '=');
    dhtv.textcolor(7);
    for (int i = 0; i < this->_Length; i++)
    {
        (*(this->p + i)).Show();
    }
}
void ThuVien::InsertLast(Book b)
{
    if (this->_Length == 0)
    {
        this->p = new Book[this->_Length + 1];
        *(this->p + this->_Length) = b;
    }
    else
    {
        Book *temp = new Book[this->_Length];
        for (int i = 0; i < this->_Length; i++)
            *(temp + i) = *(this->p + i);
        delete[] this->p;
        this->p = new Book[this->_Length + 1];
        for (int i = 0; i < this->_Length; i++)
            *(this->p + i) = *(temp + i);
        *(this->p + this->_Length) = b;
    }
    this->_Length++;
}
void ThuVien::Insert(Book b, int index)
{
    if (index <= this->_Length && index >= 0)
    {
        Book *temp = new Book[this->_Length + 1];
        for (int i = 0; i < index - 1; i++)
            *(temp + i) = *(this->p + i);
        *(temp + index - 1) = b;
        for (int i = index; i < this->_Length + 1; i++)
            *(temp + i) = *(this->p + i - 1);
        delete[] this->p;
        this->p = new Book[this->_Length + 1];
        for (int i = 0; i < this->_Length + 1; i++)
            *(this->p + i) = *(temp + i);
        this->_Length++;
    }
}
void ThuVien::Remove(int index)
{
    if (index >= 0)
    {
        if (this->_Length == 1)
        {
            delete[] this->p;
        }
        else
        {
            Book *temp = new Book[this->_Length];
            for (int i = 0; i < this->_Length; i++)
            {
                *(temp + i) = *(this->p + i);
            }
            delete[] this->p;
            this->p = new Book[this->_Length - 1];
            for (int i = 0; i < this->_Length - 1; i++)
            {
                if (i < index)
                {
                    *(this->p + i) = *(temp + i);
                }
                else
                {
                    *(this->p + i) = *(temp + i + 1);
                }
            }
        }
        this->_Length--;
    }
}
int ThuVien::IndexOf(string str)
{
    int index = -1;
    for (int i = 0; i < this->_Length; i++)
    {
        if ((this->p + i)->MSS() == str)
        {
            index = i;
            break;
        }
    }
    return index;
}

void ThuVien::Search_TheLoai()
{
    string t;
    int count = 0;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----TIM SACH THEO THE LOAI----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap the loai sach: ";
    fflush(stdin);
    getline(cin, t);
    dhtv.textcolor(7);
    cout << "Tat ca cac sach the loai " << t << endl;
    for (int i = 0; i < this->_Length; i++)
    {
        if (t == (this->p + i)->Theloai())
        {
            if (count == 0)
            {
                dhtv.textcolor(8);
                dhtv.printline(117, '=');
                dhtv.textcolor(6);
                cout << setw(10) << left << "MSS";
                cout << setw(30) << left << "Ten sach";
                cout << setw(30) << left << "Ten tac gia";
                cout << setw(23) << left << "The loai";
                cout << setw(16) << left << "So trang";
                cout << setw(16) << left << "So luong";
                dhtv.textcolor(8);
                dhtv.printline(117, '=');
            }
            dhtv.textcolor(7);
            (*(this->p + i)).Show();
            count++;
        }
    }
    if (count == 0)
    {
        dhtv.textcolor(7);
        cout << "Khong co sach thuoc the loai " << t << endl;
    }
}
void ThuVien::Search_TacGia()
{
    string t;
    int count = 0;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----TIM SACH THEO TEN TAC GIA----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap ten tac gia: ";
    fflush(stdin);
    getline(cin, t);
    dhtv.textcolor(7);
    cout << "Tat ca cac sach cua tac gia " << t << endl;
    for (int i = 0; i < this->_Length; i++)
    {
        if (t == (this->p + i)->Tacgia())
        {
            if (count == 0)
            {
                dhtv.textcolor(8);
                dhtv.printline(117, '=');
                dhtv.textcolor(6);
                cout << setw(10) << left << "MSS";
                cout << setw(30) << left << "Ten sach";
                cout << setw(30) << left << "Ten tac gia";
                cout << setw(23) << left << "The loai";
                cout << setw(16) << left << "So trang";
                cout << setw(16) << left << "So luong";
                dhtv.textcolor(8);
                dhtv.printline(117, '=');
            }
            dhtv.textcolor(7);
            (*(this->p + i)).Show();
            count++;
        }
    }
    if (count == 0)
    {
        dhtv.textcolor(7);
        cout << "Khong co sach cua tac gia " << t << endl;
    }
}
void ThuVien::FileOut()
{
    fstream fileout;
    fileout.open("BookList.txt", ios::out);
    for (int i = 0; i < this->_Length; i++)
    {
        if (i != 0)
        {
            fileout << endl
                    << endl;
        }
        XuatThongTinSach(fileout, *(this->p + i));
    }
    fileout.close();
}
void ThuVien::FileIn()
{
    ifstream filein;
    filein.open("BookList.txt", ios::in);
    if (filein.fail())
    {
        cout << "Loi doc file";
        system("exit");
    }
    while (!filein.eof())
    {
        Book b;
        DocThongtinsach(filein, b);
        InsertLast(b);
        filein.ignore();
    }
    filein.close();
}
void ThuVien::Add()
{
    int n;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----THEM SACH VAO THU VIEN----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap so luong quyen sach can them: ";
    cin >> n;
    Book *b = new Book[n];
    for (int i = 0; i < n; i++)
    {
        dhtv.textcolor(7);
        printf("\n\t%c", 16);
        cout << "Quyen thu " << i + 1 << endl;
        cin >> b[i];
        InsertLast(b[i]);
    }
    cout << "\t\tNhap xong " << endl;
    FileOut();
}
void ThuVien::DeleteID()
{
    string ms;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----XOA SACH----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap ma so sach can xoa: ";
    fflush(stdin);
    getline(cin, ms);
    int k = IndexOf(ms);
    Remove(k);
    dhtv.textcolor(7);
    cout << "Da xoa xong" << endl;
    FileOut();
}
void ThuVien::Update_SoLuong()
{
    string m;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----CAP NHAT SO LUONG SACH----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap ma so sach can cap nhat: ";
    fflush(stdin);
    getline(cin, m);
    int index = IndexOf(m);
    if (index >= 0)
    {
        int soluong;
        dhtv.textcolor(7);
        cout << "So luong hien tai cua sach la:" << (this->p + index)->Soluong();
        cout << "\nCap nhat lai so luong sach: ";
        cin >> soluong;
        (this->p + index)->Soluong(soluong);
        cout << "\nCap nhat thanh cong";
        FileOut();
    }
    else
    {
        dhtv.textcolor(4);
        cout << "\nMa so sach khong ton tai ";
    }
}
void ThuVien::Sort()
{
    Book temp;
    char a[100], b[100];
    for (int i = 0; i < this->_Length; i++)
    {
        for (int j = i + 1; j < this->_Length; j++)
        {
            if (strcmp(strcpy(a, (this->p + i)->Ten().c_str()), strcpy(b, (this->p + j)->Ten().c_str())) > 0)
            {
                temp = *(this->p + i);
                *(this->p + i) = *(this->p + j);
                *(this->p + j) = temp;
            }
        }
    }
    dhtv.textcolor(7);
    cout << "\n\tSap xep thanh cong" << endl;
}
void ThuVien::XuatPhieu(ostream &fileout, string &t, int &s)
{
    time_t now = time(0);
    char *dt = ctime(&now);
    fileout << "Ngay muon: " << dt;
    fileout << "Ten sach: " << endl;
    fileout << t << endl;
    fileout << "So luong: " << endl;
    fileout << s << endl;
}
void ThuVien::Muonsach(string &MSSV)
{
    system("cls");
    bool kt = false;
    int index = -1;
    string tensach[10];
    int k = 0;
    char c;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----MUON SACH----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap ten sach can muon: ";
    fflush(stdin);
    getline(cin, tensach[k]);
    for (int i = 0; i < this->_Length; i++)
    {
        if (tensach[k] == (this->p + i)->Ten())
        {
            kt = true;
            index = i;
            break;
        }
    }
    while (kt == false)
    {
        dhtv.textcolor(4);
        cout << "Khong ton tai sach trong thu vien " << endl;
        dhtv.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Ban co muon sach khac (y/n)" << endl;
        c = getch();
        switch (c)
        {
        case 'y':
            system("cls");
            Muonsach(MSSV);
            break;
        case 'n':
            system("cls");
            return;
        default:
            kt = false;
            dhtv.textcolor(4);
            cout << "\nLua chon khong hop le.";
            getch();
        }
    }
    if (index >= 0 && index <= this->_Length)
    {

        if ((this->p + index)->Soluong() == 0)
        {
            dhtv.textcolor(7);
            cout << "Da cho muon het sach " << endl;
        }
        else
        {
            int soluong;
            dhtv.textcolor(5);
            printf("\n\t%c", 16);
            cout << "Nhap so luong sach muon: ";
            cin >> soluong;
            if (soluong <= (this->p + index)->Soluong())
            {
                (this->p + index)->Soluong((this->p + index)->Soluong() - soluong);
                string temp = "PhieuMuon" + MSSV + ".txt";
                ofstream fileout(temp.c_str(), ios::app);
                XuatPhieu(fileout, tensach[k], soluong);
                dhtv.textcolor(7);
                cout << "\n\nMuon sach thanh cong" << endl;
                FileOut();
            }
            else
            {
                dhtv.textcolor(7);
                cout << "So luong sach hien tai chi con: " << (this->p + index)->Soluong() << endl;
            }
        }
    }
    do
    {
        dhtv.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Ban co muon tiep tuc muon sach (y/n)" << endl;
        c = getch();
        switch (c)
        {
        case 'y':
            system("cls");
            Muonsach(MSSV);
            break;
        case 'n':
            return;
        default:
            dhtv.textcolor(4);
            cout << "\nLua chon khong hop le.";
            kt = false;
            getch();
        }
    } while (kt == false);
}
void ThuVien::XemPhieuMuon(string mp)
{
    string temp = "PhieuMuon" + mp + ".txt";
    ifstream filein(temp.c_str(), ios::in);
    if (filein.fail())
    {
        dhtv.textcolor(4);
        cout << "Khong ton tai phieu muon!";
    }
    else
    {
        dhtv.textcolor(7);
        dhtv.printline(40, '_');
        cout << "MSSV:" << mp << endl;
        string line;
        while (getline(filein, line))
        {
            cout << line << endl;
        }
        dhtv.printline(40, '_');
    }
    filein.close();
}
void ThuVien::Trasach()
{
    system("cls");
    string mp;
    dhtv.textcolor(2);
    cout << "\n\t\t\t----TRA SACH----" << endl;
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap ma phieu:";
    fflush(stdin);
    getline(cin, mp);
    string temp = "PhieuMuon" + mp + ".txt";
    ifstream filein(temp.c_str(), ios::in);
    if (filein.fail())
    {
        dhtv.textcolor(4);
        cout << "Phieu muon khong ton tai! Hay nhap lai..." << endl;
        filein.close();
        getch();
        system("cls");
        Trasach();
    }
    XemPhieuMuon(mp);
    string ngaymuon[10], ten[10], s;
    int soluong[10], n = 0;
    while (!filein.eof())
    {
        getline(filein, ngaymuon[n]);
        getline(filein, s);
        getline(filein, ten[n]);
        getline(filein, s);
        filein >> soluong[n];
        filein.ignore();
        n++;
    }
    filein.close();
    getch();
    bool kt = true;
    do
    {
        char c;
        dhtv.textcolor(5);
        printf("\n\t%c", 16);
        cout << "Ban co chac chan muon tra sach? (y/n)" << endl;
        c = getch();
        switch (c)
        {
        case 'y':
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < this->_Length; j++)
                {
                    if (ten[i] == (this->p + j)->Ten())
                    {
                        (this->p + j)->Soluong((this->p + j)->Soluong() + soluong[i]);
                        break;
                    }
                }
            }
            remove(temp.c_str());
            dhtv.textcolor(7);
            cout << "\tTra sach thanh cong";
            FileOut();
            break;
        case 'n':
            cout << "Ket thuc tra sach!" << endl;
            return;
        default:
            dhtv.textcolor(4);
            cout << "\nLua chon khong hop le.";
            kt = false;
            getch();
        }
    } while (kt == false);
}
void ThuVien::Menu_TimSach()
{
    system("cls");
    dhtv.textcolor(2);
    cout << "\n\t\t\t\t----MENU TIM SACH----" << endl;
    cout << "\n\t\t\t====================================================";
    cout << "\n\t\t\t|| 1. Tim kiem sach theo the loai                 ||";
    cout << "\n\t\t\t|| 2. Tim kiem sach theo ten tac gia              ||";
    cout << "\n\t\t\t|| 0. Thoat                                       ||";
    cout << "\n\t\t\t====================================================\n";
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap su lua chon cua ban: ";
    char c;
    c = getch();
    switch (c)
    {
    case '1':
        system("cls");
        Search_TheLoai();
        getch();
        break;
    case '2':
        system("cls");
        Search_TacGia();
        getch();
        break;
    case '0':
        break;
    default:
        dhtv.textcolor(4);
        cout << "Lua chon khong hop le. Hay nhap lai...";
        Menu_TimSach();
        getch();
        system("cls");
        break;
    }
}
void ThuVien::Menu_DieuChinh()
{
    system("cls");
    dhtv.textcolor(2);
    cout << "\n\t\t\t\t----MENU DIEU CHINH----" << endl;
    cout << "\n\t\t\t====================================================";
    cout << "\n\t\t\t|| 1. Them sach vao thu vien                      ||";
    cout << "\n\t\t\t|| 2. Xoa sach khoi thu vien                      ||";
    cout << "\n\t\t\t|| 3. Cap nhat so luong sach                      ||";
    cout << "\n\t\t\t|| 4. Sap xep sach theo bang chu cai              ||";
    cout << "\n\t\t\t|| 0. Thoat                                       ||";
    cout << "\n\t\t\t====================================================\n";
    dhtv.textcolor(5);
    printf("\n\t%c", 16);
    cout << "Nhap su lua chon cua ban: ";
    char c;
    c = getch();
    switch (c)
    {
    case '1':
        system("cls");
        Add();
        getch();
        break;
    case '2':
        system("cls");
        DeleteID();
        Display();
        getch();
        break;
    case '3':
        system("cls");
        Update_SoLuong();
        Display();
        getch();
        break;
    case '4':
        system("cls");
        Sort();
        Display();
        getch();
        break;
    case '0':
        break;
    default:
        dhtv.textcolor(4);
        cout << "Lua chon khong hop le. Hay nhap lai...";
        Menu_TimSach();
        getch();
        system("cls");
        break;
    }
}
