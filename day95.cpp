class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() == t.length())
        {
            unordered_map<char,bool> chk;
            unordered_map<char,char> map;
            for(int i=0;i<s.length();i++)
            {
                char ch = t[i];
                char ch1 = s[i];
                if(!chk[ch1])
                {
                    map[ch]= s[i];
                    chk[s[i]]= true;
                }
                
            }
            for(int i=0;i<t.length();i++)
            {
                char ch = t[i];
                t[i]= map[ch];

            }
            if(s == t)
            {
                return true ;
            }
            else 
            {
                false;
            }
        }
        else 
        {
            false;
        }
        return false;
    }
};