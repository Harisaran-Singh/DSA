class Solution {
public:
    int pivotInteger(int n) {
        int total = 1LL*n*1LL*(1+n)/2;
        for(int i=1;i<=n;i++){
            int sum1 = i*(i-1)/2;
            int sum2 = total-(i*(i+1)/2);
            if(sum2==sum1) return i;
        }
        return -1;
        
    }
};