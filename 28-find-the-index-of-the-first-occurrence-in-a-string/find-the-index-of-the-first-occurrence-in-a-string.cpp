class Solution {
public:
    vector<int> findLPS(string& needle){
        int n = needle.size();
        vector<int> lps(n);
        int i=0; int j=1;
        while(j<n){
            if(needle[i]==needle[j]) lps[j++] = ++i;
            else if(i>0) i = lps[i-1];
            else lps[j++] = 0;
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        vector<int> lps = findLPS(needle);
        int i=0; int j=0;
        while(i<m && j<n){
            if(haystack[i]==needle[j]){
                i++; j++;
            }
            else if(j>0) j = lps[j-1];
            else i++;
        }
        return j==n?i-n:-1;
    }
};