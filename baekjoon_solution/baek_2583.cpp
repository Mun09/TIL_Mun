#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int loc[105][105],cnt=0;
int arr1[4]={0,0,-1,1};
int arr2[4]={1,-1,0,0};
vector<int> ve;
int m, n, k;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    loc[x][y]=1;
    int ans=1;
    while(!q.empty()){
        int a=q.front().first, b=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int newx=a+arr1[i], newy=b+arr2[i];
            if(newx>=0 && newy>=0 && newx<m && newy <n && !loc[newx][newy]){
                q.push({newx,newy});
                loc[newx][newy]=1;
                ans++;
            }
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << loc[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    ve.push_back(ans);
    cnt++;
    
}
int main(){
    cin >> m >> n >> k;
    
    for(int i=0; i<k; i++){
        int x,y,x_next,y_next;
        cin >> x >> y >> x_next >> y_next;
        y=m-y, y_next = m-y_next;
        for(int j=y_next; j<y; j++){
            for(int k=x; k<x_next; k++){
                loc[j][k]=1;
            }
        }
    }
  
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!loc[i][j]){
                bfs(i,j);
            }
        }
    }
    cout << cnt << endl;
    sort(ve.begin(), ve.end());
    for(auto i:ve)
        cout << i << ' ';
    return 0;
}