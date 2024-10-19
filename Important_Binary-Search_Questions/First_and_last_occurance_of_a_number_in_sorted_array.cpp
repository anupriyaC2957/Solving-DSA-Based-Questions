#include<iostream>
using namespace std;

void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int firstOcurrance(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int ans =-1;
    while(start<=end)
    {
       int mid=(end+start)/2;
       if(arr[mid]==key)
       {
            ans=mid; 
            end = mid-1;
       }
       else if(arr[mid]<key)
       {
            start=mid+1;
       }
       else //arr[mid]>key
       {
            end=mid-1;
       }
       
    }
    return ans;

}
int LastOcurrance(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int ans =-1;
    while(start<=end)
    {
       int mid=(end+start)/2;
       if(arr[mid]==key)
       {
            ans=mid; 
            start = mid+1;
       }
       else if(arr[mid]<key)
       {
            start=mid+1;
       }
       else //arr[mid]>key
       {
            end=mid-1;
       }
       
    }
    return ans;

}

int main()
{
    int arr[10]={1,2,2,3,3,3,3,4,4,5};
    cout<<"First Occurance of 3 is at Index: "<< firstOcurrance(arr,10,3)<<endl;
    cout<<"Last Occurance of 3 is at Index: "<< LastOcurrance(arr,10,3)<<endl;
  
   
   return 0;

}