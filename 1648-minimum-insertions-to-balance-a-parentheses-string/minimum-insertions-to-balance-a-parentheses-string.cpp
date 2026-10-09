class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char> st;
        int ans = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='(') st.push(s[i++]);
            else{
                if(i<n && s[i+1]==')'){
                    if(!st.empty()) st.pop();
                    else ans++;
                    i+=2;
                }
                else if(i<n && s[i+1]=='('){
                    if(!st.empty()){
                        st.pop();
                        ans++;
                        i++;
                    }
                    else{
                        ans+=2;
                        i++;
                    }
                }
                else{
                    if(!st.empty()){
                        st.pop();
                        ans++;
                        i++;
                    }
                    else{
                        ans+=2; i++;
                    }
                }
            }
        }
        ans+=(2*st.size());
        return ans;
    }
};