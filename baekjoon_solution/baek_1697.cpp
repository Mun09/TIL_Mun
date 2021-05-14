#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int top=-1;
int node;
bool visited[200005];
queue <pair<int,int>> q;
int main(){
    int a, b;
    cin >> a >> b;
    q.push({a,0});
    memset(visited, false, sizeof(visited));
    while(top!=b){
        top = q.front().first;
        node = q.front().second;
        if(visited[top]){
            q.pop();
            continue;
        }
        visited[top] = true;
        if(top>0){
        q.push(make_pair(top-1,node+1));
        }
        if(top < b){
        q.push(make_pair(top+1,node+1));
        q.push(make_pair(2*top,node+1));
        }
        q.pop();
    }
    cout << node << endl;
    return 0;
}