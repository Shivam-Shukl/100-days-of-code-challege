#include<unordered_map>
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxCnt =0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            maxCnt =max(maxCnt,m[nums[i]]);
        }    
        int ans=0;
        for(auto x : m)
        {
            if(x.second == maxCnt )
            ans=ans+x.second;
        }
        return ans;
    }
};