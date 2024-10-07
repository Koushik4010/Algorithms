// class DisjointSet{
//     vector<int> rank,par,size;
//     public:
//     DisjointSet(int n){
//         rank.resize(n+1,0);
//         size.resize(n+1);
//         par.resize(n+1);
//         for(int i=1;i<=n;i++){
//             par[i]=i;
//             size[i]=1;
//         }
//     }
//     int find(int x){
//         if(x==par[x])return x;
//         return par[x]=find(par[x]);
//     }
//     void unionbysize(int u,int v){
//         int au=find(u);
//         int av=find(v);
//         if(au==av)return;
//         if(size[au]<size[av]){
//             par[au]=av;
//             size[av]+=size[au];
//         }
//         else{
//             par[av]=au;
//             size[au]+=size[av];
//         }
//     }
       
// };
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // // Prims algo
        vector<int> vis(V,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,-1}});// {wt,{x,par}}
        vector<int> mst;
        int sum=0;
        
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            auto wt=it.first;
            auto x=it.second.first;
            auto p=it.second.second;
            
            if(vis[x]==1)continue;
            vis[x]=1;
            sum+=wt;
            
            for(auto &c:adj[x]){
                if(vis[c[0]]!=1){
                    q.push({c[1],{c[0],x}});
                }
            }
        }
        return sum;
        
        //Kruskal's algo
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],i,it[0]});
            }
        }
        sort(edges.begin(),edges.end());
        int ans=0;
        DisjointSet ds(V); 
        for(auto it:edges){
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            if(ds.find(u)!=ds.find(v)){
                ans+=wt;
                ds.unionbysize(u,v);
            }
            
        }
        return ans;
    }
