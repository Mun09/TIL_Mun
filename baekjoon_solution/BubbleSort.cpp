#include <stdio.h>
#include <iostream>
using namespace std;
int BubbleSort(int *array, int num_element);
int Swap(int* num);
int main(){
  int arr[10];
  
  for (int i=0; i<10; i++){
    cin >> arr[i];
  }

  int* p=arr;
  BubbleSort(p, 9);
  
  for (int i=0; i<10; i++){
    cout << arr[i] << ' ';
  }
}

int Swap(int* num){
  if(*num>*(num+1)){
    int tmp=*num;
    *num=*(num+1);
    *(num+1)=tmp;
    return 0;
  }
  else {
    return 0;
  }
}
int BubbleSort(int *array, int num_element){
  if(num_element==1){
    return 0;
  }
  for (int i=0; i<num_element; i++){
    Swap(&array[i]);
  }
  BubbleSort(array,num_element-1);
  return 0;
}
