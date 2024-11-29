/*

Enter the number of Rows: 4
Enter the number of Columns: 4
Enter the 2D Array: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

RESULT-->
The Wave Array: 1 5 9 13 14 10 6 2 3 7 11 15 16 12 8 4 


*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> new_array;
    int j=0;

    while(j<mCols)
    {
        if(j%2==0)
        {
            for(int i=0; i<nRows ; i++)
            {
                new_array.push_back(arr[i][j]);
            }  
        }
        else
        {
            for(int i=nRows-1; i>=0; i--)
            {
               new_array.push_back(arr[i][j]);
            } 
        }
        j++;
    }
    return new_array;

}

int main()
{
    
    int n, m;

    cout<<"Enter the number of Rows: ";
    cin>>n;

    cout<<"Enter the number of Columns: ";
    cin>>m;
    
    vector<vector<int>> arr(n, vector<int>(m));  // Initialization --> vector inside an another vector

    cout<<"Enter the 2D Array: ";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<int> result = wavePrint(arr, n, m);
    cout<<endl<<"The Wave Array: ";
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }



    return 0;
}