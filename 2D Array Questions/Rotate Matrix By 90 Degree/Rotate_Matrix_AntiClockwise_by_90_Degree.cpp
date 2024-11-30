//Anti-Clockwise Rotation: CodeNinja

/* You are given a square matrix of non-negative integers 'MATRIX'

For given 2D array :

    [    [ 1,  2,  3 ],
         [ 4,  5,  6 ],
         [ 7,  8,  9 ]  ]

After 90 degree rotation in anti clockwise direction, it will become:

    [   [ 3,  6,  9 ],
        [ 2,  5,  8 ],
        [ 1,  4,  7 ]   ]
        
*/


#include<iostream>
#include<vector>
using namespace std;
 
 
vector<vector<int>> rotateMatrix(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();

        int s=0;      
        int e= col-1;

        while(s<e)
        {
            for(int i=0; i<row; i++) // Row wise compare --> between two fixed Columns
            {
                swap(matrix[i][s], matrix[i][e]); 
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
        return matrix;   
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

    vector<vector<int>>result= rotateMatrix(matrix);


    cout<<"The Anti-ClockWise Rotated Matrix is: "<<endl;
    
    for(int i=0; i<result.size(); i++)
    {
        cout<<"[ ";
        for(int j=0; j<result[0].size(); j++)
        {
            if(j==(result[0].size()-1))
            {
               cout<<result[i][j]<<" "; 
            }
            else
            {
                cout<<result[i][j]<<" , ";
            }

        }
        
        if(i==(result.size()-1))
            cout<<"]";
        else
            cout<<"],";

        cout<<endl;
    }

    return 0;
}