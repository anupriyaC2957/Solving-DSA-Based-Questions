/*  
--> Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

--> Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

--> Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string. */


#include<iostream>
#include<vector>
using namespace std;

string reverseWords(string &s)
{
    int n = s.length()-1;

    //PART 1: skiping the spaces in the back of string s: _ _ Happy_ _ _Birthday_ _ --> _ _ Happy_ _ _Birthday

    while(s[n]==' ')
    {
        n--;
    }

    string newstr;

    int start= n;
    int end = n;

    //PART 2: pushback elements one after the other: newstr--> Birthday_

    while(start>=0)
    {
        while(start>=0 && s[start] != ' ')
        {
            start --;
        }

       int temp = start+1;

        while(temp<=end)
        {
            newstr.push_back(s[temp]);
            temp++;

        }
        
        newstr.push_back(' ');

    //PART 3: Spaces in between to be removed s: --> _ _ Happy_ _ _Birthday --> _ _ Happy_Birthday
    // str--> Birthday_Happy  (To be result)

        end= start -1;

        while(end>=0 && s[end]==' ') // skipping the ahead spaces
        {
            end--;
        }

        //as soon as not space received
    
        start = end;

    } // end of while main loop

    //PART 4: Result of all this would lead to newstr: --> Happy_Birthday_

    // Purpose is to remove out the last gap

    while( !newstr.empty() && newstr.back() ==' ')
    {
        newstr.pop_back();
    }

    return newstr;
}

int main() {
    string sentence;
    cout<<endl<<"Enter the string sentence: ";
    getline(cin, sentence); // Read the entire line


    string result = reverseWords(sentence);

    cout << "SOLUTION: ";
    for (int i=0; i<result.length(); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}