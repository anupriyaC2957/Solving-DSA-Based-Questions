#include<iostream>
#include<math.h>
using namespace std;

int findunique( int *arr, int size){
    int ans=0;

    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        int arr[size];
        for (int i=0; i<size; i++)
           cin>>arr[i];
    int Uniqueelement= findunique(arr, size);

    cout<<Uniqueelement;  

    }

    
    return 0;
}