class Solution {
public:
    string reverse(string str)
    {
        int s=0;
        int e= str.length()-1;
        while(s<e)
        {
            swap(str[s],str[e]);
            s++;
            e--;
        }
        return str;
    }
    int lengthOfLastWord(string s) {
        string str = reverse(s);
        int count =0;
        int i=0;
        while(str[i]==' ')
        {
            i++;
        }
        while(str[i] != ' ')
        {
            count++;
            i++;
            if(str[i]=='\0')
                break;
        }
        return count;   
    }
};
