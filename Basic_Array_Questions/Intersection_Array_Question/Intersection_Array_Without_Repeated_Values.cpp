#include<bits/stdtr1c++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ans1;
        unordered_map<int,int>ans2;
        vector<int>result;
        for(int i=0;i<nums1.size();i++)
        {
            ans1[nums1[i]]++;
        }
         for(int i=0;i<nums2.size();i++)
        {
            ans2[nums2[i]]++;
        }
         for (auto it : ans1) {
            
            if (ans2.find(it.first) != ans2.end()) {
                result.push_back(it.first); 
            }
        }
        
        return result;
    }
};

int main()
{
    Solution obj;
    int t;
    cout<<"enter the test cases";
    cin>>t;
    while(t--)
    {
        int n, m;
        cout << "Enter the size of array 1: ";
        cin >> n;
        cout << "Enter the size of array 2: ";
        cin >> m;

        vector<int> nums1(n);
        vector<int> nums2(m);

        cout << "Enter array 1 elements: ";
        for(int i = 0; i < n; i++)
        {
            cin >> nums1[i];
        }

        cout << "Enter array 2 elements: ";
        for(int i = 0; i < m; i++)
        {
            cin >> nums2[i];
        }

        vector<int> result = obj.intersection(nums1,nums2);

        cout << "Intersection Array: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
