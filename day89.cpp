class Solution {
public:
    bool wordPattern(string p, string s) {
      map<char,string> mp;
      int j=0;
      s.push_back(' ');
      string currStr="";
      set<char> st1;
      set<string> st2;

      for(auto ch:p) st1.insert(ch); 

      for(int i=0;i<s.length();i++){
          if(j==p.length()) return false;

          if(s[i]==' '){ 
            if(mp.find(p[j])==mp.end())
              mp[p[j]]=currStr;

            else if(mp[p[j]]!=currStr)
              return false;

            st2.insert(currStr); 
            currStr.clear();
            j++;  
          }
          else
            currStr.push_back(s[i]);
       }

       return size(st1)==size(st2);
  }
};