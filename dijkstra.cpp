 //Important in dijkstra algo is how you maintain the pq by removing the redundant pairs
// O((V+E)logV)
// each vertex is inserted and extracted exactly once, so these operations contribute O(VlogV)
// Each edge is processed once, and the relaxation of edges contributes O(ElogV)

void dijkstra(int s,vector<pair<int,int>> g[],vector<ll>& dist){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,s});
        dist[s]=0;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;// important to stop processing for reduntant nodes
            for(auto [wt,v]:g[u]){
                if(dist[v]>(ll)wt+dist[u]){  // Only use dist[u] and not d
                    dist[v]=(ll)wt+dist[u];
                    pq.push({dist[v],v});
                }
            }
        }
    }

