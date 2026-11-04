class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = nums.size();
        int n = nums.size();
        int l = 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) l = i;
            else ans+=1LL*(i-l);
        }
        return ans;
    }
};