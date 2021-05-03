#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <memory.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main(){

    istream::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    for(int i=0; i<m; i++){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a+b); 
        pq.push(b+a);
    }

    ll sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }

    cout << sum;
}
