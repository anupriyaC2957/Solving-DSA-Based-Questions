 /*sentence: test --> output: t 
 sentence: sampletest --> output: s
 sentence: aabbb --> output: b
 sentence: yyxxxy --> output: y
 sentence: xxyyyx --> output: x
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

    for(int i=0;i<n; i++)
    {
        char current = input[i];
        if(ans[current]> max)
        {
            max= ans[current];
            finals= input[i];
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
    //cout<<"value of n is: "<<n<<endl;
    //cout<<"Value of n+1 is:"<<n+1<<endl;

    char s[n+1];

    for(int i=0;i<n+1;i++)
    {
        s[i]= sentence[i];
    }

    char result = highestOccurringChar(s);

    cout<<" The maximum occuring character is: "<<result;

    return 0;
}
