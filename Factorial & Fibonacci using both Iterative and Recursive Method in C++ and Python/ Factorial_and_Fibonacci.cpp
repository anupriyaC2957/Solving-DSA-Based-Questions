#include<iostream>
using namespace std;

void fibonacci(int n)
{
    int n1=0;
    int n2=1;
    int new_number;
    cout<<n2<<" ";

    while(n>0)
    {
        new_number=  n1+n2;
        cout<<new_number<<" ";
        n1= n2;
        n2= new_number;
        n--;
    }
}

void factorial(int n)
{
    int fact =1;
    for(int i=1; i<=n; i++)
    {
        if(i==n)
            cout<<i<<" ";
        else
            cout<<i<<" X ";
        fact = fact*i;
    }
    cout<<endl<<"Answer:"<<fact;
}

int reccursive_fibonacci(int i)
{
    if(i<=0)
        return i;

    else
        return reccursive_fibonacci(i-1) + reccursive_fibonacci(i-2);    
}

int reccursive_factorial(int n)
{
    if(n==1)
        return n;

    else
        return n*reccursive_factorial(n-1);    
}

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
 
    //-----NORMAL ITERATIVE FIBONACCI-------

    // cout<<"Fibonacci: ";
    // fibonacci(n);

    //----NORMAL ITERATIVE FACTORIAL-------

    // cout<<endl;
    // cout<<"Factorial: ";
    // factorial(n);

    //----RECCURSIVE FIBONACCI-------

    // int result[n];

    // if(n<0)
    // {
    //     cout<<"give a positive number ";
    // }
    // else
    // {

    // for(int i=0; i<n;i++)
    // {
    //     int result = reccursive_fibonacci(i);

    //     cout<<result<<" ";
    // }

    //}

    //----RECCURSIVE FACTORIAL-------

    int result = reccursive_factorial(n);

    cout<<"Factorial: "<<result<<" ";
    
    return 0;
}
