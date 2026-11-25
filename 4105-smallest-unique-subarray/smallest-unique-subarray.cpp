class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        // Build Suffix Array using Doubling
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] +
                              cmp(sa[i - 1], sa[i]);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP array using Kasai's algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0) h--;
        }

        // Find minimum unique subarray length
        int ans = n;

        for (int r = 0; r < n; r++) {
            int i = sa[r];

            int mx = lcp[r];

            if (r + 1 < n)
                mx = max(mx, lcp[r + 1]);

            if (mx + 1 <= n - i)
                ans = min(ans, mx + 1);
        }

        return ans;
    }
};