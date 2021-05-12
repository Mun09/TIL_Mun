#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

vector<pair<int,ll>> v[100001];
bool visited[100001];
ll ans_weight=0, final_node=1;

void dfs(int node, ll weight){
    if(visited[node])
        return;
    visited[node]=true;

    if(ans_weight<weight){
        ans_weight=weight;
        final_node=node;
    }

    for(int i=0; i<v[node].size(); i++){
        dfs(v[node][i].first, weight+v[node][i].second);
    }
}
int main(){
    int V;
    cin >> V;
    for(int i=0; i<V; i++){
        int root;
        cin >> root;
        int next;
        ll weight;
        while(true){
            cin >> next;
            if(next==-1){break;}
            cin >> weight;
            v[root].push_back(make_pair(next,weight));
            v[next].push_back(make_pair(root,weight));
        }
    }
    
    memset(visited,false,sizeof(visited));
    dfs(1,0);
    ans_weight=0;
    memset(visited,false,sizeof(visited));
    dfs(final_node,0);
    cout << ans_weight<< endl;
    return 0;
}