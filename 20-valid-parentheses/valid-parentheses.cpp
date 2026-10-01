class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char& ch:s){
            if(ch=='(' || ch=='[' || ch=='{') st.push(ch);
            else if(ch==')'){
                if(st.empty() || st.top()!='(') return false;
                st.pop();
            }
            else if(ch==']'){
                if(st.empty() || st.top()!='[') return false;
                st.pop();
            }
            else{
                if(st.empty() || st.top()!='{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};