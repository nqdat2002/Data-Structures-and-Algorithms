#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

// Author: Nguyen Quoc Dat
// ID: B20DCPT053
// Organization: PTIT
// Date: 07/03/22 10:30
// Program: Kruskal
// -------------------  Your code STARTS here !!!---------------------------

typedef vector<pair<pair<int, int>, int> > edge;
edge adj, tree;
int parent[1005];
int n, m;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){ 
    return a.s < b.s; 
}

int root(int u){
    return (parent[u] == -1) ? u : (parent[u] = root(parent[u]));
}
bool Cycle(edge Tree){
    memset(parent, -1, sizeof(parent));
    for(auto a: Tree){
        int u = root(a.f.f);
        int v = root(a.f.s);
        if(u == v) 
            return true;
        parent[u] = v;
    }
    return false;
}
void Kruskal(){
    sort(adj.begin(), adj.end(), cmp);
    tree.clear();
    int res = adj[0].s;
    tree.push_back(adj[0]);
    for(int i = 1; i < m; ++i){
        tree.push_back(adj[i]);
        if(!Cycle(tree)) res += adj[i].s;
        else{
            tree.pop_back();
            continue;
        }
        if(tree.size() - n + 1 == 0) break;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        adj.clear();
        for(int i = 0; i < m; ++i){
            int u, v, w; cin >> u >> v >> w;
            adj.push_back({{u, v}, w});
        }
        Kruskal();
    }
    return 0;
}
