#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main(){
    
   int t;
   cin >> t;
   while(t--){
       int n;
       cin >> n;

       string a;
       cin >> a;

       deque<pair<char, int>> de;
       vector<int> v;
        de.push_front(make_pair(a[0],1));
        v.push_back(1);
        int order=1;
       for(int i=1; i<n; i++){
           
               if(de.front().first!=a[i]){
                   
                   int x = de.front().second;
                   v.push_back(x);
                   de.pop_front();
                   de.push_back(make_pair(a[i],x));
               }
               else if(de.back().first!=a[i]){
                    int x = de.back().second;
                       v.push_back(x);
                   de.pop_back();
                   de.push_front(make_pair(a[i],x));
               }
               else{
                   order++;
                   de.push_front(make_pair(a[i],order));
                   v.push_back(order);
                   
               }
           
       }

       cout << order << endl;
       for(auto i:v){cout << i << ' ';}
       cout << endl;

   }

   return 0;
}