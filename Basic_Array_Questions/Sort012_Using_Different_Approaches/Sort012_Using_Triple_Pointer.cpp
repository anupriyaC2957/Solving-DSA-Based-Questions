#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void sort012(int *arr, int n)
{
 int step=0;
 int i=0;
 int j=n-1;
 int mid=0;

 while(mid<=j)
 {
    cout<<"Steps "<<step++<<" : "<<endl;
    printarray(arr,n);
    if(arr[mid]==0)
    {
       swap(arr[i],arr[mid]);
       i++;
       mid++;
    }
    else if (arr[mid]==1)
      mid++;
   
    else // arr[mid]==2
    {
       swap(arr[j],arr[mid]);
       j--;
       cout<<endl<<"value of j"<<j;
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
    sort012(arr,n);
    cout<<"Printing The sorted 012 Array: ";
    printarray(arr,n);
    return 0;

}
