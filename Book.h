#include <iostream>
#include <iomanip>
using namespace std;
class Book
{
private:
    string _MSS;
    string _Ten;
    string _Tacgia;
    string _Theloai;
    int _Sotrang;
    int _Soluong;

public:
    Book(string, string, string, string, int, int);
    Book();
    Book(const Book &);
    ~Book();
    void Show();
    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>(istream &, Book &);
    friend void DocThongtinsach(istream &, Book &);
    friend void XuatThongTinSach(ostream &, Book &);
    string MSS();
    string Ten();
    string Theloai();
    string Tacgia();
    int Soluong();
    void Soluong(int);
    bool operator==(const Book &);
};