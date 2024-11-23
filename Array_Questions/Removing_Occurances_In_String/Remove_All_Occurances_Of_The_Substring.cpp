/*
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
*/

#include <iostream>
using namespace std;

string removeOccurances(string s, string part)
{
    while(s.length() !=0 && s.find(part)< s.length())
    {
        s.erase(s.find(part), part.length());
        //s.find(element) ---> finds the element in s and stores the INDEX at which the element present
        // part.length()-->  length of the part substring so that (INDEX + length value) the specific part to erase
    }
    return s;

}


int main()
{
    string sentence, part;

    cout<<" Enter the string: ";
    getline(cin,sentence);

    cout<<" Enter the part(substring): ";
    getline(cin,part);

    string result = removeOccurances(sentence, part);

    cout<<"The result ater removing the substring: "<<result;

    return 0;


}

/*
QUESTION: 

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

*/

