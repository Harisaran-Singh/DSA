class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        int size = (sum+8)/9;
        if(size>num) return "";
        int nines = sum/9;
        ans+=string(nines,'9');
        int rem = sum%9;
        if(rem) ans+=to_string(rem);
        num-=ans.size();
        ans+=string(num,'0');
        return ans;
    }
};