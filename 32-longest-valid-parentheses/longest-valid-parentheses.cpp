class Solution {
public:
    int f(string& s){
        int n = s.size();
        int ans = 0;
        int start = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else{
                cnt--;
                if(cnt<0){
                    start = i+1;
                    cnt = 0;
                    continue;
                }
                else if(cnt==0){
                    int len = i-start+1;
                    ans = max(ans,len);
                }
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        int len1 = f(s);
        reverse(s.begin(),s.end());
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') s[i] = ')';
            else s[i] = '(';
        }
        int len2 = f(s);
        return max(len1,len2);
    }
};