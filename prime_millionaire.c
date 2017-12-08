#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//一般的な大富豪ではなく「素数大富豪」です←

//10,J,Q,K→最優先で消化すべし
//その他→使えるタイミングで使用
//1,3,7,9→残しても全然OK

int i,j;
int cn;
int cnm[22];//CardNumberManagement
int scn = 9;//StartCardNumber
int pn = 6;//PlayerNumber
int car[11][55];//Player/CardNumber
int cas[55];
int myOK[11];
int number;
int OK=0;
int step=0;

int PF1(int x,int y){
  if(x%y==0){
    return 0;
  }else{
    return 1;
  }
}

int PF2(int x){
  int OK2 = 1;
  int hx = int(sqrt(double(x))) + 1;
  for(int i=2;i<=hx;i++){
    if(PF1(x,i)==0){
      return 0;
    }
  }
  return 1;
}

void swap(int a[],int i,int j){
  int k;
  k    = a[i];
  a[i] = a[j];
  a[j] = k   ;
}

void func1(int a[],int i,int j){
  int k;
  while((k=2*i+1) <= j){
    if(k<j && a[k]<a[k+1]){
      k++;
    }
    if(a[i]>=a[k]){
      break;
    }
    swap(a,i,k);
    i = k;
  }
}

void func2(int a[],int m){
  int i;
  for(i=m/2;i>-1;i--){
    func1(a,i,m-1);
  }
}

void func3(int a[],int m){
  int i ;
  func2(a,m);
  while(m>1){
    swap(a,0,m-1);
    func1(a,0,m-2);
    m--;
  }
}

int main(){
  srand((unsigned)time(NULL));
  for(i=1;i<15;i++){
    cnm[i] = 0;
  }
  for(i=0;i<pn;i++){
    for(j=0;j<54;j++){
    car[i][j] = 0;
    }
  }
  for(i=0;i<54;i++){
    cas[i] = 0;
  }
  for(i=0;i<pn;i++){
    for(j=0;j<scn;j++){
      cn = rand()%54 + 1;//1<=cn<=54
      if((cn==53 || cn==54) && cnm[14]<2){
	car[i][j] = 14;
	cnm[14]++;
      }else if(cn%13==1 && cnm[1]<4){
	car[i][j] = 1;
	cnm[1]++;
      }else if(cn%13==2 && cnm[2]<4){
	car[i][j] = 2;
	cnm[2]++;
      }else if(cn%13==3 && cnm[3]<4){
	car[i][j] = 3;
	cnm[3]++;
      }else if(cn%13==4 && cnm[4]<4){
	car[i][j] = 4;
	cnm[4]++;
      }else if(cn%13==5 && cnm[5]<4){
	car[i][j] = 5;
	cnm[5]++;
      }else if(cn%13==6 && cnm[6]<4){
	car[i][j] = 6;
	cnm[6]++;
      }else if(cn%13==7 && cnm[7]<4){
	car[i][j] = 7;
	cnm[7]++;
      }else if(cn%13==8 && cnm[8]<4){
	car[i][j] = 8;
	cnm[8]++;
      }else if(cn%13==9 && cnm[9]<4){
	car[i][j] = 9;
	cnm[9]++;
      }else if(cn%13==10 && cnm[10]<4){
	car[i][j] = 10;
	cnm[10]++;
      }else if(cn%13==11 && cnm[11]<4){
	car[i][j] = 11;
	cnm[11]++;
      }else if(cn%13==12 && cnm[12]<4){
	car[i][j] = 12;
	cnm[12]++;
      }else if(cn%13==0 && cnm[13]<4){
	car[i][j] = 13;
	cnm[13]++;
      }else{
	j--;
      }
    }
  }
  for(i=0;i<pn;i++){
    for(j=0;j<scn;j++){
      cas[j] = car[i][j];
    }
    func3(cas,scn);
    for(j=0;j<scn;j++){
      car[i][j] = cas[j];
    }
    if(i==0){
      printf("\nYOU :");
    }else{
      printf("\nCP%d :",i);
    }
    for(j=0;car[i][j]!=0;j++){
      if(car[i][j]<10){
	printf("  %d",car[i][j]);
      }
      if(car[i][j]==10){
	printf(" 10");
      }
      if(car[i][j]==11){
	printf("  J");
      }
      if(car[i][j]==12){
	printf("  Q");
      }
      if(car[i][j]==13){
	printf("  K");
      }
      if(car[i][j]==14){
	printf(" BB");
      }
    }
  }
  printf("\n\n");
  while(OK==0){
    step++;
    printf("%03d CARD : ",step);
    scanf("%d",&number);
    
  return 0;
}
