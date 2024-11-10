// Array: 5 4 3 1 2 ---> True
// Array: 2 3 4 5 6 ---> True
// Array: 1 1 1 ---> True
// Array: 2 1 3 4 ---> False


#include<bits/stdtr1c++.h>
using namespace std;

bool Check_Sorted_and_Rotated(vector<int> &arr)
{
   int count_pair =0;
   int n= arr.size();

   for(int i=1; i<n ; i++)
   {
        if(arr[i-1]>arr[i])
        {
            count_pair ++;
        }
   }
   if(arr[n-1]>arr[0])
   {
    count_pair ++;
   }

   return count_pair <=1;
  
}

int main()
{
    int n,k;
    cout<<endl;
    cout<<"Enter the size: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter The Array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    cout<<"Checked If Array is Sorted & Rotated: ";
    bool result = Check_Sorted_and_Rotated(arr);

    cout<<(result ? "True" : "False")<<endl;

}
