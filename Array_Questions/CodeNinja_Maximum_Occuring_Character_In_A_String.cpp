/*sentence: test --> output: t 
sentence: anupriya --> output: a
sentence: xxyyyx --> ouput: x
sentence: yyxxxy --> output: y */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//non case sensitive condition if needed
/*char isLower(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;  // Character is already lowercase
    } else {
        char temp = ch - 'A' + 'a';  // Convert uppercase to lowercase
        return temp;
    }
}*/

char highestOccurringChar(char input [])
{
    unordered_map <char,int> ans;
    char finals;
    int max= -1;
    
    for(int i=0; i<strlen(input); i++)
    {
        /*char LowerCase = isLower(input[i]);   //--> non case sensitive case
        ans[LowerCase]++; */
        ans[input[i]]++;
    }

    for(auto it: ans)
    {
        if (max<it.second)
        {
            max=it.second;
            finals= it.first;
        }
        //else if(max == it.second && it.first<finals)  ---> According to ASCII code which ever is the smallest -> print that
        else if (max == it.second) //--> which ever comes first print that
        {
            finals= it.first;
        }
    }
    return finals;
}

int main()
{
    string sentence;
    cout<<" Enter the sentence: ";
    getline(cin, sentence);
    
    int n = sentence.length()-1;
    char s[n];

    for(int i=0;i<n;i++)
    {
        s[i]= sentence[i];
    }

    char result = highestOccurringChar(s);
    cout<<" The maximum occuring character is: "<<result;

    return 0;
}
