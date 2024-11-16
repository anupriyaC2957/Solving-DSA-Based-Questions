/* 
Sample input 1:
2
when all else fails reboot
java is to javascript what a car is to carpet

Sample output 1:
reboot fails else all when
carpet to is car a what javascript to is java

Explanation of sample input 1:
Test Case 1:
‘STR’ = “when all else fails reboot”
The reverse order of words in ‘STR’ is: “reboot fails else all when”.

Test Case 2:
‘STR’ = “java is to javascript what a car is to carpet”
The reverse order of words in ‘STR’ is: “carpet to is car a what javascript to is java”.

Sample input 2:
2
no code has zero defects
whitespace is never white

Sample output 2:
defects zero has code no
white never is whitespace
*/
#include<iostream>
#include<vector>
using namespace std;

string Reversewords(string &s)
{
    int n = s.length()-1;
    //cout<<"start: "<<s[start]<<" "<<"  end: "<<s[end]<<endl;
    int temp;

    string newstr;


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
            //cout<<"start: "<<start<<"temp:"<<temp;
            end = start;
        }

    }
    //cout<<"start: "<<start;
    //newstr.push_back(' ');

    while(start<=end)
    {
        newstr.push_back(s[start]);
        start ++;

    }

    return newstr;
    
}

int main() {
    string sentence;
    cout << "Enter the string sentence: ";
    getline(cin, sentence); // Read the entire line


    string result= Reversewords(sentence);

    cout << "SOLUTION: ";
    for (int i=0; i<result.length(); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
