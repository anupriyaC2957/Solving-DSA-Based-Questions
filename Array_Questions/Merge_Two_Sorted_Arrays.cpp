#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n, vector<int> &arr3) {
    
    int i=0, j=0; //,k=0;
    while(i<m && j<n)
    {
        if(nums1[i]<=nums2[j])
        {
            //arr3[k]=nums1[i];
            arr3.push_back(nums1[i]);
            i++;
           // k++;
        }
        else
        {
            //arr3[k]=nums2[j];
            arr3.push_back(nums2[j]);
            j++;
            //k++;
        }
    }

    while(i<m )
    {
        //arr3[k]=nums1[i];
        arr3.push_back(nums1[i]);
        i++;
        //k++;
        
        
    }
        
    while(j<n )
    {
        //arr3[k]=nums2[j];
        arr3.push_back(nums2[j]);
        j++;
        //k++;
        
        
    } 
 
}

int main()
{
    int m, n;
    cout<<"Size of Array 1: ";
    cin>>m;
    vector<int>nums1(m);
    cout<<"Enter the Array 1: ";
    for(int i=0;i<m;i++)
    {
        cin>>nums1[i];
    }
    cout<<"Size of Array 2: ";
    cin>>n;
    vector<int>nums2(n);
    cout<<"Enter the Array 2: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    //int arr3[m+n];
    vector<int> arr3;
   

    cout<<"The Merged Array is: ";
    merge(nums1, m, nums2, n, arr3);

    for(int i=0; i<arr3.size();i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl; 
    
    
    return 0;
    
}


