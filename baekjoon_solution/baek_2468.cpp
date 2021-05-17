#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int N,cnt;
int min_value=105,max_value=-1;
int loc[105][105], loc_copy[105][105];
int a[4]={0,0,1,-1}, b[4]={1,-1,0,0};
void copy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            loc_copy[i][j]=loc[i][j];
        }
    }
}
void colorful(int height, int k, int t){
queue<pair<int,int>> q;
    q.push({k,t});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        loc_copy[x][y]=0;
        q.pop();
        for(int i=0; i<4; i++){
            int new_x=x+a[i], new_y=y+b[i];
            if(new_x>=0 && new_y>=0){
                if(loc_copy[new_x][new_y]>=height){
                    loc_copy[new_x][new_y]=0;
                    q.push({new_x,new_y});
                }
            }
        }
    }
    cnt++;
}
int bfs(int height){
    int x, y;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(loc_copy[i][j]>=height){
                colorful(height, i, j);
            }
        }
    }
    
    return cnt;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> loc[i][j];
            min_value=min(min_value, loc[i][j]);
            max_value=max(max_value, loc[i][j]);
        }
    }
    int ans=-1;
    for(int i=min_value; i<=max_value; i++){
        copy();
        ans=max(bfs(i),ans);
        cnt=0;
    }
    cout << ans;
}