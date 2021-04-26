#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
typedef long long ll;
using namespace std;

int main(){

    istream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string a;
    cin >> a;
    char temp = a[0];
    int cnt_0=0, cnt_1=0;
    for(int i=1; i<a.length(); i++){
        if(temp != a[i]){
            
            if(temp == '0')
                cnt_0++;
            else
                cnt_1++;
            temp = a[i];
        }
    }

    if(temp == '0')
        cnt_0++;
    else
        cnt_1++;

    cout << min(cnt_1,cnt_0);
}