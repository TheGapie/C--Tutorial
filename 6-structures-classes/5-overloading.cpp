/*
Function Overloading :
    - Function overloading is a type of static polymorphism in C++ where multiple function with 
       same name but different sets of parameters are defined in the same scope.
    
Operator Overloading :
    - It is also static polymorphism but here operators are overloaded rather than function
    - '::' , '.' , '.*' , '?' only these 4 operators cannot be overloaded
    
    # syntax
        retType operator[operator_symbol](args){
            // body
        }
*/
#include<iostream>
using namespace std;

class Complex{
    double real;
    double img;
    public:
        Complex(double real,double img) : real(real),img(img){}
        
        void display(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
        // Operator Overloading as Member Function
        Complex operator+(const Complex c1){
            return Complex(this->real+c1.real, this->img+c1.img);
        }
        Complex operator()(double real,double img){
            this->real = real;
            this->img = img;
            return *this;
        }

        // Operator Overloading as Non-Member funtion using friend function
        friend Complex operator-(const Complex c1, const Complex c2);
        friend Complex operator++(Complex c1);    //  prefix
        friend Complex operator++(Complex c1,int); // postfix
        friend Complex operator--(Complex c1);
        friend Complex operator--(Complex c1,int);
        
        friend ostream& operator<<(ostream& os,const Complex &c1);
        friend istream& operator>>(istream& is,Complex &c1);

    
};

Complex operator-(const Complex c1, const Complex c2){
    return Complex(c1.real-c2.real , c1.img-c2.img);
}

Complex operator++(Complex c1){
    c1.real++;
    c1.img++;
    return c1;
}

Complex operator++(Complex c1,int x){
    c1.real++;
    c1.img++;
    return c1;
}

Complex operator--(Complex c1){
    c1.real--;
    c1.img--;
    return c1;
}

Complex operator--(Complex c1,int x){
    c1.real--;
    c1.img--;
    return c1;
}

ostream& operator<<(ostream& os, const Complex& c){
    os<<c.real<<" + "<<c.img<<"i"<<endl;
    return os;
}
istream& operator>>(istream& is,Complex &c){
    cout<<"Enter real : ";
    is>>c.real;
    cout<<"Enter Imaginary :";
    is>>c.img;
    return is;
}

int main(){
    Complex c1(5,6) , c2(3,4);
    Complex res = c1+c2;
    res.display();
    res = c1-c2;
    res.display();
    c1(4,9);
    c1.display();
    cin >> c2;
    cout<< (c1+c2);

    return 0;
}