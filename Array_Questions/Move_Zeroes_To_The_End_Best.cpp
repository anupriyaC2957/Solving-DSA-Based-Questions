// Time Complexity: O(n)

#include<bits/stdtr1c++.h>
using namespace std;

//shifting non zeros to the left

void MoveZeroes(int arr[], int n)
{
    int NonZero=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]!= 0)
        {
            swap(arr[NonZero], arr[j]);
            NonZero++;
        }
    }
  
}

int main()
{
    int n=9;
    int arr[9]= {1,0,2,3,4,0,0,5,0};
    cout<<"Solution: ";
    MoveZeroes(arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}