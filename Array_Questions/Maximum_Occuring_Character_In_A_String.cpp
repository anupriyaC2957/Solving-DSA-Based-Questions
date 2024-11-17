#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char maximum_occurance(char s [])
{
    unordered_map <char,int> ans;
    char finals;
    int max= -1;

    for(int i=0; i<strlen(s); i++)
    {
        ans[s[i]]++;
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

    char result = maximum_occurance(s);

    cout<<" The maximum occuring character is: "<<result;

    return 0;
}