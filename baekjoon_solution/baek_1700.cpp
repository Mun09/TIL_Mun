#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n';
typedef long long ll;

const int Max = 101;
int plug[Max], schedule[Max];


int main(){

    int n, k, result=0;
    cin >> n >> k;

    for(int i=0; i<k; i++){
        cin >> schedule[i];
    }

    for(int i=0; i<k; i++){

        bool check = false;
        for(int j=0; j<n; j++)
            if(plug[j]==schedule[i]){
                check = true;
                break;
            }
        if(check)
            continue;
        
        for(int j=0; j<n; j++){
            if(!plug[j]){
                plug[j]=schedule[i];
                check = true;
                break;
            }
        }
        if(check)
            continue;
        
        int idx_schedule=0,idx_plug;
        for(int j=0; j<n; j++){
            int lastidx=0;
            for(int t=i+1; t<k; t++){
                if(schedule[t]==plug[j])
                    break;
                lastidx++;
            }
            if(idx_schedule < lastidx){
                idx_schedule = lastidx;
                idx_plug = j;
            }
        }

        plug[idx_plug] = schedule[i];
        result++;
    }
    
   cout << result;
   return 0;
}  