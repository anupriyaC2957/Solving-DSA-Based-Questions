
/*sentence: test --> output: t 
 sentence: sampletest --> output: e
 sentence: SampLETest --> output: e
 sentence: aabbb --> output: b
 sentence: yyxxxy --> output: x
 sentence: xxyyyx --> output: y
 sentence: xxxyyy --> output: x 
 */ 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


char highestOccurringChar(char input[]) {
    
    int arr[26] ={0};

    for(int i=0; i<strlen(input);i++)
    {
        char current = input[i];
        int num;

        if(current>='a' && current<='z')
        {
            num = current -'a'; // numberic malue corresponding to the alphabet will be attained--> arr index value
        }
        else
        {
            num = current - 'A'; // be it A or a it's the same
        }
        arr[num]++; //count value stored in the value part of the array
    }

    int max= -1;
    int ans;

    for(int i=0; i<26; i++)
    {
        //if(max <=arr) //--> Last max occuring value 
        if(max<arr[i]) 
        //This will work iteratively which ever finishes the counting to be highest first accoprdingly it will print the ans
        {
            max= arr[i];
            ans= i;
        }   
    }
    char finalans = ans +'a';

    return finalans;

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