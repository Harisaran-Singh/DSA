class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ops = 1LL;
        int diff = INT_MAX;
        int last = nums2[n];
        for(int i=0;i<n;i++){
            ops+=1LL*abs(nums1[i]-nums2[i]);
            diff = min(diff,abs(nums1[i]-last));
            diff = min(diff,abs(nums2[i]-last));
            if((nums1[i]<=last && last<=nums2[i]) || (nums1[i]>=last && last>=nums2[i])) diff = 0;
        }
        ops+=1LL*diff;
        return ops;
    }
};