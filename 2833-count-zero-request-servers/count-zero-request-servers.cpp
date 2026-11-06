class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1]!=b[1]) return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();
        sort(logs.begin(),logs.end(),cmp);
        vector<pair<int,int>> v;
        for(int i=0;i<q;i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        int l = 0; int r = 0;
        int active = 0;
        vector<int> cnt(n+1);
        vector<int> ans(q);
        for(auto& it:v){
            int t = it.first;
            int idx = it.second;
            while(r<m && logs[r][1]<=t){
                cnt[logs[r][0]]++;
                if(cnt[logs[r][0]]==1) active++;
                r++;
            }
            while(l<r && logs[l][1]<t-x){
                cnt[logs[l][0]]--;
                if(cnt[logs[l][0]]==0) active--;
                l++;
            }
            ans[idx] = n-active;
        }
        return ans;
    }
};