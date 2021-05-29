#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
ll c=0;
int ans=0;
int main(){
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--){
        int x; cin >> x;
        pq.push(x), c+=x, ans++;
        if(c<0){
            c-=pq.top(), pq.pop(), ans--;
        }
    }
    cout << ans << endl;
    return 0;
}