#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <memory.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int arr[500005];
int n, m;

int main(){
    istream::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string str;
    cin >> str;

    deque<char> dq;

    for(int i=0; i<n; i++){
        while(m && !dq.empty() && dq.back() < str[i]){
            dq.pop_back();
            m--;
        }
        dq.push_back(str[i]);
    }

    for(int j=0; j<dq.size()-m; j++){
        cout << dq[j];
    }
    return 0;
}