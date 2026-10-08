class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for(char& ch:s){
            if(ch=='(' && cnt==0){
                cnt++;
                continue;
            }
            if(ch==')' && cnt==1){
                cnt--;
                continue;
            }
            if(ch=='(') cnt++;
            else cnt--;
            ans.push_back(ch);
        }
        return ans;
    }
};