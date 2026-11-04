class Solution {
public:
    int calc2(char ch1, char ch2, string& s){
        int n = s.size();
        int l = 0;
        int ans = 0;
        int f2;
        int f1 = f2 = 0;
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            if(s[i]!=ch1 && s[i]!=ch2){
                l = i+1;
                f1 = f2 = 0;
                hash.clear();
            }
            else{
                if(s[i]==ch1) f1++;
                else f2++;
                if(hash.find(f2-f1)!=hash.end()) ans = max(ans,i-hash[f2-f1]);
                else hash[f2-f1] = i;
                if(f2==f1) ans = max(ans,i-l+1);
            }
        }
        return ans;
    }
    int calc3(string& s) {
        int n = s.size();
        int ans = 0;

        unordered_map<long long, int> mp;

        auto encode = [](int x, int y) -> long long {
            return 1LL * (x + 100000) * 200001 + (y + 100000);
        };

        int cnt[3] = {0, 0, 0};

        mp[encode(0, 0)] = -1;

        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;

            int x = cnt[0] - cnt[1];
            int y = cnt[1] - cnt[2];

            long long key = encode(x, y);

            if (mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
    int longestBalanced(string s) {
        int ans = 1;
        int n = s.size();
        char prev = s[0];
        int l = 0;
        for(int i=1;i<n;i++){
            if(prev==s[i]) ans = max(ans,i-l+1);
            else{
                prev = s[i];
                l = i;
            }
        }
        ans = max(ans,calc2('a','b',s));
        ans = max(ans,calc2('b','c',s));
        ans = max(ans,calc2('c','a',s));
        ans = max(ans,calc3(s));
        return ans;
        
    }
};