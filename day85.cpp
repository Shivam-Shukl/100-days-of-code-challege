class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
    
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=0;
        }

        int k=0;
        int j=0;
        for(pair i:count)
        {
            if(i.second>=2)
            {
                nums[j]=i.first;
                j++;
                nums[j]=i.first;
                j++;
                k=k+2;
            }
            else
            {
                nums[j] = i.first;
                j++;
                k++;
            }
        }
        return k;
    }
};