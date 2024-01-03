
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int getsize(vector<int> nums)
    {
        return nums.size();
    }
    int kthLargest(vector<int> arr, int l, int r, int k) {
        //code here
        int n = getsize(arr);
        k=n-k+1 ;
        priority_queue<int> pq;
        // step 1;
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        // step 2
        for(int i=k;i<=r;i++)
        {
            if(arr[i]<pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int r = getsize(nums) -1;
        int ans = kthLargest(nums,0,r,k);
        return ans;
    }
};