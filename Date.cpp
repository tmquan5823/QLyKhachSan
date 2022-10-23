#include"Date.h"
#include<string>

Date::Date(int d, int m, int y){
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::Date(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::~Date(){}

int Date::getDay(){
    return this->day;
}

int Date::getMonth(){
    return this->month;
}

int Date::getYear(){
    return this->year;
}

istream& operator>>(istream &i, Date &date){
    i>>date.day>>date.month>>date.year;
    return i;
}

ostream& operator<<(ostream &o, const Date &date){
    string d = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    cout<<d;
    return o;
}
