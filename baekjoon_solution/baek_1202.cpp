#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n';
using namespace std;
const int MAX = 300000;
pair<int, int> jewelry[MAX];
int bag[MAX];
priority_queue<int> qe;
int main()
{

    istream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for(int i=0; i<N; i++){cin >> jewelry[i].first >> jewelry[i].second;}
    for(int i=0; i<K; i++){cin >> bag[i];}

    sort(jewelry, jewelry+N);
    sort(bag, bag+K);
    int idx=0;
    ll sum=0;

    for(int i=0; i<K; i++){

        while(idx < N && jewelry[idx].first <= bag[i])
            qe.push(jewelry[idx++].second);
        if(!qe.empty()){
            sum+=qe.top();
            qe.pop();
        }
    }

    cout << sum;
    return 0;
}