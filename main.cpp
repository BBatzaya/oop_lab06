#include<iostream>
#include "student.h"
using namespace std;
void head()
{
    cout << "1. Kurseer erembeleh" << "\n";
    cout << "2. Nerseer erembeleh" << "\n";
    cout << "3. Heden oyutatnii object vvssen baigaag harah" << "\n";
    cout << "4. Hevleh" << "\n";
    cout << "5. Garah" << "\n";
}
//Оюутнуудыг нэрсээр нь эрэмбэлэх функц
void sort_name(Student *a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            //2 Оюуты нэрсийг харьцуулхын тулд after гэсэн гишүүн функруу хандана.
            if(a[i].after(a[j]))
            {
                a[i].update(a[j]);
                /*Student a2;
                a2 = Student(a[i]);
                a[i].copy(a[j]);
                a[j].copy(a2);*/
            }
        }
    }
}
//Оюутнуудыг түвшингээр нь эрэмбэлэх функц
void sort_level(Student *a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            //2 Оюутны түвшинг харьцуулхын тулд greatThan гэсэн гишүүн функруу хандана.
            if(a[i].greatThan(a[j]))
            {
                a[i].update(a[j]);
                /*Student a2;
                a2 = Student(a[i]);
                a[i].copy(a[j]);
                a[j].copy(a2);*/
            }
            else if(a[i].isEqual(a[j]))
            {
                    a[i].update(a[j]);
                    /*Student a2;
                    a2 = Student(a[i]);
                    a[i].copy(a[j]);
                    a[j].copy(a2);*/
            }
        }
    }
}
int main()
{
    int i, n = 0;
    int level1;
    float golch1;
    char name1[17], id1[15];
    Student *a1;
    a1 = new Student[5];
    Student *a2;
    a2 = new Student[5];
    for(i = 0; i < 5; i++)
    {
        cout << "Name: ";   cin >> name1;
        cout << "ID: ";     cin >> id1;
        cout << "level: ";  cin >> level1;
        cout << "golch1: "; cin >> golch1;
        if(golch1 >= 0 && golch1 <= 4 && level1 > 0)
        {
            a1[i] = Student(name1, id1, level1, golch1);
        }
        else{
            cout << "golch esvel leveliin ugugdul buruu baina."<< endl << "Dahin oruulna uu?";
            i--;
        }
    }
    for(i = 0; i < 5; i++)
    {
        a2[i] = Student(a1[i]);
    }
    head();
    while(n != 5)
    {
        cout << "> "; cin >> n;
        if(n == 1)
            for(i = 0; i < 5; i++)
                sort_level(a1, 5);
        if(n == 2)
            for(i = 0; i < 5; i++)
                sort_name(a1, 5);
       if(n == 3)
           a1->get_sum();
        if(n == 4)
             for(i = 0; i < 5; i++)
                 a1[i].show_student();
    }
    for(i = 0; i < 5; i++)
        a2[i].show_student();
}
