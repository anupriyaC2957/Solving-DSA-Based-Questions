//LEETCODE: 
/*

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
Input: 
    [    [ 1,  2,  3 ],
         [ 4,  5,  6 ],
         [ 7,  8,  9 ]  ]
Output: 
    [    [ 7,  4,  1 ],
         [ 8,  5,  2 ],
         [ 9,  6,  3 ]  ]
*/

#include<iostream>
#include<vector>
using namespace std;
 
 
 void rotate(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();

        int s=0;      
        int e= row-1;

        while(s<e)
        {
            for(int j=0; j<col; j++) // column wise compare --> between two fixed rows
            {
                swap(matrix[s][j], matrix[e][j]); 
            }
            s++;
            e--;
        }

        for(int i=0; i<row; i++)
        {
            for(int j=i+1; j<col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }   
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

    rotate(matrix);


    cout<<"The ClockWise Rotated Matrix is: "<<endl;
    
    for(int i=0; i<matrix.size(); i++)
    {
        cout<<"[ ";
        for(int j=0; j<matrix[0].size(); j++)
        {
            if(j==(matrix[0].size()-1))
            {
               cout<<matrix[i][j]<<" "; 
            }
            else
            {
                cout<<matrix[i][j]<<" , ";
            }

        }
        
        if(i==(matrix.size()-1))
            cout<<"]";
        else
            cout<<"],";

        cout<<endl;
    }

    return 0;
}
