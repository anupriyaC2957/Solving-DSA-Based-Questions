// Array: 1 2 3 4 5 6 7 when k=3
// Rotated in Forward Direction: 5 6 7 1 2 3 4


#include<bits/stdtr1c++.h>
using namespace std;

void Rotate(vector<int> &arr, int n, int k)
{
    int index;
    vector<int> temp =arr;
    for(int i=0;i<n;i++)
    {
        index= (i+k)%n;
        arr[index]=temp[i];

    }
  
}

int main()
{
    int n,k;
    cout<<endl;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the Steps to Rotate in Forward Direction: ";
    cin>>k;
    vector<int> arr(n);
    cout<<"Enter The Array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    cout<<"Rotated Array: ";
    Rotate(arr,n,k);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
