#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int i,j,k;
int N = 7777;
int OK;
int card[55];
int card_count;
int cpr,cpn;
int dou;
int judge_number;
int limit_number;
int loop;
int num;
int number;
int store;
int prime[22][7777];
int prime_check;
int prime_loop;
int prime_max;
int tem_j;
int tem_loop;

int PF(int x,int y);

int main(){
  num = 0 ;
  number = 1 ;
  while(number!=0){
    printf("%d number : ",num+1);
    scanf("%d",&number);
    if(number!=0){
      card[num] = number ;
      num++;
    }
  }
  printf("\n limit number : ");
  scanf("%d",&limit_number);
  printf(" L42 ");
  prime_max = 0 ;
  for(i=1;i<=num;i++){
    printf(" L45 ");
    loop = 1 ;
    for(j=1;j<=num;j++){
      printf(" L48 ");
      loop = loop * 2 ;
    }
    for(j=1;j<loop;j++){
      card_count = 0 ;
      judge_number = 0 ;
      tem_j = j ;
      for(k=num-1;k>=0;k--){
        if( tem_j >= (int)pow(2.0,(double)k) ){
          if(judge_number==0){
            judge_number = card[k] ;
          }else if(card[k]>9){
            judge_number = judge_number * 100 + card[k] ;
          }else{
            judge_number = judge_number * 10 + card[k] ;
          }
          card_count++;
          if(limit_number==card_count){
            break;
          }
          tem_j = tem_j - (int)pow(2.0,(double)k);
        }
      }
      prime_check = 1 ;
      prime_loop = (int)sqrt((double)judge_number) ;
      for(k=2;k<=prime_loop;k++){
        if(PF(judge_number,k)==1){
          prime_check = 0 ;
          break;
        }
      }
      if(prime_check==1){
        if(judge_number > prime_max){
          prime_max = judge_number ;
        }
      }
    }
    card[num] = card[0] ;
    for(j=0;j<num;j++){
      card[j] = card[j+1] ;
    }
  }
  printf("\n\n max prime number is %d\n\n",prime_max);
  return 0 ;
}



int PF(int x,int y){
  if(x % y == 0){
    return 1 ;
  }else{
    return 0 ;
  }
}
