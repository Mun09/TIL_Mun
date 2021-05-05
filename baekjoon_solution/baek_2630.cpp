#include <iostream>
#include <vector>
using namespace std;
#define endl '\n';

int N;
int arr[200][200];
void cutting(int num, int y, int x, int (*arr)[200]);

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << '(';
    cutting(N, 0, 0, arr);
    cout << ')';

   
}

void cutting(int num, int y, int x, int (*arr)[200]){
    int test=1;

    int i=y;
    int j=x;

    while(i<y+num){
        
        while(j<x+num){
            if(arr[y][x]!=arr[i][j]){
                test=0;
                break;
            }
            else{
                j++;
                
            }
        }
        i++;
        j=x;
        if(!test){
            break;
        }
    }


    if(!test){
    int thing= num/2;

    if(thing==1){
        cout<<  arr[y][x] << arr[y][x+1] << arr[y+1][x] << arr[y+1][x+1] ;
    }
    else{
    cout <<'(';
    cutting(thing,y,x, arr);
    cutting(thing, y, x+thing, arr);
    cutting(thing, y+thing, x, arr);
    cutting(thing, y+thing, x+thing ,arr);
    cout <<')'; 
    }
    }
    else{
            
            if(arr[y][x]==1){cout << 1;}
            else{cout << 0;}
               
    }

}
