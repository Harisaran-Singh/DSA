class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        using state = pair<int,int>;

        priority_queue<state, vector<state>, greater<state>> av;
        priority_queue<pair<int,state>, vector<pair<int,state>>, greater<pair<int,state>>> nav;

        for(int i = 0; i < m; i++) {
            av.push({servers[i], i});
        }

        long long t = 0;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            t = max(t, (long long)i);

            while(!nav.empty() && nav.top().first <= t) {
                auto tp = nav.top();
                nav.pop();
                av.push(tp.second);
            }

            if(av.empty()) {
                t = nav.top().first;

                while(!nav.empty() && nav.top().first <= t) {
                    auto tp = nav.top();
                    nav.pop();
                    av.push(tp.second);
                }
            }

            auto tp = av.top();
            av.pop();

            ans[i] = tp.second;

            nav.push({t + tasks[i], tp});
        }

        return ans;
    }
};