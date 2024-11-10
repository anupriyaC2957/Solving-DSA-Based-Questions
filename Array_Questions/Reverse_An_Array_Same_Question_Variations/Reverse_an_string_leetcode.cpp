// Array: h e l l o
// Reversed: o l l e h

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print_array(vector<char>arr)
{
    cout<<"The Reversed Array is: ";
    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<char> Reverse_an_Array(vector<char> arr, int n)
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
    vector<char>arr(n);
    cout<<"Enter the Array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<char>result;
    result =  Reverse_an_Array(arr, n);

    Print_array(result);

    return 0;
    
}


