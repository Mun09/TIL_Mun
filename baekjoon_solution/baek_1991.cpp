#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

char arr[30][3] = {'.',};

void first(char a){
    if(a=='.') return;
    else{
    cout << a;
    first(arr[a-'A'][0]);
    first(arr[a-'A'][1]);
    }
}
void second(char a){
    if(a=='.') return;
    else{
    second(arr[a-'A'][0]);
    cout << a;
    second(arr[a-'A'][1]);
    }
}
void third(char a){
    if(a=='.') return;
    else{
    third(arr[a-'A'][0]);
    third(arr[a-'A'][1]);
    cout << a;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char c, a, b;
        cin >> c >> a >> b;
        arr[c-'A'][0]=a;
        arr[c-'A'][1]=b;
    }

    first('A');
    cout << endl;
    second('A');
    cout << endl;
    third('A');
    cout << endl;
    return 0;
}