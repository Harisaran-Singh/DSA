class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt1 = 0;
        int cnt2 = 0;
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='x' && s2[i]=='y') cnt1++;
            else cnt2++;
        }
        int swaps = 0;
        swaps+=(cnt1/2);
        swaps+=(cnt2/2);
        cnt1%=2; cnt2%=2;
        if(cnt1 && cnt2) return swaps+2;
        else if(cnt1==0 && cnt2==0) return swaps;
        return -1;
    }
};