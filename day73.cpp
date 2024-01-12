class Solution 
{
public:
    void solve(vector<int>&v,int n,int k,map<int,int>&dp,int &maxi)
    {
        int count=0; // To count the total number of elements that can be transformed to that particular element
        auto it=dp.lower_bound(n);
        if(it==dp.end() || it->first>n)
        {
            it--;
        }
        else if(it->first==n && it==dp.begin())
        {
            count+=it->second;
            if(count>maxi)
            {
                maxi=count;
            }
            return;
        }
        else if(it->first==n)
        {
            count+=it->second;
            it--;
        }
        while(k && it!=dp.begin())
        {
            if((long long)it->second*(long long)(n-it->first)<=k)
            {
                k-=((long long)it->second*(long long)(n-it->first));
                count+=it->second;
            }
            else
            {
                count+=k/(n-it->first);
                k=0;
            }
            it--;
        }
        if(it==dp.begin())
        {
            if((long long)it->second*(long long)(n-it->first)<=k)
            {
                k-=((long long)it->second*(long long)(n-it->first));
                count+=it->second;
            }
            else
            {
                count+=k/(n-it->first);
                k=0;
            }
        }
        if(count>maxi)
        {
            maxi=count;
        }
    }
    int maxFrequency(vector<int>&v, int k) 
    {
        map<int,int>dp;
        for(int i=0;i<v.size();i++)
        {
            dp[v[i]]++;
        }
        int low=1,high=1e9;
        int ans=v.front();
        int maxi=1;
        for(auto &it:dp)
        {
            solve(v,it.first,k,dp,maxi);
        }
        return maxi;
    }
};