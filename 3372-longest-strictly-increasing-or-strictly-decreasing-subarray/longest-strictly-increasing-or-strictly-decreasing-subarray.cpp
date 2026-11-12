class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int cur1 = 1;
        int cur2 = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cur2 = 1;
                cur1++;
                inc = max(inc,cur1);
            }
            else if(nums[i]<nums[i-1]){
                cur1 = 1;
                cur2++;
                dec = max(dec,cur2);
            }
            else{
                cur1 = cur2 = 1;
            }
        }
        return max(dec,inc);
    }
};