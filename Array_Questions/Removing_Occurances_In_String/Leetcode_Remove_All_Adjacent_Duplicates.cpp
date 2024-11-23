/*Input: s = "azxxzy"
Output: "ay"
Input: s = "aaaa"
Output: " "
Input: s = "aazbbby"
Output: "zby"
*/

#include <iostream>
using namespace std;

string remove_adjacent_dupliactes(string s)
{
    int i=0;
    while( s.length() !=0 && i<s.length())
    {
        if(s[i]==s[i+1])
        {
            s.erase(i,2);
            
           //cout<<i;
            if(i>0) 
            /* if string: aazbby --> both a's deleted so without this loop 
            i-- will give -1 which is wrong as with 0th index element deleted 
            it needs to remain at the 0th  position for further compare to occur. */
            {
                i--;
            }
            
        }

        else
        {
            i++;
        }
       
    }
    return s;

}


int main()
{
    string sentence, part;

    cout<<" Enter the string: ";
    getline(cin,sentence);


    string result = remove_adjacent_dupliactes(sentence);

    cout<<"The result ater removing the substring: "<<result;

    return 0;


}

/*
QUESTION: 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

*/

