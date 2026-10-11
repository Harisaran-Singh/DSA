class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
                ll sqr = 1LL*nums[i]*1LL*nums[i];
                sum+=(sqr);
            }
        }
        return sum;
    }
};