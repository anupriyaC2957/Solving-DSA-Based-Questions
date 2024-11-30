/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row= matrix.size(); // no of rows
        int col= matrix[0].size(); // matrix[0] one row selected and col size is calculated

        vector<int>ans; // sol of spiral pattern in linear form stored
        int count=0; // track the number of elements entered in the ans

        int total = row*col; // 4*4 = 16 elements; 3*3 = 9 elements total

        //technically (count < total)  

        // if we take the 3*3 matrix -->

        int Row_Start = 0;
        int Col_Start= 0;

        int Row_End= row-1; //2
        int Col_End = col-1; //2

        while(count < total) // first time: 0<9 second time: 8<9
        {
            //PART 1: 

            // row is constant at Row_Start(0 index) and col is changing
            // second time: Row_start =1 and col is changing till Col_End =1
            for(int j= Col_Start; count < total && j<=Col_End; j++) 
            {
                ans.push_back(matrix[Row_Start][j]); //first time: [0,0],[0,1],[0,2]  second time: [1,1]
                count++; 
                //first time: 3 
                //second time: 9 --> when repeated failed as now count = total (none after this loop work)
            }
            Row_Start++;// current start row--> 1

            //PART 2:

            // col is contant at Col_End(row-1--> 2 index) and row is changing from updated current start row to last
            for(int i= Row_Start; count<total && i<= Row_End; i++) // 1--> row-1 that is 1-->2
            {
                ans.push_back(matrix[i][Col_End]); //[1,2],[2,2]
                count++;// 3+2 = 5
            }
            Col_End--; // current end col --> 1

            // PART 3:

            // Row fixed at end (Row_End--> 2) and Col is changing from current Col_End=1 to Col_Start=0

            for(int j=Col_End; count<total && j>=Col_Start; j--)
            {
                ans.push_back(matrix[Row_End][j]); //[2,1][2,0]
                count++; // 5+2= 7
            }
            Row_End--; //current end row --> 1

            //Part 4:

            // Col fixed at Col_Start and Row Changing (Row_End(1) - Row_Start(1) as moving from down to up)

            for(int i=Row_End; count<total && i>=Row_Start; i--)
            {
                ans.push_back(matrix[i][Col_Start]); //[1,0]
                count++; //7+1 = 8

            }
            Col_Start++; // col start -->1
            

            /* currently: 
            row_start =1;
            row_end=1
            col_start =1
            col_end=1 --> 1 element is left overall */

            // only [1,1] is left --> again go into the loop count = 8 total =9

        }
        return ans;
    }

int main()
{
    int n, m;

    cout<<"Enter the Number of Rows: ";
    cin>>n;

    cout<<"Enter the Number of Columns: ";
    cin>>m;

    cout<<"Enter the Matrix: ";

    vector<vector<int>>matrix(n,vector<int>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);


    cout<<"The Spiral Matrix is: ";
    
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }

    return 0;

}

