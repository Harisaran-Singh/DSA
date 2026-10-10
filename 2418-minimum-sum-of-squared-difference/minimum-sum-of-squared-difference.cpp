class Solution {
public:
    using ll = long long;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> f(1e5+1);
        for(int i=0;i<n;i++){
            int diff = abs(1LL*nums1[i]-1LL*nums2[i]);
            f[diff]++;
        }
        int k = k1+k2;
        for(int i=1e5;i>0 && k>0;i--){
            int ops = min(k,f[i]);
            k-=ops;
            f[i]-=ops;
            f[i-1]+=ops;
        }
        ll ans = 0;
        for(int i=0;i<=1e5;i++){
            ll val = 1LL*i;
            ans+=(1LL*f[i]*val*val);
        }
        return ans;
    }
};