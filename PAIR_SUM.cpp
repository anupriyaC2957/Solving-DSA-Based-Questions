#include <bits/stdtr1c++.h>
using namespace std;

vector<vector<int>> PairSum(vector<int> &arr, int s)
{
    vector<vector<int>>ans;
    for(int i=0; i<arr.size();i++)
    {
        for (int j=i+1; j<arr.size(); j++)
        {
            if(arr[i]+arr[j]==s)
            {
                vector<int>temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);

            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int t,sum;
    cout<<"testcases:";
    cin>>t;
    while(t--){
        int size;
        cout<<"enter sum of the pair needed:";
        cin>>sum;
        cout<<"enter size of the array:";
        cin>>size;

        vector<int>arr(size);
        for (int i=0; i<size; i++)
           cin>>arr[i];
    vector<vector<int>>result= PairSum (arr, sum );
    cout<<"the valid Pairs for the sum "<<sum<<" are:";
    for (int i = 0; i < result.size(); i++) {
            cout << "[" << result[i][0] << ", " << result[i][1] << "]" ;
        }
        cout << endl;
    }
  
    return 0;
}