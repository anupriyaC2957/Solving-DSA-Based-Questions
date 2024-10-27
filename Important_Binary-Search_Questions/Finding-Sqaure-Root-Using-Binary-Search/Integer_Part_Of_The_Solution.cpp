#include<iostream>
using namespace std;

int square_root(int n)
{
    int s=0;
    int e=n;
    long long int mid,ans;
    while(s<=e)
    {
        mid=(s+e)/2;
        long long int square = mid* mid;

        if(square==n)
        {
            return mid;
        }
        
        if(square>n)
        {
            e=mid-1;
        }

        else
        {
            ans=mid;
            s=mid+1;
        }
            
    }
    return ans;// everytime there won't be be an exact rootvalue hence the closest value will be returned via ans 
    // if exact ans is available then it would be returned via the first igf loop returning mid value.
}

int main()
{
    int n;
    n=27;
    long long int result = square_root ( n);
    cout<<"Square root of "<<n<<" is: "<<result;
    return 0;
}
