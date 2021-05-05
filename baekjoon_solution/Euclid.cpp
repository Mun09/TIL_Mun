#include <stdio.h>
#include <iostream>
using namespace std;

int Euclid(int a,int b);
int main(){
  int array[5];
  for (int i=0; i<5; i++){
    cin >> array[i];
  }
  int tmp=Euclid(array[0],array[1]);

  for(int i=2; i<5; i++){
    tmp=Euclid(tmp,array[i]);
  }

  cout << tmp;
}

int Euclid(int a,int b){
  int tmp3;
  tmp3=a;
  a=max(a,b);
  b=min(tmp3,b);

  int tmp=b;
  int tmp2;


  while(tmp!=0){
    tmp2=min(a%tmp,tmp);
    a=max(a%tmp,tmp);
    tmp=tmp2;
  }

  return a;
}
