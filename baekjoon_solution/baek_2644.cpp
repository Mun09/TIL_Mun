#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

const int MAX = 1000005;
int A,B;
vector<int> relation[101];
int tree[101];

int find(void){
    queue<int> q;
    q.push(A);

    while(!q.empty()){
    int next = q.front();
    q.pop();

    if(next==B)
        return tree[B];
    for(int i=0; i<relation[next].size(); i++){
        int a = relation[next][i];
        if(tree[a]==0){
            q.push(a);
            tree[a] = tree[next]+1;
        }
    }
    }
    return -1;
     
}
int main(){
    
    int n; cin >> n;
    cin >> A >> B;
    int m; cin >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        relation[x].push_back(y);
        relation[y].push_back(x);
    }
    cout << find() <<endl;
    return 0;
    
}