#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int location[55][55],cnt;
queue<pair<int,int>> q;
int temp[3]={-1,0,1};

void bfs(int x, int y){
    location[x][y]=0;
    q.push({x,y});
    while(!q.empty()){
        int top_x=q.front().first, top_y=q.front().second;
        q.pop();
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int a = top_x+temp[i],b=top_y+temp[j];
                if(a>=0 && b>=0){
                    if(location[a][b]){
                    q.push({a,b});
                    location[a][b]=0;
                    }
                }
            }
        }
    }
    cnt++;
}
int main(){
    int x=-1, y=-1;
    while(1){
        cin >> x >> y;
        if(x==0 && y==0) break;
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                cin >> location[i][j];
            }
        }

        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
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