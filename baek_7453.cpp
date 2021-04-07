#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll a[4000], b[4000], c[4000], d[4000];

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<ll> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v.push_back(c[i]+d[j]);
        }
    }
    sort(v.begin(), v.end());
    ll result = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            ll value = a[i]+ b[j];
            ll low = lower_bound(v.begin(), v.end(), -value) - v.begin();
            ll high = upper_bound(v.begin(), v.end(), -value) - v.begin();

            if(-value == v[low]){
                result += (high- low); 
            }
        }
    }

    cout << result;
    return 0;
}