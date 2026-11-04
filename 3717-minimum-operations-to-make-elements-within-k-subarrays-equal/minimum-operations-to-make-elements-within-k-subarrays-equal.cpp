class Solution {
public:
    using ll = long long;

    multiset<int> low, high;
    ll sumLow = 0, sumHigh = 0;

    void balance() {
        while (low.size() > high.size() + 1) {
            int x = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            int x = *high.begin();
            high.erase(high.begin());
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    }

    void insert(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }

        balance();
    }

    void erase(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= x;
        } else {
            it = high.find(x);
            high.erase(it);
            sumHigh -= x;
        }

        balance();
    }

    ll getCost() {
        ll med = *low.rbegin();

        return med * low.size() - sumLow
             + sumHigh - med * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        vector<ll> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            insert(nums[i]);

            if (i >= x) {
                erase(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const ll INF = 1e18;

        vector<vector<ll>> dp(k + 1,
                              vector<ll>(n + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = n - x; i >= 0; i--) {

                ll skip = dp[j][i + 1];

                ll take = cost[i] + dp[j - 1][i + x];

                dp[j][i] = min(skip, take);
            }
        }

        return dp[k][0];
    }
};