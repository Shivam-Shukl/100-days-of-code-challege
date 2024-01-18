class Solution {
public:
    int getXOR(int x, int y) {
        int ans = 0;
        for (int i = 0; i <= 31; i++) {
            if (((1LL << i) & x) != ((1LL << i) & y)) {
                ans |= (1LL << i);
            }
        }
        return ans;
    }
    
    int maximumStrongPairXor(vector<int>& nums) {
        //making strong pair as well finding xor of it at the same time so
        int Xor =0;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                int x = nums[i];
                int y = nums[j];
                if(abs(x-y) <= min(x,y))
                {
                    int New_xor = getXOR(x,y);
                    Xor= max(Xor, New_xor);
                }
            }
        }
        return Xor;

        
        
    }
    
};