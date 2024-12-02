/* matrix is of m*n size: --> leetocde and code ninja 
Input: matrix = 
[[1   ,4   ,7  ,11  ,15],
 [2   ,5   ,8  ,12  ,19],
 [3   ,6   ,9  ,16  ,22],
 [10 ,13  ,14  ,17  ,24],
 [18 ,21  ,23  ,26  ,30]], target = 5

Output: true

// 1 4 7 11 15 2 5 8 12 19 3 6 9 16 22 10 13 14 17 24 18 21 23 26 30 ---> not sorted 
// each row sorted and each col sorted 

Example 2:

Input: Row:5 and Col: 5 matrix = 1 4 7 11 15 2 5 8 12 19 3 6 9 16 22 10 13 14 17 24 18 21 23 26 30 --> target = 20
Output: false
*/

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    int Row_Index =  0;
    int Col_Index =  col-1;

    while(Row_Index < row && Col_Index >=0)
    {
        int element = matrix[Row_Index][Col_Index];

        if(target == element)
        {
            return 1;
        }
        else if (target < element)
        {
            Col_Index--;
        }
        else
        {
            Row_Index++;
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
