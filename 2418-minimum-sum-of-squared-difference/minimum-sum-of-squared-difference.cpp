class Solution {
public:
    using ll = long long;
    bool isValid(ll mid,vector<ll>& f,int k,ll sum){
        int m = f.size();
        for(int i=m-1;i>0;i--){
            ll freq = f[i];
            if(freq==0) continue;
            ll val = 2LL*i-1;
            if(sum>mid){
                if(k<freq){
                    sum-=(k*val);
                    return sum<=mid;
                }
                k-=freq;
                sum-=(freq*val);
            }
            else return true;
        }
        return sum<=mid;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        ll maxi = 0;
        unordered_map<ll,ll> hash;
        for(int i=0;i<n;i++){
            ll diff = abs(1LL*nums1[i]-1LL*nums2[i]);
            hash[diff]++;
            maxi+=(diff*diff);
        }
        vector<ll> f(1e5+1);
        for(auto& it:hash) f[it.first] = it.second;
        int m = f.size();
        for(int i=m-2;i>0;i--){
            f[i]+=f[i+1];
        }
        ll mini = 0;
        ll maxSum = maxi;
        while(mini<=maxi){
            ll mid = mini+(maxi-mini)/2;
            if(isValid(mid,f,k1+k2,maxSum)) maxi = mid-1;
            else mini = mid+1;
        }
        return mini;
    }
};