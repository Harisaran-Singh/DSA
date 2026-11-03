class Solution {
public:
    bool check(long long mid,vector<int>& ranks, int cars){
        int n = ranks.size();
        for(int i=0;i<n && cars>0;i++){
            long long cur = mid/ranks[i];
            cars-=(int)sqrt(cur);
        }
        return cars<=0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long mn = *min_element(ranks.begin(),ranks.end());
        int n = ranks.size();
        int maxRank = *max_element(ranks.begin(),ranks.end());
        long long mx = 1LL*cars*1LL*cars*1LL*maxRank;
        while(mx>=mn){
            long long mid = mn+(mx-mn)/2;
            if(check(mid,ranks,cars)) mx = mid-1;
            else mn = mid+1;
        }
        return mn;
    }
};