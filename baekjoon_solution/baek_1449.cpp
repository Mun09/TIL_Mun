#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int main(){

    int N, L;
    cin >> N >> L;

    vector<int> v(N);
    for(auto &i:v)
        cin >> i;
    
    int idx=0, cnt=0;
    sort(v.begin(), v.end());
    while(idx<N){
        int t=idx;
        cnt++;
        while(t<N && v[idx]+L-1>=v[t])
            t++;
        idx=t;
    }
    cout << cnt;
}