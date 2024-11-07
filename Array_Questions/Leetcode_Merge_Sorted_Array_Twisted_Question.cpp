#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int i= m-1;
    int j = n-1;
    int k= (m+n)-1;

    while(i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
        {
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k]= nums2[j];
            j--;
            k--;
        }
    }

    while(j>=0)
    {
        nums1[k]= nums2[j];
        j--;
        k--;
    }

    while(i>=0) //Redundant Step
    {
        nums1[k]= nums1[i];
        i--;
        k--;
    }
    
 
}

int main()
{
    int m, n;

    cout<<endl;
    cout<<"Number of Elements in Array 1: ";
    cin>>m;
    cout<<"Number of Elements in Array 2: ";
    cin>>n;

    int t=m+n;

    cout<<endl;

    cout<<"The Total Size of Array 1: "<<t<<endl;
    cout<<"The Size of Array 2 would be same as Number of Elements: "<<n<<endl;
    

    vector<int>nums1(t);
    cout<<endl;
    cout<<"---NOTE: End 0's are place for merge elements Hence, should be Ignored---"<<endl;

    cout<<endl<<"Enter the Array 1: ";
    for(int i=0;i<t;i++)
    {
        cin>>nums1[i];
    }


    vector<int>nums2(n);
    cout<<"Enter the Array 2: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    
    cout<<endl<<"The Merged Array is: ";
    merge(nums1, m, nums2, n);

    for(int i=0; i<t;i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl; 
    
    
    return 0;
    
}


