#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

void PrintArray(vector<int> result)
{
    cout<<"\t----SOLUTION----\t";
    cout<<endl;

    cout<<"\nThe Sum of Two Array is: ";

    for(int k=0; k<result.size(); k++)
    {
        cout<<result[k]<<" ";
    }
    cout<<endl;
}

vector<int> Reverse(vector<int> ans)
{
    int s=0;
    int e= ans.size()-1;

    while(s<=e)
    {
        swap(ans[s], ans[e]);
        s++;
        e--;
    }
    return ans;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) 
{
    /* we have 3 cases 
	case 1: when array1 is more in size than array two 
	case 2: when array2 is more than array 1
	case 3: adjusting carry over at the end 
	
	Case 1: 1 2 3 4 + 4 5 6 = 1 6 9 0 
	Case 2: 6 + 1 2 3 4 = 1 2 4 0
	Case 3: 9 9 9 + 1 1 1 = (1) 1 1 0   the () part is extra carry over part */

    int i = n-1;
    int j= m-1;
    int carry = 0;
    vector<int> ans;

    //Common Case Senerio

    // Why working with 10 ? 
    /* Answer: The sum of two individula pair of numbers would always lie between 0-9 
    and any number %10 would range from giving results from 0-9
    so reminder need to be within 0-9 value */

    while(i>=0 && j>=0)
    {
        int sum = a[i]+ b[j] + carry; // 6+4 --> 10+0 = 10 || 3+5+(1)= 9 -->(1) is the carry over from previous stage
        carry = sum/10; // 10/10 = 1 || 9/10 = 0 --> quotient
        sum = sum % 10; // 10 % 10 = 0 || 9 % 10 = 9 --> Remainder

        ans.push_back(sum);
        i--; // To move to the next element in array 1 from back
        j--; // To move the the next element in array 2 from back
    }

    //CASE 1: Length of Array 1 is more than Array 2
    // There are no elements left in array 2 to add further but we still do have the carry over from the previous stage
    while(i>=0)
    {
        int sum = a[i]+ carry;// 9+(1) = 10 || 2+4 = 6
        carry= sum/ 10; // 10/10 = 1 || 6/10 = 0 
        sum = sum % 10; // 10%10 = 0 || 6 % 10 = 6 --> Remainder

        ans.push_back(sum);
        i--;
    }
    
    //CASE 2: Length of Array 2 is more than Array 1
    // There are no elements left in array 1 to add further but we still do have the carry over from the previous stage

    while(j>=0)
    {
        int sum = b[j]+ carry;// 3+(1) = 4 
        carry = sum/10; // 4/10= 0 --> carry over--> Quotient
        sum = sum%10; // 4%10= 4 --> Leftover --> Remainder

        ans.push_back(sum);

        j--;

    }

    //CASE 3: carry over left over: 9 9 9 + 1 1 1 =  (1) 1 1 0 --> last 1 is due to carry over no number is there to add to it

    while(carry != 0)
    {
        int sum = carry; // 1
        carry = sum/10; // 1/10 =0 thius is to reset the value of carry for further stages
        sum = sum%10; //1%10 = 1

        ans.push_back(sum);

    }

   // return ans; 
   /* --> pushback is done from the end to start so the result will be printed backwards 
   1 2 3 4 + 4 5 6 = 1 6 9 0  while push back: 0 9 6 1*/

   return Reverse(ans);
}

int main()
{
    int n, m;

    cout<<endl<<"Enter the size of Array 1: ";
    cin>>n;

    cout<<"Enter the size of Array 2: ";
    cin>>m;

    vector<int>a(n);
    vector<int>b(m);

    cout<<endl;

    cout<<"Enter the Elements of Array 1: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the Elements of Array 2: ";
    for(int j=0; j<m; j++)
    {
        cin>>b[j];
    }

    cout<<endl;

    vector<int> Result = findArraySum(a,n,b,m);

    PrintArray(Result);

    return 0;
}