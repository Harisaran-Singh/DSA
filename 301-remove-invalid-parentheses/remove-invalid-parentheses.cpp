class Solution {
public:
    void generate(int ind,int balance,int req,string& tmp,unordered_set<string>& ans,string& s){
        if(ind>=s.size()){
            if(tmp.size()==req && balance==0) ans.insert(tmp);
            return;
        }
        if(tmp.size()<req && balance>=0){
            tmp.push_back(s[ind]);
            int add = s[ind]=='('?1:-1;
            if(s[ind]>='a' && s[ind]<='z') add = 0;
            generate(ind+1,balance+add,req,tmp,ans,s);
            tmp.pop_back();
        }
        if(balance>=0) generate(ind+1,balance,req,tmp,ans,s);
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
        int cnt = open+closed;
        string tmp;
        unordered_set<string> ans;
        generate(0,0,n-cnt,tmp,ans,s);
        return vector<string>(ans.begin(),ans.end());
    }
};