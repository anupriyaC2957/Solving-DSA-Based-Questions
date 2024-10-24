#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    int findInMountainArray(int arr [], int n,int target) {
        int start = 0, end = n - 1;

        // Find peak element
        while (start < end) {
            int mid = (start + end) / 2;
            int another = arr[mid];  // Store arr[mid] in another
            if (another < arr[mid+1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        int peak_index = start;

        start=0;
        end= peak_index;
        //cout<<"end side in first occurance : "<<end;
        while(start<=end)
        {
            int mid=(end+start)/2;
            int another= arr[mid];
            if(another==target)
            {
                return mid;
            }
            else if(another<target)
            {
                start=mid+1;
            }
            else 
            {
                end=mid-1;
            }
       
        }

        start=peak_index+1;
        end= n-1;
        //cout<<"end side in first occurance : "<<end;
        while(start<=end)
        {
            int mid=(end+start)/2;
            int another= arr[mid];
            if(another==target)
            {
                return mid;
            }
            else if(another<target)
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
};


int main()
{
    Solution obj;
    //Passed but too many get calls in this hence for long input too much time consumed
    int n= 5;
    int key = 5;
    int arr[5]={3,5,3,2,0};
    int output = obj.findInMountainArray(arr,n,key);
    cout<<"-----INDEX RESULT -------: "<<output;
   return 0;

}
