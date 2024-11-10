// Add to Array Form_of_Integer_Leetcode: 
// Example: 9 8 5 + 33(int) = 1 0 1 8

#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

void PrintArray(vector<int> result)
{
    cout<<"\t----SOLUTION----\t";
    cout<<endl;

    cout<<"\nAdd to Array form of Integer: ";

    for(int k=0; k<result.size(); k++)
    {
        cout<<result[k]<<" ";
    }
    cout<<endl;
}

vector<int> Reverse(vector<int> ans)
{
    int s=0;
    int e= ans.size() -1;

    while(s<=e)
    {
        swap(ans[s],ans[e]);
        s++;
        e--;
    }
    return ans;
}
    
vector<int> addToArrayForm(vector<int>& num, int k) 
{
    /* we have 3 cases 
	case 1: when array is more in size than integer value
    Case 2: when integer value is more in size than array
	case 3: adjusting carry over at the end 
	
	Case 1: 9 8 5 + 33(int) = 1 0 1 8
	Case 2: 2 7 4 + 1824(int) = 2 0 9 8
	Case 3: 9 9 9 + 111(int) = (1) 1 1 0   the () part is extra carry over part */

    int n= num.size();
    int i=n-1;
    int current_no,modified_no;
    int carry =0;
    vector<int> ans;

    while(i>=0 && k>0)
    {
        current_no = k; // current_no=1824 
        k = k/10;// k= 182
        modified_no=k * 10; // modified= 184* 10 = 1820
        current_no = current_no - modified_no;// current_no = 1824- 1820 = 4

        int sum = num[i]+ current_no + carry; // 4 + 4(int) + 0 =8
        carry = sum/10; // 8/10 =0;
        sum = sum%10; //8%10 = 8 --> remainder

        ans.push_back(sum);
        i--;
    }

    //case 1: when array has more elments than integer: 9 8 5 + 33(int) = 1 0 1 8

    while(i>=0)
    {
        int sum = num[i]+ carry; // 9 + (1) = 10
        carry = sum/10; //10/10 = 1
        sum = sum%10; // 10%10 =0

        ans.push_back(sum);
        i--;
    }

    //Case 2: when integer has more values than the array: 2 7 4 + 1824(int) = 2 0 9 8
    
    while(k>0)
    {
        current_no = k; //1
        k = k/10; // 1/10 =0
        modified_no= k*10; // 0*10 =0 
        current_no = current_no - modified_no;// 1-0 =1

        int sum = current_no + carry; // 9 + (1) = 10
        carry = sum/10; //10/10 = 1
        sum = sum%10; // 10%10 =0

        ans.push_back(sum);
    }

    // case 3: Adjusting carry in the end --> 9 9 9 + 111(int) = (1) 1 1 0  
    while(carry != 0)
    {
        int sum = carry; //1
        carry = sum/10; // 1/10 =0
        sum = sum%10; // 1%10 = 1--> Remainder

        ans.push_back(sum);

    }

    // return ans; 
   /* --> pushback is done from the end to start so the result will be printed backwards 
   1 2 3 4 + 456(int) = 1 6 9 0  while push back: 0 9 6 1*/

    return Reverse(ans);

}

int main()
{
    int n;

    cout<<endl<<"Enter the size of Array: ";
    cin>>n;

    vector<int>a(n);
    cout<<endl;
    
    cout<<"Enter the Elements of Array: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<endl;

    int k;

    cout<<"Enter the Second Number in for of Integer Value: ";
    cin>>k;

    vector<int> Result = addToArrayForm(a,k);
    cout<<endl;

    PrintArray(Result);

    return 0;
}