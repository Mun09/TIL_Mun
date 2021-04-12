#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        string arr;
        cin >> arr;
        int len = arr.length();

        for(int i=0; i<len; i++){
            if(arr[i]!=arr[len-i-1]){
                if(arr[i]=='?'){
                    arr[i]=arr[len-i-1];
                }
                else if(arr[len-i-1]=='?'){
                    arr[len-i-1] = arr[i];
                }
                else{
                    a=-100;
                    b=-100;
                    break;
                }
            }
        }

        for(int i=0; i<len; i++){
            if(arr[i]=='0'){a--;}
            else if(arr[i]=='1'){b--;}
        }

        
        for(int i=0; i< len/2; i++){
            if(arr[i]=='?'){
                if(a>1){a-=2; arr[i]='0'; arr[len-i-1]='0';}
                else{b-=2; arr[i]='1'; arr[len-i-1]='1';}
            }
        }
        if(len %2==1){
            if(a==1){arr[len/2]='0'; a--;}
            else if(b==1){arr[len/2]='1'; b--;}
        }

        if(a==0 && b==0){
                for(int i=0; i<len; i++){
                    cout << arr[i];
                }
                cout << '\n';
        }
            else{cout << -1 << '\n';}
    }
}