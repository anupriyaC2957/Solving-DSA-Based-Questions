// Solved using binary search
/*
Input: matrix = 
[[1 ,3 ,5 , 7],
 [10,11,16,20],
 [23,30,34,60]]

target = 3

Answer-->
Output: Yes

Logically matrix --> linear search : 1,3,5,7,10,11,16,20,23,30,34,60 --> sorted 
so concept will be same the idea is to convert the mid value such that it can be converted to row and column value

Example 2:
Row: 3 Col:4
1 3 5 7 10 11 16 20 23 30 34 60 --> target: 13 --> No
*/

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s= 0;
    int e= row*col -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        int element = matrix[mid/col][mid%col];  // why not mid/row ?
        // if we want to find 3 which is at --> index 1--> so when mid =1--> for above case 1/4 =0
        // while finding col if i did mid/ row = 1/3= 0 --> so ans would be [0,0] which is wrong it should have been [0,1]
        // if we do mid%col --> 1%4--> 1 so index: [0,1] as per required

        if(element == target)
        {
            return 1;
        }

        else if (element < target)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }

    }
    return 0;

}

int main()
{
    int n,m;

    cout<<"Enter the number of Rows: ";
    cin>>n;

    cout<<"Enter the number of Columns: ";
    cin>>m;

    cout<<"Enter the 2D Array: ";

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0; j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"Enter the Target Value: ";
    cin>> target;

    bool result =  searchMatrix(arr,target);

    cout<<"Is the Target "<<target<<" prsent in the 2D array: ";
    cout<<(result ? "Yes": "No");

}