// n=678 then ans: 21

#include<iostream>
using namespace std;

int Sum_of_Digits(int actual_number)
{
    int temp,modified_number;
    int sum =0;

    while(actual_number>0)
    {
     temp = actual_number; // actual no store
     actual_number = actual_number/10;  // last digit store
     modified_number= actual_number * 10; // removing last number *10 
     sum += (temp-modified_number); // last digit extract --> sum --> add
    }
    return sum;
}

int main()
{
    int n=678;
    int result =Sum_of_Digits(n);
    cout<<endl<<"Sum of the Digit of the Number "<<n<<" is: "<<result<<endl;

    return 0;
}