class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> kmp(n);
        if(n==1) return false;
        int i=0; int j=1;
        while(j<n){
            if(s[i]==s[j]){
                kmp[j++] = ++i;
            }
            else if(i==0) j++;
            else i = kmp[i-1];
        }
        int val = kmp[n-1];
        if(val==0) return false;
        int idx = n-1;
        while(idx>=val){
            if(kmp[idx]!=val) return false;
            idx = idx-val;
        }
        return n%(n-val)==0;
    }
};