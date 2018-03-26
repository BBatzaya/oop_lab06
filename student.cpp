#include"student.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int Student::s=0;//статик гишүүн өгөгдөлд утга оноох ёстой.
//статик гишүүн өгөгдлийн утгыг хэвлэх функц
void Student::get_sum()
{
    cout << s << "\n";
}
//анхдагч байгуулагч
Student::Student()
{
    name = new char[17];
    strcpy(name , " ");
    id = new char[15];
    strcpy(id , " ");
    level = 1;
    golch = 0;
}
//гараас оруулж байгаа өгөгдлийг параметртэй байгуулагч ашиглан утга оноох функц
Student::Student(char *n, char *m, int x , float y)
{
    set_student(n, m, x, y);
}
void Student::set_student(char *n, char *m, int x, float y)
{
    this->name = new char[strlen(n)+1];
    strcpy(this->name, n);
    this->id = new char[strlen(m)+1];
    strcpy(this->id, m);
    this->level = x;
    this->golch = y;
    s++;
}
//хуулагч байгуулагч функц
Student::Student(Student &a)
{
    this->copy(a);
}
//хуулагч функц
void Student::copy(Student &a)
{
    this->name = new char[strlen(a.get_name())+1];
    strcpy(this->name ,a.get_name());
    this->id = new char[strlen(a.get_id())+1];
    strcpy(id,a.get_id());
    this->level = a.get_level();
    this->golch = a.get_golch();
}
//Оюутны мэдээллийг хэвлэх функц
void Student::show_student()
{
    cout << setw(10) << this->name << setw(15) << this->id << setw(5) << this->level << setw(5) << this->golch << "\n";
}
//Оюутан классын гишүүн өгөгдөл тус бүрийг буцаах функцууд
char* Student::get_name()
{
    return name;
}
char* Student::get_id()
{
    return id;
}
int Student::get_level()
{
    return level;
}
float Student::get_golch()
{ 
    return golch;
}
//2 Оюутны нэр болон түвшинг харьцуулах функцууд
bool Student::greatThan(Student &a)
{
    if(this->level > a.get_level()) return true;
    else return false;
}
bool Student::lessThan(Student &a)
{
    return !greatThan(a);
}
bool Student::isEqual(Student &a)
{
        if(this->level == a.get_level()) return true;
        else return false;
}
bool Student::after(Student &a)
{
    if(strcmp(this->name,a.get_name()) >= 0) return true;
    else return false;
}
/*bool Student::before(Student &a)
{
    if(strcmp(this->name,a.get_name()) >= 0) return true;
    else return false;
}*/
//2 оюутны байр солих функц
void Student::update(Student &a)
{
    char change[20];
    strcpy(change,this->name);
    strcpy(this->name,a.name);
    strcpy(a.name,change);
    unsigned changee;
    changee = this->level;
    this->level = a.level;
    a.level = changee;
    char z[20];
    strcpy(z, this->id);
    strcpy(this->id, a.id);
    strcpy(a.id, z);
    float k;
    k= this->golch;
    this->golch = a.golch;
    a.golch = k;
}








