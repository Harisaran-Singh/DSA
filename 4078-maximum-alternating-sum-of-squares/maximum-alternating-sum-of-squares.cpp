class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        for(int& i:nums) i*=i;
        sort(nums.begin(),nums.end(),greater<int>());
        ll ans = 0;
        int k = (n+1)/2;
        for(int i=0;i<n;i++){
            if(i<k) ans+=1LL*nums[i];
            else ans-=1LL*nums[i];
        }
        return ans;
    }
};