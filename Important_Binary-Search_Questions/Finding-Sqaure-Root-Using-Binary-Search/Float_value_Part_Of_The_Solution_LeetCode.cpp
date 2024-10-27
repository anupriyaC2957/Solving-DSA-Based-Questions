#include<iostream>
using namespace std;

int MainPart(int n)
{
    int s=0;
    int e=n;
    long long int mid;
    long long int square,ans;
    while(s<=e)
    {
        mid=(s+e)/2;
        square = mid*mid;
        
        if(square == n)
            return mid;

        if(square>n)
            e=mid-1;
        
        else //square<n
        {
            ans=mid;
            s=mid+1;
        }

    }
    return ans;
}

double More_Precise(long long int n,long long int precision, long long int temp)
{
    double factor =1;
    double ans;
    ans=temp;

    for(int i=0;i<precision;i++)
    {
        factor = factor/10;

        for(double j= ans; (j*j) < n; j=j+factor )
        {
            ans=j;
        }
    }
    return ans;
}

int main()
{
    long long int n, precision;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"precision value: ";
    cin>>precision;

    long long int temp = MainPart(n);

    double result= More_Precise(n,precision,temp);
    cout<<"Square Root (Float) of "<<n<<" is: "<<result;



}
