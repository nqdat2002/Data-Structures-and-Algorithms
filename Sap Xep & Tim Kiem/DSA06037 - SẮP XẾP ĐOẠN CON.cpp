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
// Date: 12/02/22 10:04
// Program: Sap xep doan con
// -------------------  Your code STARTS here !!!---------------------------

void Solve(vector<int> a, int n){
	vector<int> b(n + 5), c(n + 5);
	b[0] = a[0];
	c[n - 1] = a[n - 1];
	for(int i = 1; i < n; i ++)
		b[i] = max(b[i - 1], a[i]);
	for(int i = n - 2; i >= 0; i --)
		c[i] = min(c[i + 1], a[i]);
	vector<int> ans;
	int cnt = 0;
	for(int i = 0; i < n - 1; i ++){
		if(b[i] <= c[i + 1]){
			cnt++;
			ans.push_back(i + 1);
		}
	}
	cout << cnt << endl;
	for(auto x: ans) cout << x << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(auto &x: a) cin >> x;
		Solve(a, n);
		cout << endl;
	}
	return 0;
}
