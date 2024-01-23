#include<iostream> 
using namespace std;

// declaring variable length parameter list in c++

void func(){        //  This is a base case for recursive call of func()
    cout<<endl;
}


template<typename T, typename... Args>
void func(T first, Args... args){       // This is recursive function for executing every parameter at a time
    cout<<first<<" ";
    func(args...);
}

// void func(...)       -> Illegal

int main(){
    func(12,"Hello",5.6,'c');
    return 0;
}