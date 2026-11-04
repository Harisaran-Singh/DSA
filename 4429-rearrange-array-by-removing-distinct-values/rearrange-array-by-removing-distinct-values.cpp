class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hash;
        vector<pair<int,int>> a;
        vector<int> ans;
        int maxf = 0;
        for(int& x:nums){
            hash[x]++;
            maxf = max(maxf,hash[x]);
        }
        for(int i=0;i<maxf;i++){
            for(auto it=hash.begin();it!=hash.end();it++){
                int el = it->first;
                int f = it->second;
                if(f<=0) continue;
                a.push_back({i,el});
                hash[el]--;
            }
        }
        sort(a.begin(),a.end(),cmp);
        for(auto& it:a) ans.push_back(it.second);
        return ans;
    }
};