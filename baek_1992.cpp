#include <iostream>
using namespace std;
#define endl '\n';

char arr[65][65];
void screen(int size, int y, int x, char (*arr)[65]);
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    
    screen(N,0,0,arr);
    
  
}

void screen(int size, int y, int x, char (*arr)[65]){

    int i=y;
    int j=x;

    int test=1;

    while(i<y+size){

        while(j<x+size){
            if(arr[y][x]!=arr[i][j]){
                test--;
                break;
            }
            j++;
        }
        i++;
        j=x;
        if(!test){
            break;
        }
    }

    if(test){
        if(arr[y][x]=='1'){
            cout << 1;
        }
        else{cout << 0;}
    }
    else{
        cout << '(';
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                
                screen(size/2, y+size*i/2, x+size*j/2, arr);
                
            }
        }
        cout << ')';
    }
}
