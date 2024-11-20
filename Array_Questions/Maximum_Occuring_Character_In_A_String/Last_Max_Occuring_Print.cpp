 /*
 sentence: test --> output: t 
 sentence: sampletest --> output: t
 sentence: SampLETest --> output: t
 sentence: aabbb --> output: b
 sentence: yyxxxy --> output: y
 sentence: xxyyyx --> output: x
 sentence: xxxyyy --> output: y
 */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char ToLower(char ch)  // non-Case-Sensitive
{
    if(ch>='a' && ch<= 'z')
    {
        return ch;
    }
    else
    {
        char temp;
        temp = ch -'A'+'a';
        return temp;
    }
}

char highestOccurringChar(char input[]) {
   
    unordered_map <char,int> ans;
    char finals;
    char ch;
    int max= -1;
    int n = strlen(input);

    for(int i=n-1; i>=0; i--)
    {
        ch= ToLower(input[i]);
        ans[ch]++;   
    }

    for(int i=n-1;i>=0; i--)
    {
        char current = ToLower(input[i]);
       // cout<<"character: "<<current<<endl;
        if(ans[current]> max)
        {
            max= ans[current];
            //cout<<" max:  "<<max<<endl;
            finals= input[i];
            //cout<<" finals:  "<<finals<<endl;
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
    cout<<" Value of n+1 is:"<<n+1<<endl;

    char s[n+1];

    for(int i=0;i<n+1;i++)
    {
        s[i]= sentence[i];
    }

    char result = highestOccurringChar(s);

    cout<<" The maximum occuring character is: "<<result;

    return 0;
}
