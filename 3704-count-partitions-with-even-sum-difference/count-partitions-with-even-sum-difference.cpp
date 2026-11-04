class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int leftSum = 0;
        int ans = 0;
        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            int rightSum = total-leftSum;
            if(abs(leftSum-rightSum)&1) continue;
            else ans++;
        }
        return ans;
    }
};