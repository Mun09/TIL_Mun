#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;

    n+=2;

    vector<int> v;
    ll sum=0;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    sort(v.begin(), v.end());

    if(sum-v[n-1] == 2*v[n-2]){
        v[n-1] = 0, v[n-2] = 0;
    }
    else{
        int i = n-2;
        while(sum-v[i] < 2*v[n-1]){
            i--;
        }
        if(i>=0 && sum-v[i]==2*v[n-1]){
                v[i] = 0, v[n-1] = 0;
        }
    }

    if(v[n-1]==0){
    for(int j=0; j<n; j++){
        if(v[j]){printf("%d ", v[j]);}
    }
    printf("\n");
    }
    else{printf("-1\n");}
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}