/*  FIND IF NUMBER IS PRIME OR NOT -->
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

n= 0 or 1 --> Output: 0 (both)

n = 5000000 --> no TLE problem faced 
output: There are 348513 prime numbers less than 5000000

0 <= n <= 5 * 10^6
*/

//  OPTIMIZED : SIEVE OF ERATOSTHENES APPROACH --> O(NloglogN)

#include<iostream>
#include<vector>
using namespace std;


int countPrimes(int n)
{
    int count =0;

    vector<int> prime(n+1, 1); // +1 is additional incase -ve number exist 
    vector<int> prime_numbers; //optional step

    prime[0] = prime[1]= 0;

    for(int i=2; i<n; i++)
    {
        if(prime[i] ==1)
        {
            prime_numbers.push_back(i); //optional step
            count ++;

            for(int j = 2*i ; j<n; j= j+i )// number * 2 = ans + number --> from *2 *3 *4 ....multiples cal 
            {
                prime[j]=0;
            }
        }
    }

    ///* OPTIONAL STEP :
    cout<<"The Prime Number less than "<<n<<" are: ";
    for(int k=0;k<prime_numbers.size(); k++)
    {
        cout<<prime_numbers[k]<<" ";
    }
    cout<<endl; //*/

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