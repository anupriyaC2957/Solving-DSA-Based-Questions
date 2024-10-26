# include<iostream>
using namespace std;

int Find_Pivot(int arr [], int n)
{
    int s=0;
    int e=n-1;
    int mid ;
    while(s<e)
    {
        mid=(s+e)/2;
        if(arr[0]<=arr[mid])
        {
            s=mid+1;
        }
        else //arr[0]> arr[mid]
        {
            e=mid;
        }
    }
    return s;
}

int main()
{
    int n;
    n=8;
    /*this array is such that it is sorted and rotated by 2 -- 
    EXAMPLE 1: array_original=[1,2,3,7,9]--sorted
    by 2 right side rotated [7,9,1,2,3] --> array passed-->ans:2

    EXAMPLE 2: array_original =[16,17,23,34,45,67,78,90]
    rotate - [45,67,78,90,16,17,23,34] ---> rotated right by 4 steps-->ans: 4

    EXAMPLE 3: array_original = [16,17,23,34,45,67,78,90]
    this time rotate it left by 3 steps = [34,45,67,78,90,16,17,23]-->ans:5
    */

    int arr[8]={34,45,67,78,90,16,17,23};
    int result= Find_Pivot(arr,n);
    cout<<"The pivot(min or max element ---in this code (min) element) is at index: "<< result;
    
    
    return 0;

}
