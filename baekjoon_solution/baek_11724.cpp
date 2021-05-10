#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

vector<int> v[1005];
bool visited[1005];
int n;
int dfs(void){
    int ans=0;
    for(int i=1; i<=n; i++){
        if(!visited[i] && v[i].size()>0){
            ans++;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int next = q.front();
                q.pop();
                if(!visited[next]){
                    visited[next]=true;
                    for(int j=0; j<v[next].size(); j++)
                        q.push(v[next][j]);
                }
            }
        }
    }
    return ans;
}
int main(){
    int line;
    cin >> n >> line;
    for(int i=0; i<line; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=1000; i++){
        v[i].push_back(i);
    }
    cout << dfs()<< endl;
    return 0;
}