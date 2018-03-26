#include<iostream>
using namespace std;
class Student{
    private:
        char *id;
        float golch;
        static int s;
    public:
        unsigned int level;
        char *name;
        Student();
        Student(char *, char *, int , float );
        Student(Student &);//хуулагч байгуулагч
        void set_student(char *, char *, int , float );
        void copy(Student &);// хуулах үйлдлийг хийх функц
        char* get_name();//оюутны нэр буцаах функц
        char* get_id();
        int get_level();
        float get_golch();
        void show_student();
        bool greatThan(Student &);
        bool lessThan(Student &);
        bool isEqual(Student &);
        bool before(Student &);
        bool after(Student &);
        void update(Student &a);//2 оюутны байр солих функц
        //~Student();
       static void get_sum();//статик гишүүн өгөгдлийн боловсруулах функц
};




