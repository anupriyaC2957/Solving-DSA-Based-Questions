/*

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}. 

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void Reverse_an_Array(vector<int> & arr, int m)
{
    int s=m+1;// next element to m is the point at which you need to start reversing
    int n=arr.size();
    int e=n-1;
    while(s<=e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{
    int n;
    cout<<"Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the Array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cout<< "Enter the position from which the reversal needs to be done from: ";
    cin>>m;
    cout<<endl;
    
    Reverse_an_Array(arr, m);
    
    cout<<"The Reversed Array is: ";
    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
    
}


