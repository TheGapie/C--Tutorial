/*
To create a custom exception class in C++ we need to derive from 'std::exception' class or it's derived class like
'std::runtime_error' or 'std::logic_error'. Here is an example
 */

#include<stdexcept>
#include<iostream>
using namespace std;

class CustomException : public std::runtime_error{
    public:
        CustomException(const std::string &ex) : std::runtime_error(ex) {}
};

void func(int c){
    if(c == 0)
        throw CustomException("/ by Zero");
    int x = 5/c;
}

int main(){
    try{
        func(0);
    }
    catch(const CustomException ex){
        cout<<ex.what()<<endl;
    }
    return 0;
}