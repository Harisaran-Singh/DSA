class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long n = arr.size();
        long long ans = 0;
        long long odd = 0;
        long long ev = 0;
        long long mod = 1e9+7;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=1LL*arr[i];
            if(sum&1LL) ans++;
            ans = ans%mod;
            if(sum&1LL){
                ans+=ev;
                ans = ans%mod;
                odd++;
            }
            else {
                ans+=odd;
                ev++;
            }
            ans = ans%mod;
        }
        return (int)ans;
    }
};