/*
unique_ptr:

    int main(){
        Dog* dog1 = new Dog("Dog 1");  // this statement used to allocate memory in heapspace.
                                       // But after execution it doesn't diallocate memory by default
                                       // we have to manually deallocate by using 'delete' operator
                                       // This problem can lead to severe memory lekeage and cause memory issue
    }

    We can allocate memory efficiently by using smart pointers like unique_ptr, shared_ptr, weak_ptr etc.
    In this section we will talk about only unique_ptrs.

    - unique_ptr is a template class that manages single object or arrays.
    - unique_ptr works on the concept of 'exclusive ownership' meaning 
       only one unique_ptr is allowed to own a single object at a time
    - This ownership can be moved or transferred but cannot be shared or copied.
    - This concept helps to prevent issues like dangling pointers, reduce memory leaks 
       and eliminates the need of manual memory management
    - When the unique_ptr goes out of scope it automatically deallocates memory that it owns.
*/


#include "Dog.h"
#include<iostream>
#include<memory>


using namespace std;

int main(){
    /// INITIALIZATION
    Dog* dog1 = new Dog("Dog 1");
    std::unique_ptr<Dog> dptr1{dog1};
    dog1 = NULL;

    
    int* a = new int(5);
    std::unique_ptr<int> nptr1{a};
    cout<<"RAW pointer of Dog1 : "<<dptr1.get()<<endl; 
    

    std::unique_ptr<Dog> dptr2{new Dog("Dog 2")};
    std::unique_ptr<int> nptr2 {new int(6)};
    
    std::unique_ptr<Dog> dptr3{nullptr};

    std::unique_ptr<Dog> dptr4 = make_unique<Dog>("Dog 4");
    std::unique_ptr<int> nptr4 = make_unique<int>(67);

    //  Array Initialization
    {
        auto dogArr = std::unique_ptr<Dog[]> {new Dog[3]{Dog("Dog 5"),Dog("Dog 6"),Dog("Dog 7")}};
        auto dogArr1 = std::make_unique<Dog[]>(3);
        // auto dogArr = std::make_unique<Dog[]>(3) {new Dog[3]{Dog("Dog 5"),Dog("Dog 6"),Dog("Dog 7")}}; -> // Won't work // Compiler error

        for(int i=0;i<3;i++){
            dogArr[i].display();
        }
    }

    /// OWNERSHIP

    /*
        ERROR

        std::unique_ptr<Dog> dptr5 = dptr1;
        std::unique_ptr<Dog> dptr6 = dptr2;
    */

    std::unique_ptr<Dog> dptr5 {move(dptr1)};
    std::unique_ptr<Dog> dptr6 = move(dptr2);
    cout<<"Dog1 : "<<(dptr1?"not null":"null")<<"\n";
    cout<<"Dog2 : "<<(dptr2?"not null":"null")<<"\n";

    return 0;
}