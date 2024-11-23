/*Input: s = "azxxzy"
Output: "azxzy"
Input: s = "aaaa"
Output: "a"
Input: s = "aazbbby"
Output: "azby"
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
            s.erase(i+1,1);
            
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

Test Case 1:

Given ‘str' = ”abcde”
There are no duplicates in the input string so the final string will be “abcde” 

Test Case 2:

Given ‘str’ = “aaaaa”
After removing adjacent duplicates string will be “a”

*/

