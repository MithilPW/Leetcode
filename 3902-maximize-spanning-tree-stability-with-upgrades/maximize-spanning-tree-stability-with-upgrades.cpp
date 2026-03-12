class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n){
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);

        parent[b]=a;

        if(rankv[a]==rankv[b]) rankv[a]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int X){

        DSU dsu(n);
        int used=0;

        vector<vector<int>> upgradeEdges;

        // Step 1: mandatory edges
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<X) return false;

                if(!dsu.unite(u,v)) return false;

                used++;
            }
        }

        // Step 2: optional edges without upgrade
        for(auto &e:edges){

            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must) continue;

            if(s>=X){
                if(dsu.unite(u,v)) used++;
            }
            else if(2*s>=X){
                upgradeEdges.push_back(e);
            }
        }

        // Step 3: optional edges with upgrade
        int upgrades=0;

        for(auto &e:upgradeEdges){

            if(upgrades==k) break;

            int u=e[0],v=e[1];

            if(dsu.unite(u,v)){
                used++;
                upgrades++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=1, hi=0;

        for(auto &e:edges)
            hi=max(hi,2*e[2]);

        int ans=-1;

        while(lo<=hi){

            int mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans;
    }
};