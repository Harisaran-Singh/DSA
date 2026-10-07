class Solution {
public:
    bool isValid(string& s){
        int n = s.size();
        int cnt = 0;
        for(char &ch:s){
            if(ch<='z' && ch>='a') continue;
            else if(ch=='(') cnt++;
            else{
                cnt--;
                if(cnt<0) return false;
            }
        }
        return cnt==0;
    }
    void generate(int ind,int req,string& tmp,unordered_set<string>& ans,string& s){
        if(ind>=s.size()){
            if(tmp.size()==req && isValid(tmp)) ans.insert(tmp);
            return;
        }
        if(tmp.size()<req){
            tmp.push_back(s[ind]);
            generate(ind+1,req,tmp,ans,s);
            tmp.pop_back();
        }
        generate(ind+1,req,tmp,ans,s);
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        stack<char> st;
        for(char &ch:s){
            if(ch>='a' && ch<='z') continue;
            else if(ch=='(') st.push(ch);
            else{
                if(st.empty() || st.top()!='(') cnt++;
                else st.pop();
            }
        }
        cnt+=st.size();
        string tmp;
        unordered_set<string> ans;
        generate(0,n-cnt,tmp,ans,s);
        vector<string> valid(ans.begin(),ans.end());
        return valid;
    }
};