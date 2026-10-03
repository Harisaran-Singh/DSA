class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> z(n);
        int l = 0; int r = 0;
        for(int i=1;i<n;i++){
            if(i>r){
                l = r = i;
                while(r<n && word[r-l]==word[r]) r++;
                z[i] = r-l;
                r--;
            }
            else{
                int idx = i-l;
                if(z[idx]<(r-i+1)){
                    z[i] = z[idx];
                }
                else{
                    l = i;
                    while(r<n && word[r-l]==word[r]) r++;
                    z[i] = r-l;
                    r--;
                }
            }
        }
        for(int i=1;i<n;i++){
            int len = z[i];
            if((i+len)==n && i%k==0) return i/k;
        }
        if(n%k==0) return n/k;
        return (n/k)+1;
    }
};