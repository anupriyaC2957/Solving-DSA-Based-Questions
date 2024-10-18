#include<iostream>
using namespace std;

int Binary_Search(int arr[], int n, int s)
{
  int left=0;
  int right= n-1;
  
  while(left<=right)
  {
    int mid = (right+left)/2;
    if(arr[mid]==s)
        return mid;
  
    else if (arr[mid]>s)
        right=mid-1;

    else //arr[mid]<s
        left = mid+1;

   }
   return -1;

}


int main()
{
    int n,search;
    cout<<"Size:";
    cin>>n;
    int arr[n];
    cout<<"The element to search: ";
    cin>>search;
    cout<<"Enter the array: ";
    for (int k=0;k<n;k++)
        cin>>arr[k];
   int result= Binary_Search(arr,n,search);
   if(result==-1)
        cout<<"Element not found";
   cout<<"Searched element is at index: "<<result+1;
   return 0;

}