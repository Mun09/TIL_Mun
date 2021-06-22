#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
    int t; 
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        map<int, long long> m;
        long long ans=0;
        for(int i=1; i<=n; i++){
            int a; cin >> a;
            ans+=m[a]*(n-i+1);
            m[a]+=i;
        }
        cout << ans << endl;
    }
}