#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int m, int k, int mid) {
    int adjflower_count = 0;
    int bouquet_count = 0;  

    for (int i = 0; i < arr.size(); i++) 
    {
        
        if (arr[i] <= mid) 
        {
            adjflower_count++;  
            
            
            if (adjflower_count == k) 
            {
                bouquet_count++; 
                adjflower_count = 0;  

                
                if (bouquet_count == m) 
                {
                    return true;
                }
            }
        } 
        
        else 
        {
            adjflower_count = 0; 
        }
    }

   
    return bouquet_count == m;
}

int minDays(vector<int>arr,int m , int k)
{
    int s=0;
    int n = arr.size();
    int max =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
            max =arr[i];
    }
    int e=max; 
    cout<<"e:"<<e;
    int mid;
    int ans=-1;

    while(s<=e)
    {
        mid= (s+e)/2;

        if(isPossible(arr,m,k,mid))
        {
            ans=mid;
            e=mid-1; //minimum value of acceptance 
        }
        else
        {
            s=mid+1; //value is too small hence move ahead
        }

    }
    return ans;
}

int main()
{
    int n,m,k;
    cout<<"Enter the Number of Bouquets: ";
    cin>>m;
    cout<<"Enter the Number of adjacent flowers: ";
    cin>>k;
    cout<<"Enter the Number of Flowers: ";
    cin >>n;
    vector<int> arr(n);
    cout<<"Enter the Number of days it takes the flower to bloom: ";
    for(int i=0; i<n;i++)
        cin>>arr[i];
    
    int result = minDays(arr,m,k);
    cout<<"Maximum number of days assigned is Mimimum when it is: "<<result;

    return 0;
}



