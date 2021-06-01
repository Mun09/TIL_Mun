#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n,t;
struct col{
    int x, y;
};
int dp[1010][1010];
col fir[1010], sec[1010];
vector<int> v;
int func(int c1, int c2){
    if(c1==t || c2==t)
        return 0;
    int &ref=dp[c1][c2];
    if(ref!=-1)
        return ref;
    int np=max(c1,c2)+1;
    int a1=abs(fir[c1].x-fir[np].x)+abs(fir[c1].y-fir[np].y);
    int a2=func(np, c2)+a1;

    int b1=abs(sec[np].x-sec[c2].x)+abs(sec[np].y-sec[c2].y);
    int b2=func(c1,np) + b1;
    return ref=min(b2, a2);
}
void tracking(int c1, int c2){
    if(c1==t || c2==t)
        return;
    int np=max(c1,c2)+1;
    int a1=abs(fir[c1].x-fir[np].x)+abs(fir[c1].y-fir[np].y);
    int a2=func(np, c2)+a1;

    int b1=abs(sec[np].x-sec[c2].x)+abs(sec[np].y-sec[c2].y);
    int b2=func(c1,np) + b1;
    
    if(b2>a2){
        v.push_back(1);
        tracking(np,c2);
    }
    else{
        v.push_back(2);
        tracking(c1,np);
    }
}
int main(){
    scanf("%d %d",&n, &t);
    for(int i=1; i<=t; i++){
        scanf("%d %d",&fir[i].x, &fir[i].y);
        sec[i]={fir[i].x,fir[i].y};
    }
    fir[0]={1,1}, sec[0]={n,n};
    memset(dp, -1, sizeof(dp));
    printf("%d\n",func(0,0));
    tracking(0,0);
    for(auto i:v)
        printf("%d\n",i);
    return 0;
}