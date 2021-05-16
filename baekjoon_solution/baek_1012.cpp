#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int location[55][55],cnt;
int arr[3]={-1,0,1};
queue<pair<int,int>> q;

void plusing(int top_x, int top_y){
    for(int i=0; i<3; i++){
        int a = top_x+arr[i];
        if(a>=0){
            if(location[a][top_y]){
            q.push({a,top_y});
            location[a][top_y]=0;}
        }
    }
    for(int i=0; i<3; i++){
        int a = top_y+arr[i];
        if(a>=0){
            if(location[top_x][a]){
            q.push({top_x,a});
            location[top_x][a]=0;}
        }
    }
}
void bfs(int x, int y){
    q.push({x,y});
    location[x][y]=0;
    while(!q.empty()){
        int top_x = q.front().first, top_y=q.front().second;
        q.pop();
        plusing(top_x, top_y);
    }
    cnt++;

}
int main(){
    int t;
    cin >> t;
    while(t--){
    int n, m, k;
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        location[y][x]=1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(location[i][j]){
                bfs(i,j);
            }
        }
    }
    cout << cnt << endl;
    cnt=0;
    }
    return 0;
}