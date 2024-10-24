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


int resultant(int arr[], int n, int key) {
    int peak_index = peak_value_index(arr, n);

    int start=0;
    int end= peak_index;
    //cout<<"end side in first occurance : "<<end;
    
    while(start<=end)
    {
       int mid=(end+start)/2;
       int another = arr[mid];
       if(another==key)
       {
            return mid;
       }
       else if(another<key)
       {
            start=mid+1;
       }
       else //arr[mid]>key
       {
            end=mid-1;
       }
       
    }

    // If not found in the ascending part, search in the descending part (peak_index+1 to n-1)
    start=peak_index+1;
    end= n-1;
    //cout<<"end side in first occurance : "<<end;
    
    while(start<=end)
    {
       int mid=(end+start)/2;
       int another = arr[mid];
       if(another==key)
       {
            return mid;
       }
       else if(another<key)
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
