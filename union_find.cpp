class UnionFind {
    int n;
    vector<int> parent;
    vector<int> rankk;
    int ncc; // number of connected components
    int lcs; // largest component size
    public:
    UnionFind(int n) {
        this->n = n;
        this->ncc = n;
        this->lcs = 1;
        parent = vector<int> (n, -1);
        rankk = vector<int> (n, -1);
    }

    int find(int u) {
        if(parent[u] < 0) return u;
        return parent[u] = find(parent[u]); // path compression
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(rankk[u] >= rankk[v]) {
                parent[u] += parent[v]; // size combining
                parent[v] = u;
                if(rankk[u] == rankk[v]) {
                    rankk[u]++;
                }
                lcs = max(lcs, abs(parent[u]));
            } else {
                parent[v] += parent[u]; // size combining
                parent[u] = v;
                lcs = max(lcs, abs(parent[v]));
            }
            ncc--; // 2 diffrent components are combining 
            return true;
        }
        return false;
    }
    int getNCC() {
        return ncc;
    }
    int getLCS() {
        return lcs;
    }
};