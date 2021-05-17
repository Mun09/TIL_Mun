#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int loc[305][305],n;
bool visited[305][305];
int arr1[]={2,1,-1,-2,-2,-1,1,2};
int arr2[]={1,2,2,1,-1,-2,-2,-1};
int dfs(int x,int y,int newx,int newy){
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visited[x][y]=true;

    while(!q.empty()){
        int a=q.front().first.first, b=q.front().first.second,chasu=q.front().second;
        if(a==newx && b==newy){
            return chasu;
        }
        q.pop();
        for(int i=0; i<8; i++){
            int newa=a+arr1[i], newb=b+arr2[i];
            if(newa>=0 && newa<n && newb>=0 && newb<n && !visited[newa][newb]){
                visited[newa][newb]=true;
                q.push({{newa,newb},chasu+1});
            }
        }
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int x,y,newx,newy;
        cin >> x >> y >> newx >> newy;
        memset(visited,false,sizeof(visited));
        cout << dfs(x,y,newx,newy) << endl;
    }
}