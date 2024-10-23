#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstOcurrance(vector<int>& arr,int n,int key)
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

    int LastOcurrance(vector<int>& arr,int n,int key)
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

    /*vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>result;
        int n=arr.size();

        int first = firstOcurrance(arr,n, target);
        int second = LastOcurrance(arr,n, target);
        result.push_back(first);
        result.push_back(second);
           
        
       return result; 
    }*/

    pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
    {
     pair<int,int>p;
     p.first = firstOcurrance(arr,n,k);
     p.second = LastOcurrance(arr,n,k);
     return p;
    } 
};

int main()
{
    Solution obj;
    int t,size;
    cout<<"testcases";
    cin>>t;
    while(t--)
    {
    int target;
    cout<<"To Find NUmber:";
    cin>>target;
    cout<<"size";
    cin>>size;
    cout<<"Enter the Array:";
    vector<int>arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];

    }
    /*vector<int>results= obj.searchRange(arr,target);
    cout<<"The First and the Last occurance of "<<target<<" are at Index: ";
    for(int i=0;i<results.size();i++)
    {
       cout<<results[i]<<" ";
    }
    cout<<endl;
    }*/
   pair<int,int>result = obj.firstAndLastPosition(arr,size,target);
   cout<<"The First Occurance of "<<target<<" is at index:"<<result.first;
   cout<<endl<<"The Last Occurance of "<<target<<" is at index:"<<result.second;

   return 0;
    }

}
