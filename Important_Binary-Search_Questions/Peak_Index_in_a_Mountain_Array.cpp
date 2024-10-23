/* There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 
Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1*/ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        int peak_value_index ( vector<int> arr)
        {
            int start =0;
            int end=arr.size()-1;
            int mid;
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
            cout<<"PEAK VALUE: "<<arr[end]<<endl; //10
            return end; //it could be mid, start, end as at the end loop all will be at same point
        }

};

int main()
{
    Solution obj;
    
    int n;
    cout<<"Size:";
    cin>>n; //12
    vector <int> arr(n);
    cout<<"Enter the Mountain Array: "; // 0 1 2 3 5 6 10 8 7 5 3 1
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int result = obj.peak_value_index(arr);
    cout<<"Peak Value INDEX: "<<result; //6
   
   return 0;

}