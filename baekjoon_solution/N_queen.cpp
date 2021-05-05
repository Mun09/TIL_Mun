#include <stdio.h>
#include <stdlib.h>

int N;
int count;
int col[255]={0,};
void queen(int);
int judge(int);
int main(){

  scanf("%d",&N);

  queen(0);

  printf("%d",count);
}

void queen(int number){
  if(judge(number)){
    if(number==N){
      count++;
    }
    else{
      for(int j=0; j<N; j++){
        col[number+1]=j;
        queen(number+1);
      }
    }
  }
}

int judge(int number){
  int i=1;
  int missing=1;

  while(missing && i<number){
    if(col[i]==col[number] || abs(col[i]-col[number])==(number-i)){
      missing=0;
    }
    i+=1;
  }
  return missing;
}