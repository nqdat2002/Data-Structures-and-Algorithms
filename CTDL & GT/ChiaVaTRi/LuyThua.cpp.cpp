#include <bits/stdc++.h>
using namespace std;

int  MODULO = 1000000007;

long long power(long long n, long long k) {
    if (k == 0)
        return 1;

    long long x = power(n, (k / 2));

    if (k % 2 == 0)
        return x * x % MODULO;

    return n * (x * x % MODULO) % MODULO;
}

int main() {
    int test;
    long long n, k;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        cout << power(n, k) << endl;
    }
    return 0;
}
