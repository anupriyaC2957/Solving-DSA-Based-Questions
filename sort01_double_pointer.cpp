#include<iostream>
using namespace std;

void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void sort01(int arr[], int size)
{
    //int step=0;
    int i=0;
    int j=size-1;
    while(i<j)
    {
       // cout<<"step"<<step++<<endl;
       // printarray(arr,size);
        if(arr[i]==0)
            i++;
        if(arr[j]==1)
            j--;
        if(arr[i]==1 && arr[j]==0)
        {
          swap(arr[i],arr[j]);
          i++;
          j--;
        }
        
    }
}

int main()
{
    int n;
    cout<<"Size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for (int k=0;k<n;k++)
        cin>>arr[k];
    sort01(arr,n);
    cout<<" Printing The sorted 01 Array: ";
    printarray(arr,n);
    return 0;

}