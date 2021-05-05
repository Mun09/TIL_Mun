#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
 int array[100]={0,};
 int array_natural[100];
 for(int i=0; i<100; i++){
array_natural[i]=i+1;
 }
for(int i=1; i<100; i++){
    if(array[i]==0){
        int t=array_natural[i];
        for(int j=i+t; j<100; j+=t){

            array[j]=1;

        }
    }
}

for(int i=0; i<100; i++){
    if (array[i]==0){
        printf("%d\n",array_natural[i]);
    }
}

}