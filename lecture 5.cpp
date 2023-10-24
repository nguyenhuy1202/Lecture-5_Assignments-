#include<bits/stdc++.h>
using namespace std;

vector<int> tree[100005];
int height[100005];
bool visited[100005];

void dfs(int node, int h) {
    visited[node] = true;
    height[node] = h;
    for(int i=0; i<tree[node].size(); i++) {
        if(!visited[tree[node][i]]) {
            dfs(tree[node][i], h+1);
        }
    }
}

void preorder(int node) {
    cout << node << " ";
    for(int i=0; i<tree[node].size(); i++) {
        preorder(tree[node][i]);
    }
}

void postorder(int node) {
    for(int i=0; i<tree[node].size(); i++) {
        postorder(tree[node][i]);
    }
    cout << node << " ";
}

bool isBinaryTree(int node) {
    if(tree[node].size() > 2) return false;
    for(int i=0; i<tree[node].size(); i++) {
        if(!isBinaryTree(tree[node][i])) return false;
    }
    return true;
}

void inorder(int node) {
    if(tree[node].size() > 0) inorder(tree[node][0]);
    cout << node << " ";
    if(tree[node].size() > 1) inorder(tree[node][1]);
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }
    
    dfs(1, 1);
    
    cout << *max_element(height+1, height+N+1) << endl;
    
    preorder(1);
    cout << endl;
    
    postorder(1);
    cout << endl;
    
    if(isBinaryTree(1)) {
        inorder(1);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
    
    return 0;
}
