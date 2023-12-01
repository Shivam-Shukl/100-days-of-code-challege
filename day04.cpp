class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n) ;
        for(int i=0;i<n;i++)
        {
            arr[i]=nums[i];
        }
        std::sort(arr.begin(), arr.begin() + n);

        int i=0,j=1;
        while(i<n-1 && j<n)
        {
            if(arr[i]==arr[j])
            return arr[i];
            else
            i++,j++;
        }
        return 0;
    }
};
