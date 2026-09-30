class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int maxNested = 0;
        int cnt = 0;
        for(char &ch:seq){
            if(ch=='('){
                cnt++;
                maxNested = max(maxNested,cnt);
            }
            else cnt--;
        }
        int need = maxNested/2;
        vector<int> ans(n,1);
        cnt = 0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                if(cnt<need){
                    ans[i] = 0;
                    cnt++;
                }
            }
            else if(cnt>0){
                ans[i] = 0;
                cnt--;
            }
        }
        return ans;
    }
};