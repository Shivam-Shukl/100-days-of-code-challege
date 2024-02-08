class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
     vector<int>& nums2, int k) {
         vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
                int sum=nums1[i]+nums2[0];
                q.push({sum,{i,0}});
            
        }
        while(!q.empty() && k--){
            auto it=q.top();
            int a=it.second.first;
            int b=it.second.second;
            q.pop();
            ans.push_back({nums1[a],nums2[b]});
            if(b!=m-1){
                q.push({nums1[a]+nums2[b+1],{a,b+1}});
            }
        }
        return ans;
    }
};