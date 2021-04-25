#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int v[105], sum = 0;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        sum+=v[i];
    }

    bitset<200005> b;
    b[0]=1;
    for(int i=1; i<=n; i++){
        b|=(b<<v[i]);
    }    

    if(sum%2==0 && b[sum/2]){
        cout << 1 << endl;
        pair<int, int> mn(20,0);
        for(int i=1; i<=n; i++){
            mn = min(mn, make_pair(__builtin_ctz(v[i]),i));
        }
        cout << mn.second;
    }
    else{
        cout << 0;
    }


}