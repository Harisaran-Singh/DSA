class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int ans = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                open++;
                i++;
            }
            else{
                if(i<n-1 && s[i+1]==')'){
                    if(open>0) open--;
                    else ans++;
                    i+=2;
                }
                else if((i<n-1 && s[i+1]=='(') || i==n-1){
                    if(open>0){
                        open--;
                        ans++;
                    }
                    else{
                        ans+=2;
                    }
                    i++;
                }
            }
        }
        ans+=(2*open);
        return ans;
    }
};