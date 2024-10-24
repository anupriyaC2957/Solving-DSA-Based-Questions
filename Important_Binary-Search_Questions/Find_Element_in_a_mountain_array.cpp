#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int peak_value_index ( int arr [], int n)
    {
            int start =0;
            int end=n-1;
            int mid=-1;
            while(start <end)
            {
                mid=(start + end)/2;
                if( arr[mid]<arr[mid+1])
                {
                    start = mid+1;
                }
                else
                {
                    end= mid;
                }

            }
            //cout<<"PEAK VALUE: "<<arr[start]<<endl; //10
            return start; //it could be mid, start, end as at the end loop all will be at same point
    }

int FirstOccurance(int arr[],int n,int key)
{
    int start=0;
    int end= peak_value_index(arr,n);
    //cout<<"end side in first occurance : "<<end;
    int mid =0;
    while(start<=end)
    {
       int mid=(end+start)/2;
       if(arr[mid]==key)
       {
            return mid;
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
    return -1;

}
int LastOccurance(int arr[],int n,int key)
{
    int start=peak_value_index(arr,n);
   // cout<<"start side in last occurance : "<<start;
    int end=n-1;
    int mid=0;

    while(start<=end)
    {
       int mid=(end+start)/2;
       if(arr[mid]==key)
       {
             return mid;
       }
       else if(arr[mid]<key)
       {
            end=mid-1;
       }
       else //arr[mid]>key
       {
            start=mid+1;
       }
       
    }
    return -1;
}

int resultant (int arr[], int n, int key)
{
    int left_side = FirstOccurance (arr,n,key);
    int right_side = LastOccurance (arr,n,key);
    int result;
    if(left_side != -1 && right_side !=-1)
        result = min(left_side, right_side);
    else if (left_side == -1)
        result = right_side;
    else if(right_side ==-1)
        result =left_side;
    else
        result =-1;

    return result;
}


int main()
{
    //Passed but too many get calls in this hence for long input too much time consumed
    int n= 5;
    int key = 5;
    int arr[5]={3,5,3,2,0};
    int output = resultant(arr,n,key);
    cout<<"-----INDEX RESULT -------: "<<output;
   return 0;

}