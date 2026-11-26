class Solution {
public:
    bool canAliceWin(int n) {
        if(n<=9) return false;
        if(n<=18) return true;
        if(n<=26) return false;
        if(n<=33) return true;
        if(n<=39) return false;
        if(n<=44) return true;
        if(n<=48) return false;
        return true;
    }
};