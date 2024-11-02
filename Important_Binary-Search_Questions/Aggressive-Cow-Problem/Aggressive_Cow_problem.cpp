
#include<iostream>
#include<vector>
#include<algorithm>
//#include<climits>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, vector<pair<int,int>>&cow_position)
{
    int cow_count = 1;
    int lastpos = stalls[0];
    int n= stalls.size();
    cow_position.push_back({0,lastpos}); //to store the first position


    for(int i=0;i<n;i++)
    {
        if(stalls[i]-lastpos >= mid)
        {
            cow_count++;
            lastpos= stalls[i];
            cow_position.push_back({i,lastpos});
            
            if(cow_count==k)
            {
                return true;
            }
            
        }

    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k, vector<pair<int,int>> &final_position)
//& will change the actual variable without & it will maintain copy within the local function which will not be reflected outside the func
{
    sort(stalls.begin(),stalls.end());

    int s=0;
    int n=stalls.size();
    int max=-1;
    int min= 1e9; //INT_MAX;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(max < stalls[i])
        {
            max=stalls[i];
        }
        if(min > stalls[i])
        {
            min=stalls[i];
        }
    }
    int e = max-min;
    int mid;
    while(s<=e)
    {
        mid= (s+e)/2;
        vector<pair<int,int>>cow_position;
        
        if(isPossible(stalls,k,mid,cow_position))
        {
            ans= mid;
            final_position = cow_position;
            s=mid+1; //as this time we need the largest one
        }

        else
        {
            e=mid-1;
        }
    }
    return ans;   
}

int main()
{
    int n,k;
    cout<<endl<<"Enter the Number of Cows: ";
    cin>>k;
    cout<<"Enter the Number of stalls: ";
    cin >>n;
    vector<int> stalls(n);
    cout<<"Enter the Dist for each stall: ";
    for(int i=0; i<n;i++)
        cin>>stalls[i];
    cout<<endl;
    vector<pair<int,int>>final_position;
    
    int result = aggressiveCows(stalls,k,final_position);
    cout<<"Minimum Distance Assigned Between The Stalls With Largest Distance as: "<<result<<endl;

    cout << "The stalls at which the cows are placed at: "<<endl;
    for (int i=0; i<final_position.size();i++) {
        cout<<" | " <<"Index: "<< final_position[i].first<<" | "<<" Distance: "<<final_position[i].second<<endl;
    }

    return 0;
}




/*Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows 
such that the minimum distance between any two of them is the maximum possible.

Print the maximum possible minimum distance.

Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. 
Here distance between cows is 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 4
0 3 4 7 10 9
Sample Output 1 :
3

Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. 
Here distance between cows are 3, 4 and 3 respectively.
Sample Input 2 :
5 2
4 2 1 3 6
Sample Output 2 :
5

Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?

Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.*/


