// Time Complexity O(n^2)--> SELECTION SORT

#include<iostream>
using namespace std;

int smallest(int arr[], int k, int n)
{
    int small = arr[k];
    int pos=k;
    for(int i=k+1; i<n; i++)
    {
        if(small>arr[i])
        {
            small=arr[i];
            pos=i;
        }

    }
    return pos;
}

void selection_sort (int arr[], int n)
{
    int temp, pos;

    for(int i=0;i<n;i++)
    {
        pos= smallest(arr,i,n);
        temp =arr[pos];
        arr[pos] = arr[i];
        arr[i]=temp;
    }

}
int main()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
