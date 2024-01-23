/* 
namespaces :
    - In C++ Namespaces are a way to organize and encapsulate identifiers such as variable, functions, classes into a named scope.
    - Their purpose is to localize the names of identifiers and avoid naming conflicts.
*/

#include<iostream>
#include<math.h>
using namespace std;       

// Basic Namespace
namespace myNamespce{
    template<typename T>
    T abs(T x){
        if(x<0)
            return -x;
        return x;
    }
}

// Nested Namespace
namespace outer{
    namespace inner{
        template<typename T>
        T abs(T x){
            if(x<0)
                return -x;
            return x;
        }
    }
}

// Anonymus Namespace -> It allows to create identifiers that are known only within the scope of a single file.
namespace{
    int staticVariable = 0; // works same as (static int var = 0) 
}

int main(){
    cout<<"From math.h : "<<abs(-5)<<"\n";
    cout<<"From myNamespace : "<<myNamespce::abs(-5.6)<<"\n";
    cout<<"From outer::inner namespace : "<<outer::inner::abs(-5.6)<<"\n";
    cout<<"Static Variable : "<<staticVariable<<endl;
    return 0;
}