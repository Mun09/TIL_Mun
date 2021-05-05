#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int arr[2000]={0,};
int main(){

    istream::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    pair<int, int> p[n];

    for(int i=1; i<=n; i++){
        cin >> p[i].first >> p[i].second;
    }

    for(int i=n; i>=1; i--){

        int a = i+p[i].first;
        if(a>n+1) arr[i]=arr[i+1];
        else{
            arr[i] = max(arr[i+1], arr[a]+p[i].second);
        }
    }

    cout << arr[1];
}
