#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int pos[500001];
struct Comparator{
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}
    bool operator()(int a, int b){
        if (group[a]!=group[b])
            return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};
vector<int> suffixarray(const string& s){
    int n=s.size();
    int t=1;
    vector<int> group(n+1);
    for(int i=0; i<n; i++) group[i]=s[i];
    group[n]=-1;
    vector<int> perm(n);
    for(int i=0; i<n; i++) perm[i]=i;
    while(t<n){
        Comparator compareUsing2T(group,t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t*=2;
        if(t>=n) break;
        vector<int> newgroup(n+1);
        newgroup[n]=-1;
        newgroup[perm[0]]=0;
        for(int i=1; i<n; i++){
            if(compareUsing2T(perm[i-1], perm[i]))
                newgroup[perm[i]]=newgroup[perm[i-1]]+1;
            else
                newgroup[perm[i]]=newgroup[perm[i-1]];
        }
        group=newgroup;
    }
    return perm;
}
vector<int> makelcp(const string& s, const vector<int>& suffix){
    int n=s.size();
    vector<int> ret(n,0);
    for(int i=0; i<n; i++) pos[suffix[i]]=i;
    for(int i=0, k=0; i<n; i++, k=max(k-1,0)){
        if(pos[i]==n-1) continue;
        for(int j=suffix[pos[i]+1]; s[i+k]==s[j+k]; k++);
        ret[pos[i]]=k;
    }
    return ret;
}
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;
    vector<int> suffix=suffixarray(S);
    vector<int> lcp=makelcp(S,suffix);
    int n=S.size();
    for(auto i:suffix)
        cout << i+1 << ' ';
    cout << endl;
    cout << 'x' << ' ';
    for(int i=0; i<n-1; i++)
        cout << lcp[i] << ' ';
    return 0;
}
