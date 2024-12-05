/*  FIND IF NUMBER IS PRIME OR NOT -->
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

n= 0 or 1 --> Output: 0 (both)
*/

// WHY NOT OPTIMIZED ? O(n^2)--> 0 <= n <= 5 * 10^6 --> code run 5000000 --> Time Exceed Limit 

#include<iostream>
#include<vector>
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

int countPrimes(int n)
{
    int count =0;
    vector<int> prime_numbers;

    for(int i=0; i<n; i++)
    {
        if (isPrime(i)== true)
        {
            prime_numbers.push_back(i);
            count++;
        }

    }
    
    cout<<"The Prime Number less than "<<n<<" are: ";
    for(int j=0;j<prime_numbers.size(); j++)
    {
        cout<<prime_numbers[j]<<" ";
    }
    cout<<endl;

    return count;
}


int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    int result = countPrimes(n);

    cout<<"There are "<<result<<" prime numbers less than "<<n;

    return 0;   
}