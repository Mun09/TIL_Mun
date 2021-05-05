#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int arr[1100][1100];

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(arr[0], arr[0]+1100*1100, -1);
    queue<pair<int, int>> q1, q2;
    int n, m;

    cin >> m >> n;
    
    for(int i=1; i<=n; i++){
        int a;
        for(int j=1; j<=m; j++){
            cin >> a;
            arr[i][j]=a;

            if(a==1){
                q1.push(make_pair(i,j));
            } 
        }
    }
    int cnt=-1;

    while(!q1.empty()){
        int t= q1.size();

        for(int k=0; k<t; k++){

        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();

        for(int i=-1; i<=1; i++){
                if(arr[x+i][y]==0){
                    arr[x+i][y]=1;
                    q2.push(make_pair(x+i,y));
                }
        }
        for(int i=-1; i<=1; i++){
                if(arr[x][y+i]==0){
                    arr[x][y+i]=1;
                    q2.push(make_pair(x,y+i));
                }
        }

    }

    q1=q2;
    q2 = queue<pair<int, int>>();
    cnt++;

    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]==0){
                cnt=-1;
                break;
            }
        }
        if(cnt==-1){break;}
    }

    cout << cnt;
}