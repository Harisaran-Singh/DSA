class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();
        unordered_set<string> seen;
        string cur = "";
        vector<string> ans;
        for(char &ch:s){
            cur.push_back(ch);
            if(!seen.count(cur)){
                seen.insert(cur);
                ans.push_back(cur);
                cur = "";
            }
        }
        return ans;
    }
};