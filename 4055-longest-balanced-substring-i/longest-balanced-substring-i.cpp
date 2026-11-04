class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> f(26);
            for(int j=i;j<n;j++){
                bool flag = true;
                int prev = -1;
                f[s[j]-'a']++;
                for(int k=0;k<26;k++){
                    if(prev==-1){
                        if(f[k]!=0) prev = f[k];
                        continue;
                    }
                    else if(f[k]!=0 && prev!=f[k]){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};