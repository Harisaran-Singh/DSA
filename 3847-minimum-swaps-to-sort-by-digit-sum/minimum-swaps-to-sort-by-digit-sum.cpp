class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {digitSum(nums[i]), nums[i]};
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i, cnt = 0;

            while (!vis[j]) {
                vis[j] = true;
                cnt++;
                j = pos[nums[j]];
            }

            ans += cnt - 1;
        }

        return ans;
    }
};