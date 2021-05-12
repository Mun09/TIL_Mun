#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

vector<pair<int,int>> v[10001];
bool visited[10001];
int ans_weight=0, final_node=0;
void dfs(int node, int weight){
    if(weight > ans_weight){
        final_node = node;
        ans_weight=weight;
    }
    visited[node]=true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i].first;
        if(!visited[next]){
            dfs(next, weight+v[node][i].second);
        }
    }
}
int main(){
    int n; cin >> n;
    for(int i=0; i<n-1; i++){
        int root, next, weight;
        cin >> root >> next >> weight;
        v[root].push_back(make_pair(next,weight));
        v[next].push_back(make_pair(root,weight));
    }

    memset(visited, false, sizeof(visited));
    dfs(1,0);
    ans_weight=0;
    memset(visited, false, sizeof(visited));
    dfs(final_node,0);
    cout << ans_weight <<endl;
    return 0;
}