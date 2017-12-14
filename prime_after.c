#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int i,j,k;
int N = 7777;
int OK;
int base_number;
int card[55];
int card_count;
int check_start;
int check_end;
int cpr,cpn;
int dou;
int ideal_sum;
int ideal_mul;
int judge_number;
int limit_number;
int loop;
int num;
int number;
int number_flag[11];
int overflow;
int store;
int prime[22][7777];
int prime_check;
int prime_loop;
int prime_max;
int real_sum;
int real_mul;
int stock[11];
int tem_i, tem_j;
int tem_loop;
int tem_val_1, tem_val_2;

int PF(int x,int y);

int main(){
  printf("\n limit number : ");
  scanf("%d",&limit_number);
  base_number = 1 ;
  for(i=1;i<=limit_number;i++){
    base_number = base_number * 10 ;
  }
  check_start = base_number / 10 ;
  check_end = base_number - 1 ;
  prime_loop = 4 ;
  for(i=1;i<=9;i++){
    printf("%d number : ",i);
    scanf("%d",&number);
    card[i] = number ;
  }
  prime_max = 0 ;
  for(i=check_start;i<=check_end;i++){
    tem_i = i ;
    OK = 0 ;
    for(j=1;j<=9;j++){
      number_flag[j] = 0 ;
    }
    for(j=1;j<=limit_number;j++){
      stock[j] = tem_i % 10 ;
      tem_i = tem_i / 10 ;
      if(number_flag[stock[j]]==0 && card[stock[j]]!=0){
        number_flag[stock[j]] = 1 ;
      }else{
        OK = 1 ;
      }
    }
    if(OK == 0){
      judge_number = 0 ;
      overflow = 0 ;
      for(j=1;j<=limit_number;j++){
        tem_val_1 = judge_number ;
        if(judge_number==0){
          judge_number = card[stock[j]] ;
        }else if(card[stock[j]]>9){
          judge_number = judge_number * 100 + card[stock[j]] ;
        }else{
          judge_number = judge_number * 10 + card[stock[j]] ;
        }
        tem_val_2 = judge_number ;
        if(tem_val_1 > tem_val_2){
          overflow = 1 ;
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
      if(prime_check==1 && overflow==0){
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
