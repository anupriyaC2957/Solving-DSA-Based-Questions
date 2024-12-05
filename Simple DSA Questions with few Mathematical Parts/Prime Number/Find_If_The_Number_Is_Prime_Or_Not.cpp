/*  FIND IF NUMBER IS PRIME OR NOT -->
n= 11 --> Output: Yes
n= 0 or 1 --> Output: No
n= 2 --> Output: Yes
n= 200 --> Output: No */

#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n==1 || n==0)
    {
        return false;
    }

    for(int i=2; i<n; i++)
    {
        if(n%i == 0) // 2 - (n-1) any number get divible to n then its not a prime
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    bool result = isPrime(n);

    cout<<"Is the Number "<<n<<" Prime? --> "<<(result ? "Yes": "No");

    return 0;   
}
