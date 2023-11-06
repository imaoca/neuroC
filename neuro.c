#include <stdio.h>
int links[25*25];
int D[25]={
                 1, 1, 1, 1,-1,
                -1, 1,-1,-1, 1,
                -1, 1,-1,-1, 1,
                -1, 1,-1,-1, 1,
                -1, 1, 1, 1,-1
        };
int J[25]={
                 1, 1, 1, 1, 1,
                -1,-1,-1, 1,-1,
                -1,-1,-1, 1,-1,
                 1,-1,-1, 1,-1,
                 1, 1, 1,-1,-1
        };
int C[25]={
                -1, 1, 1, 1, 1,
                 1,-1,-1,-1,-1,
                 1,-1,-1,-1,-1,
                 1,-1,-1,-1,-1,
                -1, 1, 1, 1, 1
        };
int M[25]={	 1,-1,-1,-1, 1,
                 1, 1,-1, 1, 1,
                 1,-1, 1,-1, 1,
                 1,-1,-1,-1, 1,
                 1,-1,-1,-1, 1};

void show(int p[]){
        int i,j;
        for (i=0;i<5;i++){
         for(j=0;j<5;j++)
                if (p[i*5+j]>0) putchar('#');
                else
                        putchar(' ');
        putchar('\n');
        }
   putchar('\n');
}

void learn2(void){
  int i,j;
  for (i=0;i<25;i++)
     for(j=0;j<25;j++)
        links[i*25+j]=
	((D[i]==D[j])?1:-1)+
	((J[i]==J[j])?1:-1)+
	((C[i]==C[j])?1:-1)+
	((M[i]==M[j])?1:-1);
}

void hopfield(int inp[], int lin[]){
        int sum,i,j;
        for (i=0;i<25;i++){
                sum = 0;
                for(j=0;j<25;j++)sum=sum+(inp[j])*(lin[i*25+j]);
                inp[i]=(sum>=0)?1:-1;
        }
}



void main(void){
        int input[25]={
           -1, 1,-1, 1, 1,
           -1,-1,-1, 1,-1,
           -1,-1,-1, 1,-1,
           -1,-1,-1, 1,-1,
           -1, 1, 1,-1,-1
        };
	learn2();
        printf("example\n");
        show(input);
        printf("recognition\n");
        hopfield(input,links);
        show(input);
}
