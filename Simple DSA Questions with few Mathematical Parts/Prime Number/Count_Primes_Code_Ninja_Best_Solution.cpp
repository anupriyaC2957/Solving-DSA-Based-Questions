/*  
Input  1: 35   | Input  2: 44   | Input  3: 900   | Input  4: 441  |
Output 1: 5 7  | Output 2: 2 11 | Output 3: 2 3 5 | Output 4: 3 7  |

-----------------WORKING---------------------------
FOR n= 44:

44/2=22 --> 22/2=11 --> 11/2 is not equal to 0 --> 11/11= 0 ==> Output: [2,11]

FOR n=900:

900/2 = 300 --> 300/2 = 150 --> 150/2 = 75 --> 75/2 is not equal to 0 --> 75/3 = 25 --> 25/3 is not equal to 0
--> 25/5 =0 --> 0/5 exit ==> Output: [2,3,5]

Time complexity: 

O(NloglogN)+O(sqrt(N))

For large value of N O(NloglogN) dominates hence: overall Time Complexity is O(NloglogN) 

Sapce Complexity: O(N)

*/ 

#include<iostream>
#include<vector>
using namespace std;


vector<int> countPrimes(int n)
{
    vector<int> prime(n+1, 1);
    vector<int> prime_numbers;
    vector<int> factors;

    // Part 1: Got all the prime numbers less than the range number n
    prime[0]= prime[1]= 0;

    for(int i=2; i<n; i++)
    {
        if(prime[i]==1)
        {
            for(int j=2*i ; j<n; j= j+i)
            {
                prime_numbers.push_back(i);
                prime[j]=0;
            }
        }
    }

    // Part 2: Select the prime number which are factors of the number n

    for(int i=0; i<prime_numbers.size(); i++)
    {
        if(n% prime_numbers[i] ==0)
        {
            factors.push_back(prime_numbers[i]);
        }
        while(n% prime_numbers[i] ==0) // is it possible to be divided by the same number again ?
        {
            n /= prime_numbers[i]; 
        }
    }

    return factors;
}


int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    vector<int> result = countPrimes(n);

    cout<<"The unique prime factors of "<<n<<" in increasing order are: ";
    for(int k=0;k<result.size(); k++)
    {
        cout<<result[k]<<" ";
    }
    cout<<endl;

    return 0;   
}
