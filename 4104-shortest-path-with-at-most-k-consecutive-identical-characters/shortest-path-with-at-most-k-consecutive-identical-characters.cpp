class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n*(k+1),INT_MAX);
        using State = tuple<int,int,int>;
        priority_queue<State,vector<State>,greater<State>> pq;
        pq.push({0,0,1});
        dist[1] = 0;
        while(!pq.empty()){
            auto [d,node,streak] = pq.top();
            int ch = labels[node]-'a';
            pq.pop();
            if(node==n-1) return d;
            if(dist[(node)*(k+1)+streak]<d) continue;
            for(auto it:adj[node]){
                int newNode = it.first;
                int wt = it.second;
                int newCh = labels[newNode]-'a';
                int newWt = wt+d;
                if(newCh==ch){
                    if(streak<k){
                        int idx = (newNode)*(k+1)+streak+1;
                        if(newWt<dist[idx]){
                            dist[idx] = newWt;
                            pq.push({newWt,newNode,streak+1});
                        }
                    }
                }
                else{
                    int idx = (newNode)*(k+1)+1;
                    if(newWt<dist[idx]){
                        dist[idx] = newWt;
                        pq.push({newWt,newNode,1});
                    }
                }
            }
        }
        return -1;
    }
};