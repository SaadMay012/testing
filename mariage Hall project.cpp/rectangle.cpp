// Implement a base class called Shape with a virtual function area(). 
// Then, derive two classes Circle and Rectangle from Shape. Override the area()
//  function in both derived classes to calculate the area of a circle and a rectangle, respectively. 
//  Finally, write a main function to create instances of Çircle and Rectangle, and use a pointer to the base class Shape to call the area()
//   function for each object, demonstrating polymorphism.


#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area()= 0;
};
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area(){
        return 3.14 * radius * radius;
    }
    void getInfo(){
        cout<<area();
    }
};
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() {
        return width * height;
    }

    void getInfo(){
        cout<<area();
    }
};

int main() {
   
    Circle c(5.0);
    cout<<c.area();
     cout<<endl;
    Rectangle r(4.0,6.0);
    cout<<r.area();
}