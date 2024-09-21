#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 200000;

int bit[N + 1];

void update(int i, int val) {
    for (; i <= N; i += i & -i) {
        bit[i] = (bit[i] + val) % MOD;
    }
}

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
        sum = (sum + bit[i]) % MOD;
    }
    return sum;
}
