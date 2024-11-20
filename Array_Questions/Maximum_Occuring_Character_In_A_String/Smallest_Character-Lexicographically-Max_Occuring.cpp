 /*sentence: test --> output: t 
 sentence: sampletest --> output: e
 sentence: aabbb --> output: b
 sentence: yyxxxy --> output: x
 sentence: xxyyyx --> output: x
 sentence: xxxyyy --> output: x
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char highestOccurringChar(char input[]) {
   
    unordered_map <char,int> ans;
    char finals;
    int max= -1;
    int n = strlen(input);

    for(int i=0; i<n; i++)
    {
        ans[input[i]]++;   
    }

    for(auto it : ans )
    {
        if(max< it.second)
        {
            max= it.second;
            finals= it.first;
        }

        else if (max == it.second)
        {
            if(finals > it.first)
            {
                finals = it.first;
            }
        }
    }

    return finals;

}


int main()
{
    string sentence;

    cout<<" Enter the sentence: ";
    getline(cin, sentence);

    int n = sentence.length();
    //cout<<" Value of n is: "<<n<<endl;
    //cout<<" Value of n+1 is:"<<n+1<<endl;

    char s[n+1];

    for(int i=0;i<n+1;i++)
    {
        s[i]= sentence[i];
    }

    char result = highestOccurringChar(s);

    cout<<" The maximum occuring character is: "<<result;

    return 0;
}