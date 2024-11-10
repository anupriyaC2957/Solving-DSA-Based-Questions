#include <bits/stdtr1c++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int s) {
       unordered_multiset<int>tempSet;
       unordered_map<int,int> indexmap;
       vector<int>ans;
       
       for(int i=0;i<arr.size();i++)
       {
        int leftovers = s-arr[i];
        if (tempSet.find(leftovers) != tempSet.end()) 
        {          int counts = tempSet.count(leftovers);
           for(int j=0;j<counts;j++)
            {
                ans={indexmap[leftovers],i};
                return ans;
    
            }
        }
         tempSet.insert(arr[i]);
         indexmap[arr[i]]=i;
        }
        return ans;  
    }
};

int main() {
    Solution obj;
    int t,s; // number of test cases
    cout<<"Testcases: ";
    cin >> t;
    
    while(t--) {
        int n;
        cout<<"Enter the size of the array: ";
        cin >> n;
        cout<<"Enter the paired sum total: ";
        cin>>s;
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int>result= obj.twoSum(arr,s);
        cout<<"the result pair sum value is: ";
        cout<<"[";
        for(int i=0;i<result.size();i++)
        {
            cout<<" "<<result[i]<<" ";
        }
        cout<<"]";
    }
    
    return 0;
}
