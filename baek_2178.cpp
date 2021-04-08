#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

int main(){
  
    int n, m;
    cin >> n >> m;

    int arr[200][200]={0,};
    queue<pair<int, int>> q;

    for(int i=1; i<=n; i++){
        string a;
        cin >> a;
        for(int j=1; j<=m; j++){
            arr[i][j] = a[j-1] - '0';
        }
    }

    q.push(make_pair(1,1));
    arr[1][1]=0;
    int x=1, y=1, cnt=0, count=1;
    int tmp;
    while(arr[n][m]){
        
        tmp=0;
        cnt++;

        for(int i=0; i<count; i++){

        x=q.front().first;
        y=q.front().second;
        q.pop();

            for(int j=-1; j<=1; j++){
                if(arr[x][y+j]){
                        q.push(make_pair(x, y+j));
                        arr[x][y+j]=0;
                        tmp++;
                    }
            }

            for(int j=-1; j<=1; j++){
                if(arr[x+j][y]){
                        q.push(make_pair(x+j, y));
                        arr[x+j][y]=0;
                        tmp++;
                    }
            }
        }
        count=tmp;
        
    }

    cout << cnt+1;

}