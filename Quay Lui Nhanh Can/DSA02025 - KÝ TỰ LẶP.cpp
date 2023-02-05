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
// Date: 14/02/22 10:43
// Program: Ky tu lap
// -------------------  Your code STARTS here !!!---------------------------

int res, fopt, cnt;
int a[100];
int n;
vector<string> v;
bool visited[100];

int Count(string x, string y){
	int i = 0, j = 0, l1 = x.size(), l2 = y.size(), s = 0;
    while (i < l1 && j < l2){
        if (x[i] == y[j]){
            s ++;
            i ++;
            j ++;
        }
        while (x[i] < y[j]){
            i++;
            if (i == l1)
                break;
        }
        while (x[i] > y[j]){
            j++;
            if (j == l2)
                break;
        }
    }
    return s;
}

void init(){
	cin >> n;
	v.clear();
	v.resize(n + 1);
	v.push_back("");
	for(int i = 1; i <= n; i ++){
		cin >> v[i];
	}
	a[0] = 0;
	res = oo;
	memset(visited, false, sizeof(visited));
}

void Try(int i, int cnt){
	if(res < cnt)
		return;
	for(int j = 1; j <= n; j ++){
		if(!visited[j]){
			visited[j] = true;
			a[i] = j;
			if(i == n){
				res = min(res, cnt + Count(v[a[i - 1]], v[j]));
			}
			else if(res > cnt && i < n) 
				Try(i + 1, cnt + Count(v[a[i - 1]], v[j]));
			visited[j] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while(t--){

		init();
		Try(1, 0);
		cout << res << endl;
	}
	return 0;
}
