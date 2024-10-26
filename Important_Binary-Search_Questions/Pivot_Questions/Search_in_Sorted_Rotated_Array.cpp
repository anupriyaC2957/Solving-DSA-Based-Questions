#include<iostream>
using namespace std;

int pivot (int arr [], int n)
{
    int s=0;
    int e=n-1;
    int mid;
    while(s<e)
    {
        mid=(s+e)/2;
        if(arr[0]<=arr[mid])
        {
            s=mid+1;
        }
        else 
            e=mid;
    }
    //cout<<"pivot: "<<s;
    return s;
}

int Binary_search(int arr[], int s, int e, int target)
{
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==target)
            return mid;
  
        else if (arr[mid]>target)
            e=mid-1;

         else //arr[mid]<s
            s = mid+1;

   }
   return -1;
}

int search_element (int arr[], int n, int target)
{
    int pivot_index = pivot(arr,n);
    
    if(arr[pivot_index]<=target && target<=arr[n-1])
    {
        return Binary_search(arr,pivot_index,n-1,target);
        
    }
    
    else
    { 
        return Binary_search(arr,0,pivot_index-1,target);

    }


}

int main()
{
    int n;
    n=8;
    int arr[8]={34,45,67,78,90,16,17,23};
    int search;
    search = 67;
    int pos = search_element(arr,n,search);
    cout<<"The element to find is at index: "<<pos;

}