/*
lambda function :
    - A lambda function also known as Anonymus function that provides a concise 
       way to declare a small inline function without a formal declaration of function

    - Lambda functions are especially useful when we need to pass a short piece of code 
       as an arguement to a function or use it locally

    # Syntax:
        [capture_list](parameter) -> return_type {
            function body
        };

        - capture_list : A list of variables from surrounding scope that the function needs to execute
        - parameter: The list of parameters just like regular functions
        - return_type(optional) : The type of value that the Lambda function will return;
        - function_body : The code that defines the opeartion of the lambda function
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

    int multi = 3;
    auto times = [multi](int x) -> int{
        return x * multi;
    };

    cout<<times(5)<<endl;   // 15


    vector<int> nums = {1,2,3,4,5};
    for_each(nums.begin(),nums.end(),[](int& x){
        x *= x;
    });

    for_each(nums.begin(),nums.end(),[](int& x){
        cout<<x<<", ";
    });
    cout<<endl;

    return 0;
}
