#include<iostream>  //      #include<filename> includes the contents of filename in the source code
#include<math.h>
#define PI 3.14     //      used to create MACRO or symbolic constraints

#define square(x) x*x   //  can also be used like functions but does'nt work like function rather 
                        //  it replaces the macro keyword with the expression

#ifdef square                       //  #ifdef, #ifndef, #else, #endif -> used for conditional compliation
    #define CUBE(x) x*x*x           //  #if, #elif, #else, #endif -> also used for conditional computation

#else
    #define ROOT(sq) sqrt(x,2);     // will not work as square is DEFINED
#endif

#undef PI        //  it is used to undefine previously defined macro

#ifndef PI
    #warning Warining!! PI is not defined   //  It will only genrate a warning but will compile
#endif

#ifndef PI
    // #error PI is not defined         // It will generate an error and will show a compilation error
#endif

int main(){
    std::cout<<CUBE(5)<<"\n";
    return 0;
}
