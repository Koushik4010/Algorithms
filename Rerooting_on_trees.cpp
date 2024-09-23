#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> tree[MAXN];
int dp[MAXN];  // Height of subtree rooted at node u
int ans[MAXN]; // Height of tree when rooted at node u

// First DFS to compute heights of subtrees
void dfs1(int u, int p) {
    dp[u] = 0; // Height of a leaf node is 0
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] = max(dp[u], dp[v] + 1); // Update height
    }
}

// Second DFS to reroot the tree at each node and compute heights
void dfs2(int u, int p, int up) {
    ans[u] = max(dp[u], up); // Height when rooted at u
    int mx1 = -1, mx2 = -1;  // Top two maximum heights among child subtrees
    int ch1 = -1, ch2 = -1;  // Corresponding child nodes

    // Find the top two maximum heights among children
    for (int v : tree[u]) {
        if (v == p) continue;
        int val = dp[v] + 1;
        if (val > mx1) {
            mx2 = mx1;
            ch2 = ch1;
            mx1 = val;
            ch1 = v;
        } else if (val > mx2) {
            mx2 = val;
            ch2 = v;
        }
    }

    // Reroot the tree at each child and compute heights
    for (int v : tree[u]) {
        if (v == p) continue;
        int use = (v == ch1) ? mx2 : mx1;
        int up_v = max(up, use) + 1; // Height from ancestors and siblings
        dfs2(v, u, up_v);
    }
}

int main() {
    int n;
    cin >> n;
    // Build the tree
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // Assuming nodes are 1-indexed
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs1(1, -1);      // Start first DFS from node 1
    dfs2(1, -1, -1);  // Start second DFS from node 1 with up = -1
    // Output the heights for all nodes
    for (int u = 1; u <= n; ++u) {
        cout << "Height when rooted at node " << u << ": " << ans[u] << endl;
    }
    return 0;
}
