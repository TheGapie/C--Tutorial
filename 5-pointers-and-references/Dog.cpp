#include "Dog.h"
#include<iostream>

Dog::Dog(std::string dname) : name(dname){
    std::cout<<"Constructor for dog : "<<name<<" called\n";
}

Dog::~Dog(){
    std::cout<<"Destructor for dog : "<<name<<" called\n";
}