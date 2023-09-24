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

    // number of connected components
    int getNCC() {
        return ncc;
    }

    // largest component size
    int getLCS() {
        return lcs;
    }

    // return the size of connected component of node u
    int getSizeOfCC(int u) {
        u = find(u);
        return abs(parent[u]);
    }

    void printParent() {
        for(int p: parent) {
            cout << p << ", ";
        }
        cout << endl;
    }

    void printRank() {
        for(int r: rankk) {
            cout << r << ", ";
        }
        cout << endl;
    }
};