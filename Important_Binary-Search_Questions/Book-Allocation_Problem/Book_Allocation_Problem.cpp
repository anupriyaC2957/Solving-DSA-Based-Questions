/* QUESTION 1:

Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

There are ‘m’ number of students, and the task is to allocate all the books to the students.

CONDITIONS: 
Allocate books in such a way that:
1. Each student gets at least one book. 
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner. (10 and 30 cannot be allocated it needs to be continuous)

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
(There could be different combinations to which the books could be distributed among student.
Our aim to find a solution where max no of pages assigned to a student is minimum 
that is if maximum pages in different combinations are [90, 70,60] then ans to minimum is 60)

If the allocation of books is not possible, return -1.
(if (m>n)--> -1);

Example:
Input: ‘n’ = 4 (no of books) ‘m’ = 2 (no of students)
‘arr’ = [10,20,30,40] (no of pages in each book)

Output: 60
*/

//QUESTION 2

/* Same code Leetcode for the question: **Split Array Largest Sum**

Given an integer array nums and an integer k, split nums into k non-empty subarrays ----such that the largest sum of any subarray is minimized.----IMPORTANT LINE

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

THE REMAINS EXACTLY THE SAME JUST THE OVERALL WORDS ARE CHANGED
*/

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>arr,int n, int m, int mid)
{
    int student_count = 1;
    int page_count =0;

    for(int i=0;i<n;i++)
    {
        if((page_count + arr[i])<=mid)
            page_count +=arr[i];
        
        else
        {
            student_count ++;
            if(student_count > m || arr[i]>mid)
            {
                return false;
            }
            page_count=0;
            page_count +=arr[i];
        }
    }
    return true;
}

int AllocateBook(vector<int>arr,int n, int m)
{
    int s=0;
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
    }
    int e=sum; //100
    int mid;
    int ans=-1;
    
    if(m>n)
    {
        return -1;
    }

    while(s<=e)
    {
        mid= (s+e)/2;

        if(isPossible(arr,n,m,mid))
        {
            ans=mid;
            e=mid-1; //minimum value of acceptance 
        }
        else
        {
            s=mid+1; //value is too small hence move ahead
        }

    }
    return ans;
}

int main()
{
    int n,m;
    cout<<"Enter the Number of Students: ";
    cin>>m;
    cout<<"Enter the Number of Books: ";
    cin >>n;
    vector<int> arr(n);
    cout<<"Enter the Number of Pages in Each Book: ";
    for(int i=0; i<n;i++)
        cin>>arr[i];
    
    int result = AllocateBook(arr,n,m);
    cout<<"Maximum number of pages assigned to a student is Mimimum when it is: "<<result;

    return 0;
}



