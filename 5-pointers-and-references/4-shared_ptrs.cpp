/*
shared_ptr:
    - 'shared_ptr' allows to share ownership between different pointers of a dynamically allocated object.
    - The object will automatically destroyed only when the last shared_ptr that points to the memory, is distroyed.
    - When a shared_ptr refers to a data the reference count increases as more shared_ptr start pointing to the memory
    - once the reference count is 0, the data will be distroyed from memory
    - We cannot transfer ownership of a shared_ptr to a unique_ptr but vice-versa is True.

*/

#include<iostream>
#include<memory>
using namespace std;

int main(){
    shared_ptr<int> dptr1 {new int(5)};
    cout<<"Before : "<<*dptr1<<" Reference Count : "<<dptr1.use_count()<<endl;  // 1
    shared_ptr<int> dptr2 = dptr1;
    shared_ptr<int> dptr3 = dptr2;
    shared_ptr<int> dptr4 = make_shared<int>(9);
    *dptr3 = 7;
    cout<<"After : "<<*dptr1<<" Reference Count : "<<dptr1.use_count()<<endl;   // 3

    dptr3.reset();
    dptr2 = dptr4;
    cout<<"Reference Count dptr1: "<<dptr1.use_count()<<endl;   // 1
    cout<<"Reference Count dptr2: "<<dptr2.use_count()<<endl;   // 2
    cout<<"Reference Count dptr3: "<<dptr3.use_count()<<endl;   // 0
    
    // Array of shared_ptrs
    shared_ptr<int[]> ptrArr (new int[10]);

    // shared_ptr<int[]> ptrArr = make_shared<int[]>(10); // This will generate Compilation Error

    // OWNERSHIP
    unique_ptr<int> uptr1 = make_unique<int>(3);
    shared_ptr<int> dptr5 = move(uptr1);
    // unique_ptr<int> uptr2 = move(dptr5);  // Compilation Error, Bcz we can move ownership of a unique pointer 
                                             // to shared pointer but vice versa not true. As there can be multiple 
                                             // shared_ptrs pointing to same location

    /*
        Using unique_ptrs are very flexible as while returning from a function unique_ptrs can be assigned 
        to unique_ptrs implicitely and also can be assigned to shared_ptrs implicitely
    */
    return 0;
}