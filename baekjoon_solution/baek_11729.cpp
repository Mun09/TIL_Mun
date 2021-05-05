#include <iostream>
#include <math.h>
using namespace std;
#define endl '\n';

int Hanoi(int from, int to, int n) // from번 기둥에서 to번 기둥으로 n개의 원반을 이동.
{
    if(n == 1)
    {
        cout << from << ' ' << to << endl;
        return 0;
    }

    Hanoi(from, 6-from-to, n-1);
    cout << from << ' ' << to << endl;
    Hanoi(6-from-to, to, n-1);
    return 0;
}

int main(){

    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N;
    cin >> N;
    cout << (1<<N)-1 << endl;
    Hanoi(1,3,N);
}