// Situation where there are no case sensitive
// and to ignore special characters 
// value taken in form of string
// alphanumeric means --> only numeric and character values no special characters allowed

#include<iostream>

using namespace std;


int length_of_string(string str)
{
    int count=0;

    for(int i=0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;

}

string reverse_the_string(string str)
{
    int s=0;
    int e= length_of_string(str);

    while(s<=e)
    {

        while(s<e && ! isalnum(str[s]))  // leaves the special characters in its respective position
        {
            s++;
        }
        while(s<e && !isalnum(str[e]))
        {
            e--;
        }

        swap(str[s], str[e]);
        s++;
        e--;
    }
    return str;
}

char isLower(char ch)
{
    if((ch>='a' && ch<='z')|| (ch>='0' && ch<='9'))
    {
        return ch;
    }
    else
    {
        ch = ch- 'A' + 'a';
        return ch;
    }
}

bool isPalindrome(string str)
{
    int s=0;
    int e= length_of_string(str);

    while(s<=e)
    {
        while(s<e && ! isalnum(str[s]))  // if not alphanumeric numbers then skip
        {
            s++;
        }
        while(s<e && !isalnum(str[e]))
        {
            e--;
        }
        if(isLower(str[s]) != isLower(str[e]))
        {
            return false;
        }

        else
        {
            s++;
            e--;
        }
    }
    return true;

}

int main()
{
    string test1= "A man, a plan, a canal: Panama";
    string test2= "race a car";
    string test3= " ";
    string test4= "  ";
    string test5= "No 'X' in Nixon";
    string test6= "564@123#";

    cout<<endl<<"\t--CHECK IF PALINDROME--\t"<<endl;

    cout<<endl<<"The Test 1: \" A man, a plan, a canal: Panama \" ";

    cout<<endl<<"Reverse of Test 1: "<<reverse_the_string(test1);
    
    cout<<" --> is it Palindrome: "<<isPalindrome(test1)<<endl;

    
    cout<<endl<<"The Test 2: \" race a car \" ";

    cout<<endl<<"Reverse of Test 2: "<<reverse_the_string(test2);
    
    cout<<" --> is it Palindrome: "<<isPalindrome(test2)<<endl;


    cout<<endl<<"The Test 3: \" \" ";

    cout<<endl<<"Reverse of Test 3: "<<reverse_the_string(test3);
    
    cout<<" --> is it Palindrome: "<<isPalindrome(test3)<<endl;


    cout<<endl<<"The Test 4: \"  \" ";

    cout<<endl<<"Reverse of Test 4: "<<reverse_the_string(test4);
    
    cout<<" --> is it Palindrome: "<<isPalindrome(test4)<<endl;


    cout<<endl<<"The Test 5: \" No 'X' in Nixon \" ";

    cout<<endl<<"Reverse of Test 5: "<<reverse_the_string(test5);
    
    cout<<" --> is it Palindrome: "<<isPalindrome(test5)<<endl;

    cout<<endl<<"The Test 6: \" 564@123# \" ";

    cout<<endl<<"Reverse of Test 6: "<<reverse_the_string(test6);
    
    cout<<" --> is it Palindrome: "<<isPalindrome(test6)<<endl;
    
    return 0;
}
