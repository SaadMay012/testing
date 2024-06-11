// Write a program in which you need to define a class item. 
// This class can instantiate three different kind of items. 
// Each item has three properties i) Name ii) price iii) quantity.
//  First type of item has all the values default (i-e Name="Candy", price= 20, quantity=200). 
//  Second item has name as default value and other two values will be provided by user. 
//  In third type of item, each value should be provided by user. 
//  Make appropriate constructor for each type of item and instantiate one item for each type and show details of each item. 
//  You can declare and define extra functions as required


#include<iostream>
using namespace std;

class item {
    string name;
    int price;
    int quntatiy ;
public:
    item():name("canday"),price(20),quntatiy(200){};
    item (int p,int q):name("canday"),price(p),quntatiy(q){};
    item(string n ,int p,int q):name(n),price(p),quntatiy(q){};

    void getIfo(){
        cout<<"name : "<<name<<endl;
        cout<<"price : "<<price<<endl;
        cout<<"quntaty : "<<quntatiy<<endl;
}

};

int main(){
    item item1;
    item1.getIfo();

    item item2(30,300);
    item2.getIfo();

    item item3("buntay",40,400);
    item3.getIfo();
}