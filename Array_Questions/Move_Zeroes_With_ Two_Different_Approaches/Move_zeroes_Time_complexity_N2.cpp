#include<bits/stdtr1c++.h>
using namespace std;

void MoveZeroes(int arr[], int n)
{
    int i=0;
    int j=n-1;

    while(i<=j)
    {
        if(arr[j]==0)
        {
            j--;
        }
        else if(arr[i] !=0)
        {
            i++;
        }
        else if( arr[i] ==0 && arr[j] !=0)
        {
            /*int temp;
            temp =i;
    
            while(i<=j)
            {
                arr[i]=arr[i+1];
                i++;
            }
            arr[i-1]=0;

            i=temp;*/

            for(int k=i; k<j;k++)
            {
                arr[k]=arr[k+1];
            }
            arr[j]=0;

            
        }
    }
  
}

int main()
{
    int n=9;
    int arr[9]= {1,0,2,3,4,0,0,5,0};
    MoveZeroes(arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
