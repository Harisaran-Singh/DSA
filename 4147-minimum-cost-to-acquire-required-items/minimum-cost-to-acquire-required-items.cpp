class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mn = min(need1, need2);

        long long ans = 0;

        ans += mn * min((long long)costBoth, (long long)cost1 + cost2);

        ans += (need1 - mn) * min(cost1, costBoth);
        ans += (need2 - mn) * min(cost2, costBoth);

        return ans;
    }
};