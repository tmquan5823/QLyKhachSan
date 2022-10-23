#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        ~Date();
        int getDay();
        int getMonth();
        int getYear();
        friend istream& operator>>(istream &i, Date&);
        friend ostream& operator<<(ostream &o, const Date&);
};