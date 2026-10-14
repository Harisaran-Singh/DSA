class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while(sum>0){
            if(sum>=9){
                ans.push_back('9');
                sum-=9;
            }
            else{
                ans+=to_string(sum);
                sum = 0;
            }
            num--;
        }
        if(num>0) ans+=string(num,'0');
        return num>=0?ans:"";
    }
};