#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int loc[1005][1005];
int col, row;
int visited1[1005][1005];
int visited2[1005][1005];
int arr1[]={0,0,1,-1};
int arr2[]={1,-1,0,0};
int bfs(){
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0,0,1,1));
    visited1[0][0]=true;
    while(!q.empty()){
        int x=get<0>(q.front()), y=get<1>(q.front());
        int used=get<2>(q.front()),ans=get<3>(q.front());
        if(x==col-1 && y==row-1) return ans;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x=x+arr1[i], next_y=y+arr2[i];
            if(next_x>=0 && next_x <col && next_y>=0 && next_y <row){
                if(loc[next_x][next_y] && used && visited2[next_x][next_y]){
                q.push(make_tuple(next_x,next_y,0,ans+1));
                visited1[next_x][next_y]=0;
            }
            else if(!loc[next_x][next_y]){
                if(used && visited2[next_x][next_y]){
                q.push(make_tuple(next_x,next_y,used,ans+1));
                visited2[next_x][next_y]=0;
            }
            else if(!used && visited1[next_x][next_y]){
                q.push(make_tuple(next_x,next_y,used,ans+1));
                visited1[next_x][next_y]=0;
            }
            }
        }
    }
    }
    return -1;
}

int main(){
cin >> col >> row;
for(int i=0; i<col; i++){
    string a;
    cin >> a;
    for(int j=0; j<row; j++){
        loc[i][j] = a[j]-'0';
    }
}
memset(visited1,1,sizeof(visited1));
memset(visited2,1,sizeof(visited2));
cout << bfs() << endl;
return 0;
}