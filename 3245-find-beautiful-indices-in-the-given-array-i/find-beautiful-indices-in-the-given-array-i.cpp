class Solution {
public:
    vector<int> findLPS(string& s){
        int n = s.size();
        vector<int> lps(n);
        int i=0; int j=1;
        while(j<n){
            if(s[i]==s[j]) lps[j++] = ++i;
            else if(i>0) i = lps[i-1];
            else j++;
        }
        return lps;
    }
    vector<int> match(string& s, string& a,vector<int>& lps){
        int m = s.size();
        int n = a.size();
        vector<int> indices;
        int i=0; int j=0;
        while(i<m){
            if(s[i]==a[j]){
                i++; j++;
                if(j==n){
                    indices.push_back(i-n);
                    j = lps[j-1];
                }
            }
            else if(j>0) j = lps[j-1];
            else i++;
        }
        return indices;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int l = s.size();
        int m = a.size();
        int n = b.size();
        vector<int> lps1 = findLPS(a);
        vector<int> lps2 = findLPS(b);
        vector<int> idx1 = match(s,a,lps1);
        vector<int> idx2 = match(s,b,lps2);
        vector<int> ans;
        for(int &i:idx1){
            int lb = lower_bound(idx2.begin(),idx2.end(),i)-idx2.begin();
            int val1 = lb==0?-1e9:idx2[lb-1];
            int val2 = lb==(idx2.size())?1e9:idx2[lb];
            if(abs(i-val1)<=k || abs(val2-i)<=k) ans.push_back(i);
        }
        return ans;
    }
};