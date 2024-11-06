//Bubble Sort Time complexity--> worst case: O(n^2) and best case: O(n)

#include<iostream>
#include<vector>
using namespace std;

void Bubble_sort(vector<int>& arr, int n)
{
    int swapped= false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
    }
    if(swapped==false)
        return ; //is valid becos its returning without any value
    
}

int main()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the Array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Bubble_sort(arr,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}