/*
weak_ptr:
    - It doesn't increments reference count
    - It cannot be used to read and write data
    - It doesn't have any get() function to get the RAW pointer
    - It converts to shared_ptr using lock()
    - It is mainly used to break reference cycle in cases two objects have shared pointers to each other, 
       or when we need a non owning reference to an object that is managed by a shared_ptr
*/


#include<iostream>
#include<memory>
class Person{
    public:
        Person() = default;
        Person(std::string mName) : name(mName){};
        ~Person(){
            std::cout<<name<<" destroyed\n";
        };

        // Member Function
        // void setFriend(std::shared_ptr<Person> p){
        void setFriend(std::shared_ptr<Person> p){
            m_friend = p;
        }
    private:
        std::string name {"Unknown"};

        // std::shared_ptr<Person> m_friend;
        
        /*
        It will create a cyclic Dependency.
        P1 is refering to P2 as friend and reference count 1;
        P2 is refering to P1 as friend and reference count 1;

        now when compiler will try to deallocate p1
            - It will not be able to deallocate them as p1 is still refering to p2
            - and when it will go for p2 it will still not be able to deallocate that because still p2 is referring to p1
            - so it will create a cyclic dependency .
            - To eliminate that we use 'weak_ptr' as it won't increment reference count and compiler can deallocate them.
        */

       std::weak_ptr<Person> m_friend;
};

using namespace std;
int main(){
    shared_ptr<int> ptr = make_shared<int>(5);

    weak_ptr<int> wptr = ptr;
    // cout<<*wptr<<endl;  // Error

    shared_ptr<int> ptr2 = wptr.lock(); //  Converts weak_ptr to shared_ptr.
    cout<<*ptr2<<endl;

    ////////////////////////////////////////////////////////
    shared_ptr<Person> p1 = make_shared<Person>("Alex");
    shared_ptr<Person> p2 = make_shared<Person>("Bob");

    p1->setFriend(p2);
    p2->setFriend(p1);

    return 0;
}