vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V;i++){
            for(auto &it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8&&dist[v]>dist[u]+wt){
                    if(i==V-1)return {-1};
                    if(i<V-1)dist[v]=dist[u]+wt;
                }
            }
        }
        return dist;
        
    }
