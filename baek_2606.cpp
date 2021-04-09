#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<int> v[200];
int arr[200]={0,};

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, pair;
    queue<int> q;
    int a, b;

    cin >> n >> pair;

    for(int i=0; i< pair; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;

    q.push(1);
    arr[1]=1;

    while(!q.empty()){

        int t = q.front();
        q.pop();

        for(int i=0; i < v[t].size(); i++){
            int y = v[t][i];
            if(!arr[y]){
                arr[y]=1;
                q.push(y);
                cnt++;
            }
        }
    }

    cout << cnt;

}