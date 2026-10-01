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
    bool search(string& a, string& b,vector<int>& lps){
        int i=0; int j=0;
        int m = a.size(); int n = b.size();
        while(i<m && j<n){
            if(a[i]==b[j]){
                i++; j++;
            }
            else if(j>0) j = lps[j-1];
            else i++;
        }
        return j==n;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int cnt = 1;
        string tmp = a;
        while(tmp.size()<b.size()){
            tmp+=a; cnt++;
        }
        vector<int> lps = findLPS(b);
        if(search(tmp,b,lps)) return cnt;
        tmp+=a;
        if(search(tmp,b,lps)) return cnt+1;
        return -1;
    }
};