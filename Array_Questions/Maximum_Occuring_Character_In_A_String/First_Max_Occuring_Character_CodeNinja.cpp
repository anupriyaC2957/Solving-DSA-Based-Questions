/*sentence: test --> output: t 
 sentence: sampletest --> output: s
 //sentence: SampLETest --> output: S
 sentence: aabbb --> output: b
 sentence: yyxxxy --> output: y
 sentence: xxyyyx --> output: x
 sentence: xxxyyy --> output: x 
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* char ToLower(char ch)  // non-Case-Sensitive
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
} */

char highestOccurringChar(char input[]) {
   
    unordered_map <char,int> ans; // unordered map --> iteration order is not fixed --> change can occur--> do not depend on the iteration order
    char finals;
    //char ch;
    int max= -1;
    int n = strlen(input);

    for(int i=0; i<n; i++)
    {
        //ch = ToLower(input[i]);
        // ans[ch]++;
        ans[input[i]]++;
    }

    for(int i=0;i<n; i++)
    {
        //char current = ToLower(input[i]);
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
    cout<<" Value of n is: "<<n<<endl;
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
