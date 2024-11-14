#include<iostream>
#include<vector>
using namespace std;


bool isPalindrome(long long int x) {

        if (x < 0)
             return false;
        
        vector<int>arr;

        long long int current_number,modified_number;

        while(x>0) //12
        {
            current_number= x; //121  --> //12
            x= x/10; //12 --> //1
            modified_number= x*10;//120 -->//10
            current_number= current_number-modified_number;//121-120  --> 12-10 = 2

            arr.push_back(current_number); //1  --> //2
        }
         
        int s=0;
        int e=arr.size()-1;

        while(s<=e)
        {
            if(arr[s] != arr[e])
            {
                return false;
            }
            else
            {
                s++;
                e--;
            }
        }
        return true;
    }

int main()
{
    long long int n= 123456654321;

    bool result = isPalindrome(n) ;

    cout<<endl<<" Is the number "<<n<<" Palindrome ? --> "<<result<<endl;
    return 0;
}