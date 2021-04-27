#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n';
using namespace std;

int main()
{

    istream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    if(N==1 || M==1){
        cout << 1;
    }
    else if(N<3 && M<9){
        cout << 1 + (M-1)/2;
    }
    else if(N>=3 && M<5){
        cout << M;
    }
    else{
        if(N<3 || M<7){cout << 4;}
        else{
        cout << 1+4+(M-7);
        }
    }
    
}