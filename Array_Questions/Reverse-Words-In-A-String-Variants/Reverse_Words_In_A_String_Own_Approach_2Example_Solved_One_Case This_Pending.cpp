/* 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

these two cases are working via this code the problem is occuring with the third case


*/
#include<iostream>
#include<vector>
using namespace std;

void Reversewords(string &s)
{
    int n = s.length()-1;
    //cout<<"start: "<<s[start]<<" "<<"  end: "<<s[end]<<endl;
    int temp;

    string newstr;

    while( n>=0 && !isalnum(s[n]))
    {
        n--;
    }

    int start = n;
    int end = n;


    while(start>0)
    {
        if(s[start] != ' ')
        {
            start --;
        }
        else
        {

            temp = start;
            start = start +1;

            while(start<=end)
            {
                newstr.push_back(s[start]);
                start ++;
            }

            newstr.push_back(' ');

            start = temp -1;
            cout<<"start: "<<start<<"temp:"<<temp;
            end = start;
        }

    }
    //cout<<"start: "<<start;
    //newstr.push_back(' ');

    int i=0;

    while( !isalnum(s[i]) && start<n)
    {
        i++;
    }

    start = i;

    while(start<=end)
    {
        newstr.push_back(s[start]);
        start ++;

    }

    // Remove trailing space if present
        if (!newstr.empty() && newstr.back() == ' ') {
            newstr.pop_back();
        }

    s= newstr;
    
}

int main() {
    string sentence;
    cout << "Enter the string sentence: ";
    getline(cin, sentence); // Read the entire line


    Reversewords(sentence);

    cout << "SOLUTION: ";
    for (int i=0; i<sentence.length(); i++) {
        cout << sentence[i];
    }
    cout << endl;

    return 0;
}