#include<iostream>
#include<vector>
using namespace std;

void Insertion_sort(vector<int> &arr, int n)  //39 9 45 63 18 81 108 54 72 36
{
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        int j=i-1;
        while((arr[j]> temp) && j>=0 )
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

}

int main()
{
    int n;
    cout<<endl<<"Enter the size of the array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Insertion_sort(arr,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}