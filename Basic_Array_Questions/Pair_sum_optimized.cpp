#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> PairSum(vector<int> &arr, int s){
   unordered_multiset<int>tempSet;
   vector<vector<int>>ans;
   for(int i=0;i<arr.size();i++)
   {
      int leftovers = s-arr[i];
      if (tempSet.find(leftovers) != tempSet.end()) {
        int counts = tempSet.count(leftovers);
        for(int j=0;j<counts;j++)
        {
          vector<int> temp = {min(arr[i], leftovers), max(arr[i], leftovers)};
          ans.push_back(temp);
        }
      }
      tempSet.insert(arr[i]);
   }
   sort(ans.begin(),ans.end());
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
    vector<vector<int>>result= PairSum(arr, sum );
    cout<<"the valid Pairs for the sum "<<sum<<" are:";
    for (int i = 0; i < result.size(); i++) {
            cout << "[" << result[i][0] << ", " << result[i][1] << "]" ;
        }
        cout << endl;
    }
  
    return 0;
}
