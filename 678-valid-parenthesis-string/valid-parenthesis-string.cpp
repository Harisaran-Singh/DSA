class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int l = 0; int h = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                l++; h++;
            }
            else if(s[i]==')'){
                l--;h--;
                if(l<0) l = 0;
            }
            else{
                l--;
                if(l<0) l = 0;
                h++;
            }
            if(h<0) return false;
        }
        return l==0;
    }
};