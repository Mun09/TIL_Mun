#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main() {

    iostream::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n;
    ll value;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++){cin >> v[i];}
    cin >> value;

    sort(v.begin(), v.end());
    
    ll left = 0, right = v.back();;
    ll result=0;
    ll mid, ans;
    ll sum;

    while(left <= right){

        mid = (left+right)/2;
        sum=0;

        for(int i=0; i<n; i++){
            if(mid > v[i]){sum+=v[i];}
            else{sum+=mid;}
        }

        if(sum <= value){
            left = mid +1;
        }
        else{
            right = mid -1;
        }

        if(sum <= value && sum > result){
            result = max(result, sum);
            ans = mid;
        }
    }

    cout << ans; 
}
