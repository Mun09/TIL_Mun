#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

const int MAX=100005;
int arr[MAX];
int main(){
    
   int t;
   cin >> t;
   while(t--){
       int n;
       cin >> n;

        int t=1e9+5, pos=-1;
       for(int i=0; i<n; i++){
           int a; cin >> a;
           if(t>a) t=a, pos=i;
       }

        cout << n-1 << endl;
       for(int i=0; i<n; i++){
           if(pos==i) continue;
           cout << pos+1 << ' ' << i+1 << ' ' << t << ' ' << t+abs(pos-i) << endl;
       }
       
   }
}