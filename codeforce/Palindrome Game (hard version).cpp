#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int isitpal(string s){
    int n=s.length();
    int isit=1;
    int error=0;
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-i-1]){
            isit=0;
            break;
        }
    }
    return isit;
}
int main(){
    int t; 
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt=0;
        for(int i=0; i<n; i++)
            if(s[i]=='0')
                cnt++;
        
        if(isitpal(s)==1){
        if(n%2 && s[n/2]=='0' && cnt>=3){
            cout << "ALICE";
        }
        else{
            cout << "BOB";
        }
        }
        else{
            if(n%2 && s[n/2]=='0' && cnt==2){
                cout << "DRAW";
            }
            else{
            cout << "ALICE";
            }
        }
        cout << endl;
    }
}