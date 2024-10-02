#include <vector>
#include <stack>
using namespace std;

void dfs1(int x, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
    vis[x] = 1;
    for (auto c : adj[x]) {
        if (!vis[c]) {
            dfs1(c, vis, st, adj);
        }
    }
    st.push(x); // After finishing the node, push it to the stack
}

void dfs2(int x, vector<int>& vis, vector<int> transpose[], vector<int>& component) {
    vis[x] = 1;
    component.push_back(x); // Collect nodes in the current SCC
    for (auto c : transpose[x]) {
        if (!vis[c]) {
            dfs2(c, vis, transpose, component);
        }
    }
}

void kosaraju(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);
    stack<int> st;

    // Step 1: First DFS to get the finish times
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs1(i, vis, st, adj);
        }
    }

    // Step 2: Transpose the graph
    vector<int> transpose[n];
    for (int i = 0; i < n; i++) {
        for (auto c : adj[i]) {
            transpose[c].push_back(i); // Reverse the edges
        }
    }

    // Step 3: Second DFS on the transposed graph
    fill(vis.begin(), vis.end(), 0);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            vector<int> component; // To store nodes of the current SCC
            dfs2(node, vis, transpose, component);
            // Now 'component' has one SCC, you can process/store it as needed
        }
    }
}
