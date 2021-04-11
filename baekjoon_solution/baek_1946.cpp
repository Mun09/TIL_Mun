#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void solve(){

    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2,0));

    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1]; 
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int tmp = v[0][1];

    for(int i=1; i<n; i++){

        if(v[i][1] < tmp){
            cnt++;
            tmp = v[i][1];
        }
    }

    cout << cnt << '\n';
}

int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}