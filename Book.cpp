#include "Book.h"
Book::Book()
{
    this->_MSS = "";
    this->_Ten = "";
    this->_Tacgia = "";
    this->_Theloai = "";
    this->_Sotrang = 0;
    this->_Soluong = 0;
}
Book::Book(string ms, string n, string a, string c, int p, int s)
    : _MSS(ms), _Ten(n), _Tacgia(a), _Theloai(c), _Sotrang(p), _Soluong(s)
{
}
Book::Book(const Book &b)
{
    this->_MSS = b._MSS;
    this->_Ten = b._Ten;
    this->_Tacgia = b._Tacgia;
    this->_Theloai = b._Theloai;
    this->_Sotrang = b._Sotrang;
    this->_Soluong = b._Soluong;
}
Book::~Book()
{
}
string Book::MSS()
{
    return this->_MSS;
}
string Book::Ten()
{
    return this->_Ten;
}
string Book::Theloai()
{
    return this->_Theloai;
}
string Book::Tacgia()
{
    return this->_Tacgia;
}
int Book::Soluong()
{
    return this->_Soluong;
}
void Book::Soluong(int value)
{
    this->_Soluong = value;
}
void Book::Show()
{
    cout << setw(10) << left << this->_MSS;
    cout << setw(30) << left << this->_Ten;
    cout << setw(30) << left << this->_Tacgia;
    cout << setw(23) << left << this->_Theloai;
    cout << setw(16) << left << this->_Sotrang;
    cout << setw(16) << left << this->_Soluong << endl;
}
ostream &operator<<(ostream &o, const Book &b)
{
    // o << "MSS: " << b._MSS << ", "
    //   << "Ten sach: " << b._Ten << ", "
    //   << "Tac gia: " << b._Tacgia << ", "
    //   << "The loai: " << b._Theloai << ", "
    //   << "So trang:  " << b._Sotrang << ", "
    //   << " So luong: " << b._Soluong << endl;
    o << setw(10) << left << b._MSS;
    o << setw(30) << left << b._Ten;
    o << setw(30) << left << b._Tacgia;
    o << setw(23) << left << b._Theloai;
    o << setw(16) << left << b._Sotrang;
    o << setw(16) << left << b._Soluong << endl;
    return o;
}
istream &operator>>(istream &in, Book &b)
{
    cout << "MSS: ";
    in.ignore();
    getline(in, b._MSS);
    cout << "Ten sach: ";
    getline(in, b._Ten);
    cout << "Tac gia: ";
    getline(in, b._Tacgia);
    cout << "The loai: ";
    getline(in, b._Theloai);
    cout << "So trang: ";
    in >> b._Sotrang;
    cout << "So luong: ";
    in >> b._Soluong;
    return in;
}
bool Book::operator==(const Book &b)
{
    return (this->_Ten == b._Ten && this->_Tacgia == b._Tacgia);
}
void DocThongtinsach(istream &filein, Book &b)
{
    getline(filein, b._MSS);
    getline(filein, b._Ten);
    getline(filein, b._Tacgia);
    getline(filein, b._Theloai);
    filein >> b._Sotrang;
    filein.ignore();
    filein >> b._Soluong;
    filein.ignore();
}
void XuatThongTinSach(ostream &fileout, Book &b)
{
    fileout << b._MSS << endl;
    fileout << b._Ten << endl;
    fileout << b._Tacgia << endl;
    fileout << b._Theloai << endl;
    fileout << b._Sotrang << endl;
    fileout << b._Soluong;
}