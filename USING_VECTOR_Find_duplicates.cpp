#include<bits/stdtr1c++.h>
using namespace std;


int findDuplicate(vector<int>& arr) {
    unordered_map<int, int> ans;
    
    for(int i = 0; i < arr.size(); i++) {
        ans[arr[i]]++;
        
        if (ans[arr[i]] == 2) {
            return arr[i];
        }
    }
    
    return -1; 
}

int main() {
    int t; // number of test cases
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << findDuplicate(arr) << endl;
    }
    
    return 0;
}