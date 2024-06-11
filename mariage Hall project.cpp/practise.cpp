#include <iostream>
using namespace std;
class    employee {
public:
virtual int calculate_salary() = 0;
} ;

class salaried_employee: public employee{
    private:
        int basic_salary ;
        int Allowances;
public:
 salaried_employee(int basic,int allowances):basic_salary(basic),Allowances(allowances){}

int  calculate_salary(){
return basic_salary + Allowances;

}

};
class  hourly_employee:public employee{
int rate_H;
int inMonth;
int rate_per_hour;
public:
hourly_employee(int rate_h,int im):rate_H(rate_h),inMonth(im){}

int  calculate_salary(){
    return rate_H*inMonth;
}
};
int main(){
salaried_employee eg(32,21);
 cout<<"salaried_employee is: "<<eg.calculate_salary()<<endl;

hourly_employee He(321,33);
cout<<"hourly_employee is :"<<He.calculate_salary();
}