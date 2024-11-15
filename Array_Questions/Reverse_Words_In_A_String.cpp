// My name is Love
// Solution: yM eman si evoL

#include<iostream>
#include<vector>
using namespace std;

void Reversewords(vector<char> &s)
{
    int start=0;
    int end=0;
    // int count=0;
    int temp;

    while(end < s.size())   // vector char do not have null pointer at the end
    {

        if (s[end] != ' ')
        {
            //count ++;
            //cout<<endl<<"step: "<<count<<" before modified end value: "<<end<<"-->current element: "<<s[end]<<endl;
            end ++;   
            //cout<<endl<<"step: "<<count<<" after modified end value: "<<end<<"-->current element: "<<s[end]<<endl;
            
        }

        else
        {
        temp=end;
        end= end-1;

        while(start<=end)
        {
            swap(s[start], s[end]);
            start++;
            end--;

        }

        start = temp+1;  
        end= start;
        //cout<<endl<<"step: "<<count++<<" start value: "<<start<<endl;
        //cout<<endl<<"step: "<<count++<<" end value: "<<end<<endl;
        
        }
          
    }
    end= end-1;

    while(start<=end)
    {
        swap(s[start], s[end]);
        start++;
        end--;

    }
}

int main() {
    string sentence;
    cout << "Enter the string sentence: ";
    getline(cin, sentence); // Read the entire line

    // Convert to vector<char>
    vector<char> s(sentence.begin(), sentence.end());

    Reversewords(s);

    cout << "SOLUTION: ";
    for (int i=0; i<s.size(); i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}