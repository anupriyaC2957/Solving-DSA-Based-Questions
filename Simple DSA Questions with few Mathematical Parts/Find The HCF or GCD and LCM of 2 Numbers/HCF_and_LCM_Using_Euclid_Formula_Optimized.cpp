/*
Euclid formula: 

GCD/HCF:

gcd(a,b)= gcd(a-b,b) if a>b and gcd(a,b-a) when b>a
when a=b then return a or b to get the ans 

if a==0 then return b and if b==0 then return a 

LCM:

lcm(a,b)*hcf(a,b)= a*b
lcm(a,b)= a*b/hcf(a,b) --> (a/hcf(a,b))*b

*/

#include<iostream>
using namespace std;

long long calcGCD(int n, int m) // Time Complexity: O(N)
{
    while(m!=0)
    {
        int temp= m;
        m = n%m;
        n = temp;
    }
    return n;
}

long long LCM(int x, int y)
{
    long long hcf = calcGCD(x,y);

    //long long lcm =  (x*y)/ hcf; 
    
    // if x= 100000 and y = 100000 --> hcf= 100000
    // (x*y) before reaching long long it already is in int form hence 100000* 100000 => out of bound condition
    // hence to there are 2 ways 
   
    //APPROACH 1: Forcefully convert the x*y approach into long long internally while multiplying
    
    //long long lcm =  (1LL * x * y)/ hcf; 

    //APPROACH 2: Simplification
    
    long long lcm =  (x/ hcf) *y; // make multiplication a little easier

    return lcm;

}
int main()
{
    int a,b;

    cout<<"Enter the First Number: ";
    cin>>a;

    cout<<"Enter the Second Number: ";
    cin>>b;

    long long HCF_result= calcGCD(a,b);
    long long LCM_result= LCM(a,b);

    cout<<"The HCF or GCD of the numbers "<<a<<" and "<<b<<" is: "<<HCF_result<<endl;
    cout<<"The LCM of the numbers "<<a<<" and "<<b<<" is: "<<LCM_result;

    return 0;

}