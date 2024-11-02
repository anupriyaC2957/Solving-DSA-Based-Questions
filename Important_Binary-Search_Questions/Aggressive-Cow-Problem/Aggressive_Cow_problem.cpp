
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
    // basically store the position and the distance in the final_position--> This is additional part !
    
    int result = aggressiveCows(stalls,k,final_position);
    cout<<"Minimum Distance Assigned Between The Stalls With Largest Distance as: "<<result<<endl;

    cout << "The stalls at which the cows are placed at: "<<endl;
    for (int i=0; i<final_position.size();i++) {
        cout<<" | " <<"Index: "<< final_position[i].first<<" | "<<" Distance: "<<final_position[i].second<<endl;
    }

    return 0;
}



