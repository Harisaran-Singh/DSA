class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 6*min({x,y,z});
        int mini = min({x,y,z});
        x-=mini; y-=mini; z-=mini;
        if(z==0){
            int mn = min(x,y);
            if(x==y) ans+=(4*x);
            else ans+=(4*mn+2);
        }
        else if(x==0){
            ans+=(2*z);
            if(y) ans+=2;
        }
        else{
            ans+=(2*z);
            if(x) ans+=2;
        }
        return ans;
    }
};