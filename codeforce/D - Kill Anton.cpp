#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve(){
    string c="ANTO";
    sort(c.begin(), c.end());
    string a;
    cin >> a;
    ll best=-1;
    string bests="";
    do{
        string cur=a;
        string res="";
        ll score=0;
        for(char l:c){
            string another="";
            ll f=0;
            for(char t:cur){
                if(t==l){score+=f; res+=t;}
                else{f++; another+=t;}
            }
            cur=another;
        }
        if(best<score){
            bests=res;
            best=score;
        }
    }
    while(next_permutation(c.begin(), c.end()));
    cout << bests << endl;
}
int main(){
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}