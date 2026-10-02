class Solution {
public:
    void generate(int open,int closed,int n,string& tmp,vector<string>& ans){
        if(open==n && closed==n){
            ans.push_back(tmp);
            return;
        }
        if(open<n){
            tmp.push_back('(');
            generate(open+1,closed,n,tmp,ans);
            tmp.pop_back();
        }
        if(closed<open){
            tmp.push_back(')');
            generate(open,closed+1,n,tmp,ans);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp;
        vector<string> ans;
        generate(0,0,n,tmp,ans);
        return ans;
    }
};