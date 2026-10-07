class Solution {
public:
    void dfs(int ind,int balance,int left,int right,string& tmp,unordered_set<string>& ans,string& s){
        if(ind>=s.size()){
            if(balance==0 && left==0 && right==0) ans.insert(tmp);
            return;
        }
        if(balance<0) return;
        char ch = s[ind];
        if(ch>='a' && ch<='z'){
            tmp.push_back(ch);
            dfs(ind+1,balance,left,right,tmp,ans,s);
            tmp.pop_back();
            return;
        }
        if(ch=='('){
            if(left>0){
                dfs(ind+1,balance,left-1,right,tmp,ans,s);
            }
            tmp.push_back(ch);
            dfs(ind+1,balance+1,left,right,tmp,ans,s);
            tmp.pop_back();
        }
        else{
            if(right>0){
                dfs(ind+1,balance,left,right-1,tmp,ans,s);
            }
            tmp.push_back(ch);
            dfs(ind+1,balance-1,left,right,tmp,ans,s);
            tmp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int open = 0;
        int closed = 0;
        for(char &ch:s){
            if(ch>='a' && ch<='z') continue;
            else if(ch=='(') open++;
            else{
                if(open>0) open--;
                else closed++;
            }
        }
        string tmp;
        unordered_set<string> ans;
        dfs(0,0,open,closed,tmp,ans,s);
        return vector<string>(ans.begin(),ans.end());
    }
};