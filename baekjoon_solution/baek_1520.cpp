#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

vector<vector<int>> v(510,vector<int>(510));
vector<vector<int>> dp(510,vector<int>(510,0));
int arr1[]={0,0,1,-1};
int arr2[]={1,-1,0,0};
int n, m; 
int bfs(int x, int y){
    if(x==n && y==m){return 1;}
    else if(dp[x][y]==-1){
        dp[x][y]=0;
        for(int i=0; i<4; i++){
            int addx=x+arr1[i], addy=y+arr2[i];
            if(addx>=1 && addx <=n && addy >=1 && addy <=m && v[addx][addy]<v[x][y]){
                dp[x][y]+=bfs(addx,addy);
            }
        }
    }
    return dp[x][y];
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> v[i][j];
            dp[i][j]=-1;
        }
    }
    
    cout << bfs(1,1) << endl;
    return 0;
}