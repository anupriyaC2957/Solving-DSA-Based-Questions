#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>boards, int n, int k, int mid)
{
    int Lboards_count =0;
    int painter_count=1;

    for(int i=0;i<n;i++)
    {
        if(boards[i]+Lboards_count <= mid)
        {
            Lboards_count += boards[i];
        }
        else
        {
            painter_count++;
            if(painter_count > k ||boards[i]>mid)
            {
                return false;
            }
            Lboards_count=0;
            Lboards_count +=boards[i];

        }

    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    int ans=-1;
    int n= boards.size();
    for(int i=0;i<n;i++)
    {
        sum +=boards[i];
    }
    int e=sum;
    int mid;

    while(s<=e)
    {
        mid=(s+e)/2;

        if(isPossible(boards,n,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int n,k;
    cout<<"Enter the Number of Painters: ";
    cin>>k;
    cout<<"Enter the Number of Boards: ";
    cin >>n;
    vector<int> boards(n);
    cout<<"Enter the Length of each Board: ";
    for(int i=0; i<n;i++)
        cin>>boards[i];
    
    int result = findLargestMinDistance(boards,k);
    cout<<"Maximum number of boards assigned to a painter is Mimimum when it is: "<<result;

    return 0;
}