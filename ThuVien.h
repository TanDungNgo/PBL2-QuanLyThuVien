#ifndef THUVIEN_H
#define THUVIEN_H
#include "Book.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;

class ThuVien
{
private:
    Book *p;
    int _Length;

public:
    ThuVien();
    ~ThuVien();
    void Display();
    int Length();
    void InsertLast(Book);
    void Insert(Book, int);
    int IndexOf(string);
    void Remove(int);
    void FileOut();
    void FileIn();
    void Erase();
    //
    void Add();
    void DeleteID();
    void Update_SoLuong();
    void Sort();
    void Menu_DieuChinh();
    //
    void Search_TheLoai();
    void Search_TacGia();
    void Menu_TimSach();
    void XuatPhieu(ostream &, string &, int &);
    void Muonsach(string &);
    void XemPhieuMuon(string);
    void Trasach();
};
#endif