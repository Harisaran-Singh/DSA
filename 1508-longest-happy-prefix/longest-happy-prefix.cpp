class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        int i=0; int j=1;
        while(j<n){
            if(s[i]==s[j]) lps[j++] = ++i;
            else if(i>0) i = lps[i-1];
            else j++;
        }
        int len = lps[n-1];
        return s.substr(0,len);
    }
};