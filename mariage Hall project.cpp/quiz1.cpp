// Write a program in which you need to write two functions, find_largest() and Check_Prime(). 
// Pass three integers to find_largest() function. Function will return the largest number. 
// Then pass the returned number to Check_Prime() function. Function will check whether the number is prime or not. 


#include <iostream>
using namespace std;
int find_largest(int num1,int num2,int num3){
    if (num1>num2 && num1>num3){
        return num1;
    }else if (num2>num1 && num2>num3){
        return num2;
    }
    else{
        return num3;
    }
}

int check_Prime(int nbr ){
    for(int i = 2 ;i<nbr;i++ ){
        if(nbr%i==0){
            cout<<i<<"is prime";
            break;
        }else{
            cout<<"is not prime";
        }
    }
}
int main(){
int n = 4;
int n2 = 9;
int n3 = 3;

int lagestNbr = find_largest(n,n2,n3);
cout<<lagestNbr;


cout<< check_Prime(lagestNbr);




}
