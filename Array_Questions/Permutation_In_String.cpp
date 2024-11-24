/*Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

#include<iostream>
using namespace std;

class Solution
{
    private:
    bool checkequal(int count1[26], int count2[26])
    {
        for(int i=0;i<26; i++)
        {
            if(count1[i] != count2[i])  // if a single mismatch then return 0
            // it cannot be count1[i]== count2[i] becos --> if a single index match it will return 1 which is wrong
            {
                return 0;
            }
            
        }
        return 1; // after verifying all index value then if equal then return true
    }

    public:
    bool checkInclusion(string s1, string s2) 
    {
        // PART 1: s1 character stored in count1 --> and convert them into alphabet
        int count1[26]={0};

        for(int i=0;i<s1.length(); i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        /* Part 2: s2 0th to (window_size)th characters stored in count2
        (like if window_size =2 (length of s1) --> then 0th and 1st element stored) */

        int window_size= s1.length();
        int i=0;
        int count2[26]={0};

        while(i<window_size && i<s2.length()) 
        // if s1= "ab" and s2= "a" --> window_size=2 & i=0 
        // at i=1 without i<s2.length()--> out of bound condition will occur
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // Part 3: Compare count1( stores elements of s1) and count2(stores 0th to window_size characters of s2)

        if(checkequal(count1,count2))
        {
            return 1;
        }

        /* Part 4: loop into while --> for rest of the elements left in s2 such that 
        the upcoming index has +1 and the left behind index/ character gets -1 so that we can compare it ahead*/
        
        /*Input: s1 = "ab", s2 = "eidbaooo" */

        while(i<s2.length())
        {
            int index = s2[i] - 'a';
            count2[index]++;

            index = s2[i-window_size]-'a';  
            /* s2[i-window_size] --> stores left behind character --> i=3 and window size 2 --> 
            s2[3-2]=s[1]--> this is left behind so remove it 
            from counting by turning the 1 which was counted before to count 0*/
            count2[index]--;

            i++;

            /* Part 5: Compare count1( stores elements of s1) and count2( leftover characters in s2)*/

            if(checkequal(count1, count2))
            {
                return 1;
            }
        }

        return 0; // if all fails then return false
   
    }

};

int main()
{
    Solution obj;

    string s1, s2;

    cout<<"Enter String 1: ";
    getline(cin,s1);

    cout<<"Enter String 2: ";
    getline(cin,s2);

    bool result = obj.checkInclusion(s1,s2);

    cout<<"Does s2 contains one permutation of s1: ";

    cout<< (result ? "true": "false");

    return 0;
}

