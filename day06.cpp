class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m = arr.size(), n = arr[0].size();

        int start=0,end=m*n-1,mid=0;
        while(start<=end)
        {
            mid=end+(start-end)/2;
            int i=mid/n;
            int j=mid%n;
            if(arr[i][j]==target)
            {
                return 1;
            }
            else if(arr[i][j]<target)
            {
                start=mid+1;
            }
            else
            end=mid-1;
        }
        return 0;
        
    }
};
