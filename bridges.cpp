class Solution {
private:
    int timer=1;
    void dfs(int x,int par,vector<int>& vis,vector<int> g[],vector<int>& tins,vector<int>& low,vector<vector<int>>& bridges){
        vis[x]=1;
        tins[x]=low[x]=timer;
        timer++;
        for(auto c:g[x]){
            if(c==par)continue;
            if(vis[c]==0){
                dfs(c,x,vis,g,tins,low,bridges);
                low[x]=min(low[x],low[c]);
                if(low[c]>tins[x]){
                    bridges.push_back({x,c});
                }
            }
            else{
               low[x]=min(low[x],tins[c]); 
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        for(auto it:connections){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> tins(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0,-1,vis,g,tins,low,bridges);
        return bridges;

    }
};
