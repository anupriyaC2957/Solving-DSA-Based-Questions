/* Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.

nums1=[7,9,9] nums2 =[6,7,7,7,9,9,9]
result=[7,9,9]
*/
# include<bits/stdtr1c++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
        unordered_map<int, int> ans1;
        unordered_map<int, int> ans2;
        vector<int> result;
        
        
        for(int i = 0; i < n; i++) {
            ans1[nums1[i]]++;
        }
        
    
        for(int i = 0; i < m; i++) {
            ans2[nums2[i]]++;
        }
        
        for(auto it : ans1) {
            int count1= it.second;
            if(ans2.find(it.first) != ans2.end()) {
                int count2 = ans2[it.first]; 

                
                int minCount = min(count1, count2);
                for(int i = 0; i < minCount; i++) {
                    result.push_back(it.first); 
                }
            }
        }
		
	   sort(result.begin(), result.end());
        
    return result;
};

int main()
{
    int t;
    cout << "Enter the number of Test cases: ";
    cin >> t;
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

        vector<int> result = findArrayIntersection(nums1, n, nums2, m);

        cout << "Intersection Array: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}




