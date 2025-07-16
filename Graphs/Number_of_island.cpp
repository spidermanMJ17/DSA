#include<bits/stdc++.h>

class DSU{
    private:
    vector<int> parent,size,rank;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size(i)=1;
        }
    }

    int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionbyrank(int u,int v){
        uu = findUpar(u);
        uv = findUpar(v);
        if(uu == uv) return;
        if(rank[uu]<rank[uv]){
            parent[uu] = uv;
        }
        else if(rank[uu]>rank[uv]){
            parent[uv]=uu;
        }
        else{
            parent[uu]=uv;
            rank[uv]++;
        }
    }

    void unionbysize(int u, int v){
        uu = findUpar(u);
        uv = findUpar(v);
        if(uu == uv) return;
        if(size[uu]>size[uv]){
            parent[uv] = uu;
            size[uu] += size[uv];
        }
        else{
            parent[uu] = uv;
            size[uv] += size[uu];
        }
    }
};

int answer(int V, vector<vector<int>> &adj){
    int n = adj.size();
    DSU ds(n*n);

    //step 1 to find all ones and connect them

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(adj[row][col]==0) continue;
            int dr[] = {+1,0,0,-1};
            int dc[] = {0,+1,-1,0};

            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(isvalid(nrow,ncol,n) && adj[nrow][ncol]==1){
                    int nodeno = row * n + col;
                    int adjnode = nrow * n + ncol;
                    ds.unionbysize(nodeno, adjnode);
                }
            }
        }
    }

    //step 2 to find zero and make it one
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(adj[row][col]==1) continue;
            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(isvalid(ifbnid)){
                    
                }
            }
        }
    }

};