#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int i= m-1;
    int j = n-1;
    int k= (m+n)-1;

    while(i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
        {
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k]= nums2[j];
            j--;
            k--;
        }
    }

    while(j>=0)
    {
        nums1[k]= nums2[j];
        j--;
        k--;
    }

    while(i>=0) //Redundant Step
    {
        nums1[k]= nums1[i];
        i--;
        k--;
    }
    
 
}

int main()
{
    int m, n;

    cout<<endl;
    cout<<"Number of Elements in Array 1: ";
    cin>>m;
    cout<<"Number of Elements in Array 2: ";
    cin>>n;

    int t=m+n;

    cout<<endl;

    cout<<"The Total Size of Array 1: "<<t<<endl;
    cout<<"The Size of Array 2 would be same as Number of Elements: "<<n<<endl;
    

    vector<int>nums1(t);
    cout<<endl;
    cout<<"---NOTE: End 0's are place for merge elements Hence, should be Ignored---"<<endl;

    cout<<endl<<"Enter the Array 1: ";
    for(int i=0;i<t;i++)
    {
        cin>>nums1[i];
    }


    vector<int>nums2(n);
    cout<<"Enter the Array 2: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    
    cout<<endl<<"The Merged Array is: ";
    merge(nums1, m, nums2, n);

    for(int i=0; i<t;i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl; 
    
    
    return 0;
    
}

/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.


Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1. */


