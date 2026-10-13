class Solution {
public:
    static bool cmp(int& a, int& b){
        a = abs(a);
        b = abs(b);
        return a>b;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        ll ans = 0;
        int k = (n+1)/2;
        for(int i=0;i<n;i++){
            ll sq = 1LL*nums[i]*1LL*nums[i];
            if(i<k) ans+=sq;
            else ans-=sq;
        }
        return ans;
    }
};