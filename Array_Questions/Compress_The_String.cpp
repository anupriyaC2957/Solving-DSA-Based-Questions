//Leetcode and Code Ninja

/*chars =
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output
["a","b","1","2"]
*/
#include <iostream> 
using namespace std;

	string compressTheString(string &s)
	{
        int i=0;
        int ansindex =0;
        int n =  s.size();

        while(i<n)
        {
            int j = i+1;

            while(j<n && s[i]==s[j])
            {
                j++;

            }
            s[ansindex]= s[i];
            ansindex++;

            int count = j-i;

            if(count>1)
            {
                string cnt = to_string(count);// converting int to string

                for(char ch : cnt)
                {
                    s[ansindex] = ch;
                    ansindex++;
                }

            }
            i=j;
        }
		s.erase(ansindex);
        /* length: return ansindex; //no need to erase*/
		return s;    	
    }

    int main()
    {
        string s;
        cout<<" Enter the String: ";
        getline(cin,s);

        string result = compressTheString(s);
        cout<<"The Compressed String is: ";
        cout<<result;

        return 0;
    }

/* LOGIC : ansindex: 0
                 [ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ,10 ,11 ,12, 13]
    Input: s =   ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
                 [ i , j ] //ansindex: 1, count 1, updated: i=1 and j = 2;
                 [ a ,"b","b","b","b","b","b","b","b","b","b","b","b"] 
                     [ i , j ] 
                     [ i ,     j ]
                     [ i ,         j ]
                     [ i ,            j ]
                     [ i ,                j ]
                             ....... // becos s[i]= s[j]
                     [ i ,                                         j ]  
                     [ i ,                                             j ] // last j++; which exceeds j<n value
                     
                     [ a , b ,"b","b","b","b","b","b","b","b","b","b","b"]
                     //ansindex: 2, count (13-1)=12, updated: i=1 and j = 13;

                     count >1 --> double digit --> 12 --> change string--> one by one enter
                     
                     [ a , b , 1 ,"b","b","b","b","b","b","b","b","b","b"] --> ansindex = 3
                     again....
                     [ a , b , 1 , 2,"b","b","b","b","b","b","b","b","b"] --> ansindex = 4
*/