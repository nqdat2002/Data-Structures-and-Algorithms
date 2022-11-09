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

typedef struct node{
    int data;
    node *left;
    node *right;
} *tree;

bool isLeft(tree root, int value){
    return value < root->data;
}
bool isRight(tree root, int value){
    return value > root->data;
}
tree Insert(tree root, int value){
    if(root == NULL){
        root = new node();
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(isLeft(root, value)){
        root->left = Insert(root->left, value);
    }
    else if(isRight(root, value)){
        root->right = Insert(root->right, value);
    }
    return root;
}

void showPostOrder(tree root){
    if (root == NULL) return;
    showPostOrder(root->left);
    showPostOrder(root->right);
    cout << root->data << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a;
        set<int> st;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            a.push_back(x);
            st.insert(x);
        }
        if(st.size() < n){
            cout << 0 << endl;
            continue;
        }
        int ok = 1;
        for(int i = 0; i < n - 1; ++i){
            if(a[i] > a[i + 1]){
                cout << 0 << endl;
                ok = 0;
                break;
            }
        }
        if(ok) cout << 1 << endl;
    }
    return 0;
}
