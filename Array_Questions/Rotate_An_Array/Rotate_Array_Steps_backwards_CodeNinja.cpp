// Array: 1 2 3 4 5 6 7 when k=3
// Rotated in Backward Direction: 4 5 6 7 1 2 3

#include<bits/stdtr1c++.h>
using namespace std;


void Rotate(vector<int> &arr, int k)
{
    int index;
    int n=arr.size();
    vector<int>temp= arr;
    for(int i=0;i<n;i++)
    {
        index = (i+n-k)%n;
        arr[index]=temp[i];

    }
}

int main()
{
    int n,k;
    cout<<endl;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the Steps to Rotate in Backward Direction: ";
    cin>>k;
    vector<int> arr(n);
    cout<<"Enter The Array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    cout<<"Rotated Array: ";
    Rotate(arr,k);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
