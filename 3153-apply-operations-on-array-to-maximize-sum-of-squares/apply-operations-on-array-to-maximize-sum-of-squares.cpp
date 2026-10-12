class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        ll mod = 1e9+7;
        vector<int> bits(32,0);
        for(int i=0;i<n;i++){
            int val = nums[i];
            for(int j=0;j<32;j++){
                if(val & (1<<j)) bits[j]++;
            }
        }
        ll ans = 0;
        for(int i=0;i<k;i++){
            int val = 0;
            for(int j=0;j<32;j++){
                if(bits[j]>0){
                    val|=(1<<j);
                    bits[j]--;
                }
            }
            ll sq = 1LL*val*1LL*val;
            ans = (ans+sq)%mod;
        }
        return ans;
    }
};