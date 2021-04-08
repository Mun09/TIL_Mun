#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
int arr[100][100]={0,}, cnt=0;
vector<int> v;

void building(int i, int j){

cnt++;
queue<pair<int,int>> q;
q.push(make_pair(i,j));
arr[i][j]=0;
int x,y;
int count=1;

while(!q.empty()){
    x=q.front().first;
    y=q.front().second;
    q.pop();

    for(int k=-1; k<=1; k++){
        if(arr[x+k][y]){
            q.push(make_pair(x+k,y));
            arr[x+k][y]=0;
            count++;
        }
    }
    for(int k=-1; k<=1; k++){
        if(arr[x][y+k]){
            q.push(make_pair(x,y+k));
            arr[x][y+k]=0;
            count++;
        }
    }
}
v.push_back(count);
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        string a;
        cin >> a;
        for(int j=1; j<=n; j++){
            arr[i][j] = a[j-1] - '0';
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j])
                building(i,j);
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << '\n';
    for(int i:v){cout << i << '\n';}
}