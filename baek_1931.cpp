#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SortSecCol(const vector<int>& v1, const vector<int>& v2)
{
    if(v1[1]==v2[1]){
        return v1[0] < v2[0];
    }
    return v1[1] < v2[1];
}
int count1=1;

int main() {
    int n;
    
    cin >> n;
    
    vector <vector<int>> time(n,vector<int>(2,0)); // n행 2열을 가지는 벡터 선언
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> time[i][j];
        }
    } // 테스트를 위한 임의의 값 배정
 
    sort(time.begin(), time.end(),SortSecCol); // 기준 함수를 정해주지 않음 (기본값 오름차순)
 
    int start=time[0][1];
    for(int i=1; i<n; i++){
        if(start<=time[i][0]){
            start=time[i][1];
            count1++;
        }
    }

    cout << count1<<endl;
    
    for(int i=0; i<n; i++){
        cout << time[i][0]<<' '<<time[i][1]<<endl;
    }
 
    return 0;
}

