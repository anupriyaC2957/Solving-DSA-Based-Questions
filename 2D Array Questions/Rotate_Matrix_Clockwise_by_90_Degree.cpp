#include<iostream>
#include<vector>
using namespace std;
 
 
 void rotate(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();

        int s=0;
        int e= row-1;

        while(s<=e)
        {
            for(int j=0; j<col; j++)
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
        for(int j=0; j<matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}