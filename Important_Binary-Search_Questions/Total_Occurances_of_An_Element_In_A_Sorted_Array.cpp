#include<bits/stdtr1c++.h>
using namespace std;

int Left_Occurances(int arr[], int n, int s)
{
  int left=0;
  int right= n-1;
  int ans=-1;
  
  while(left<=right)
  {
    int mid = (right+left)/2;

    if(arr[mid]==s)
    {
        ans=mid;
       
        right=mid-1;
        
    }

    else if (arr[mid]>s)
    {
        right=mid-1;   
    }
    else //arr[mid]<s
    {    
        left = mid+1;    
    }
   }
   cout<<endl<<"Ans for the left side: "<<ans<<endl;
   return ans;

}
int Right_Occurances(int arr[], int n, int s)
{
   int left=0;
  int right= n-1;
  int ans=-1;
  
  while(left<=right)
  {
    int mid = (right+left)/2;

    if(arr[mid]==s)
    {
        ans=mid;
       
        left=mid+1;
        
    }

    else if (arr[mid]>s)
    {
        right=mid-1;   
    }
    else //arr[mid]<s
    {    
        left = mid+1;    
    }
   }
   cout<<"Ans for the right side: "<<ans<<endl;
   return ans;
}

int Total_occurance (int arr[],int n, int s)
{
    int left_occur_value= Left_Occurances(arr,n, s);
    cout<<"In total_occur loop- left_occur value attained is "<<left_occur_value<<endl<<endl;
    int right_occur_value= Right_Occurances(arr,n, s);
    cout<<"In total_occur loop- right_occur value attained is "<<right_occur_value<<endl<<endl;
    int result_total_occurance= (right_occur_value - left_occur_value) + 1;

    return result_total_occurance;

}


int main()
{
    int n,search;
    n=21;
    search=3;
    int arr[21] ={1,1,2,2,2,3,3,3,3,3,3,3,4,4,4,4,5,6,7,7,7};
    int occurance = Total_occurance (arr,n,search);
    cout<<"----Total_Occurances: "<<occurance<<"----";
    return 0;

}
