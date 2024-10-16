#include<bits/stdtr1c++.h>
using namespace std;


int findDuplicate(vector<int>&arr)
{
   int ans=0;
   for(int i=0;i<arr.size();i++)
   {
    ans=ans^arr[i];
   }
   for( int i=1;i<arr.size();i++)
   {
    ans=ans^i;
   }
   return ans;
}

int main()
{
    int t;
    cout<<"Enter the number of Test cases";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter the size of the array";
        cin>>n;
        vector<int> arr(n);
        cout<<"enter the array";
        for(int i=0;i<n;i++)
        {
         cin>>arr[i];
        }
        int result= findDuplicate(arr);
        cout<<"DUPLICATE VALUE IS: "<<result<<endl;
    }
}