class DisjointSet{
    vector<int> rank,par,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        par.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    int find(int x){
        if(x==par[x])return x;
        return par[x]=find(par[x]);
    }
    void unionbysize(int u,int v){
        int au=find(u);
        int av=find(v);
        if(au==av)return;
        if(size[au]<size[av]){
            par[au]=av;
            size[av]+=size[au];
        }
        else{
            par[av]=au;
            size[au]+=size[av];
        }
    }
       
};
