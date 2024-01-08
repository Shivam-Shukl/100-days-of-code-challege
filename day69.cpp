class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v;
        for(auto i : nums1)
        {
            v.push_back(i);
        }
        for(auto j : nums2)
        {
            v.push_back(j);
        }

        sort(v.begin(),v.end());

        int n = v.size();
        if (n%2 == 0)
        {
            //even
            int mid = n/2 ;
            double ans = v[mid-1] + v[mid];
            ans = ans /2.0;
            return ans;
        }
        else
        {
            //odd
            int mid = n/2;
            double ans = v[mid];
            
            return ans;
        }
        return 0.0;
    }
};