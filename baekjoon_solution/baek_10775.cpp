#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <memory.h>
using namespace std;
#define endl '\n';
typedef long long ll;
const int Max = 100001;
int p[Max],cnt;

int Find(int x){
    if(p[x]<0) return x;
    return p[x] = Find(p[x]);
}
int main(){

    istream::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P;
    cin >> G >> P;
    
    memset(p,-1,sizeof(p));

    for(int i=0; i<P; i++){
        int a;
        cin >> a;

        int tmp = Find(a);
        if(!tmp) break;
        cnt++;
        p[tmp]=tmp-1;
    }

    cout << cnt;
    return 0;
}  