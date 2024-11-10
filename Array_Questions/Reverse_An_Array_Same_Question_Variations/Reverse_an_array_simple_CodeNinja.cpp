// Array: 11 7 3 12 4 
//Reverse: 4 12 3 7 11

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print_array(vector<int>arr)
{
    cout<<"The Reversed Array is: ";
    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> Reverse_an_Array(vector<int> arr, int n)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return arr;
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
    vector<int>result;
    result =  Reverse_an_Array(arr, n);

    Print_array(result);

    return 0;
    
}


