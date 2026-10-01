class Solution {
public:
    string shortestPalindrome(string s) {
        if(s=="") return "";
        string ans = s;
        s+="#";
        string rev = s;
        reverse(rev.begin(),rev.end());
        s+=rev;
        int n = s.size();
        vector<int> lps(n);
        int i,j;
        i = 0; j = 1;
        while(j<n){
            if(s[i]==s[j]) lps[j++] = ++i;
            else if(i>0) i = lps[i-1];
            else j++;
        }
        int len = lps[n-1];
        string tmp = ans.substr(len);
        reverse(tmp.begin(),tmp.end());
        ans = tmp + ans;
        return ans;
    }
};