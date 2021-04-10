#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    map<int, int> m;

    for(int i=0; i< n; i++){
        int x;
        cin >> x;
        m[x]++;
    }

    priority_queue<pair<int, int>> q;
    
    for(auto iter = m.begin(); iter!= m.end(); iter++){
        q.push({iter->second, iter->first});
    }

    int size = n;
    while(q.size()>=2){

        auto x1 = q.top().first, y1 = q.top().second;
        q.pop();
        auto x2 = q.top().first, y2 = q.top().second;
        q.pop();

        x1--;
        x2--;
        size-=2;

        if(x1){
            q.push({x1, y1});
        }
        if(x2){
            q.push({x2, y2});
        }
    }

    cout << size << '\n';
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
