#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

const int MAX=20005;
vector<int> v[MAX];
bool visited[MAX];
int color[MAX];
bool check=false;
void bfs(int node, int last){
    if(visited[node])
        return;
    color[node]=3-last;
    visited[node]=true;
    for(int i=0; i<v[node].size(); i++){
        int a=v[node][i];
        if(color[a]!=0 && color[a]==color[node]){check=true; break;}
        bfs(a,color[node]);
    }
}
void solve(){
    int V, L;
    cin >> V >> L;
    memset(visited,false,sizeof(visited));
    memset(color,0,sizeof(color));
    for(int i=0; i<L; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1; i<=V; i++){
        if(!visited[i]){
        bfs(i,1);
        }
    }
    puts(!check?"YES":"NO");
    for(int i=1; i<=V; i++){v[i].clear();}
    check=false;
}
int main(){
    int t; cin>>t;
    while(t--){solve();}
}