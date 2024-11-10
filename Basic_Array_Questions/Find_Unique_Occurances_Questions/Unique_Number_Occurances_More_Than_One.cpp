#include<bits/stdtr1c++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ans;
        for(int i=0; i<arr.size(); i++){
            ans[arr[i]]++;
        }
        set<int> freq;
        for(auto it : ans){
            if(freq.count(it.second) > 0 ){
                return false;
            }
            freq.insert(it.second);
        }
      return true;  
    }
};

int main(){
    Solution obj ;
    int n;
    cout<<"enter the size of the array";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool result = obj.uniqueOccurrences(arr);
    cout<<(result ? "The Occurances are Unique": "There are duplicate occurances")<<endl;
    return 0;
    
}
