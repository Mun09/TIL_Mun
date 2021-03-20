#include <iostream>
#include <math.h>
using namespace std;
int fivenumber(int n){
    int t;
    int number=0;
    for(int i=1; ; i++){
        t=n/pow(5,i);
        
        if (t==0){
            break;
        }
        else{
            number+=t;
        }
    }

    return number;
}
int twonumber(int n){
    int t;
    int number=0;
    for(int i=1; ; i++){
        t=n/pow(2,i);
        
        if (t==0){
            break;
        }
        else{
            number+=t;
        }
    }

    return number;
}

int main() {
    int a,b;
    cin >> a >> b;

    cout << min(fivenumber(a)-fivenumber(a-b)-fivenumber(b),twonumber(a)-twonumber(a-b)-twonumber(b));
    
}