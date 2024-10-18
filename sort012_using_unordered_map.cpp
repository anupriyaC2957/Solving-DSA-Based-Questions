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
   unordered_map<int,int>ans;
   int index=0;
   for (int i = 0; i < n; i++) {
     ans[arr[i]]++;
   }
   for(int num=0;num<=2;num++)
   {
      int count = ans[num];

      for (int k = 0; k < count; k++) {
            arr[index++] = num; 
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