/*Purpose of the program is to replace ' ' with "@40"
Sentence - My name is anupriya 
Output: My@40name@40is@40anupriya*/

#include<iostream>
using namespace std;

string replaceSpaces(string &str) 
{
    //Approach 1: with additional space

   /*
    string temp = "";

    for(int i=0;i<str.length(); i++)
    {
        if(str[i]==' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
           
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp; 
    */

   // Approach 2: Without additional space

   string replaced_value = "@40";

   for(int i=0;i<str.length(); i++)
   {
        if(str[i] == ' ')
        {
            str.replace(i,1,replaced_value);
            // replace (index at which to be replaced at, length of the original value, replaced value)
        }
           
   }
   return str;
}

int main()
{
    string sentence;

    cout<<"Enter the sentence: ";
    getline(cin,sentence);

    string result = replaceSpaces(sentence);

    cout<<"Output: "<<result;

    return 0;
}