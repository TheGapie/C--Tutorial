/*
Errors : 
    - Errors in C++ typically refers to conditions that are not part of the normal program execution
       and may lead to the termination of the program. e.g. division by zero, invalid memory access, or 
       other critical issues that can make it unsafe to continue the program execution.
    - Errors must not be caught
    - They cannot be recovered once caught

Exception:
    - Exception is an unexpected problem that arises during the exectution of the program and the 
       program suddenly terminates with some errors.
    - Exception are those condition at runtime that the application might want to catch
    - Exceptions are recoverable.
        
        # Synchronous Exception 
            - Exceptions when something goes wrong for some mistake like wrong input or when the program 
               is not equipped to work with current data.
            
        # Asynchronous Exception
            - Exceptions that are beyond control of the program's logic, such as disk failure, keyboard interrupt etc.


try:
    - In C++, 'try' block contains the code segment that might throw an exception.
    - there can be nested try catch block
    - try block without catch or finally block will lead to compilation error. The try block must be followed 
       by either one catch or finally block

    # syntax
        try{
            ///
                !!Exception occured
            ///
        }

catch:
    - The catch represents a block of code that is executed after a try block throws an exception.
    - there can be multiple catch block after a try block to serve multiple type of exception
    
    # syntax
        // normal catch block
        
        catch(ExceptionType ex){
            //
        }

        // catch-all-exceptions

        catch(...){

        }

throw:
    - throw is used to throw exception when a unexpected event occurs during the runtime
    - one can rethrow an exception from the catch block that it is been caught

    # syntax
        try{
            ////
                throw exception
            ////
        }
        catch(exception){
            ///
        }

finally:
    - finally is mainly is used for resource deallocation
    - finally is not in C++ but can be achieved by using destructors


*/
#include<iostream>
using namespace std;

void func(int c){
    if(c == 0)
        throw "Divide by 0";
    int x = 5/c;
}

int main(){
    try{
        func(0);
    }
    catch(const char* c){
        cout<<c<<endl;
        throw;
    }
    return 0;
}