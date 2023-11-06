#include <stdio.h>

// int links[25][25];
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

void listlinks(void){
        for (int i=0;i<25;i++)
                for(int j=0;j<25;j++)
			printf("links[%d]=%d;\n",i*25+j,links[i*25+j]);
}


void learn(int p[]){
        int i,j;
        for (i=0;i<25;i++)
                for(j=0;j<25;j++)
                        if (i!=j)
                                if (p[i]==p[j]) links[i*25+j]+=1;
                                else links[i*25+j]-=1;
}

void learn2(void){
  int i,j;
  for (i=0;i<25;i++)
     for(j=0;j<25;j++)
        links[i*25+j]=links[i*25+j]+((D[i]==D[j])?1:-1)+((J[i]==J[j])?1:-1)+((C[i]==C[j])?1:-1)+((M[i]==M[j])?1:-1);
}


/* 
      for (k=0;k<25;k=k+1)
          for(m=0;m<25;m=m+1)
               links[k*25+m]=((learn[0][k]==learn[0][m])?1:-1)+((learn[1][k]==learn[1][m])?1:-1)+((learn[2][k]==learn[2][m])?1:-1)+((learn[3][k]==learn[3][m])?1:-1);
*/

void calclinks(void){
  int k,m;
  for (k=0;k<25;k++)
     for(m=0;m<25;m++)
	printf("links[%d]=((learn[0][%d]==learn[0][%d])?1:-1)+((learn[1][%d]==learn[1][%d])?1:-1)+((learn[2][%d]==learn[2][%d])?1:-1)+((learn[3][%d]==learn[3][%d])?1:-1);\n",k*25+m,k,m,k,m,k,m,k,m);
}

void hopfield(int inp[], int lin[]){
        int sum,i,j;
        for (i=0;i<25;i++){
                sum = 0;
                for(j=0;j<25;j++){
                        sum=sum+(inp[j]) * (lin[i*25+j]);
                }
                if (sum>=0) inp[i]=1;
                else inp[i]=-1;
//                printf("%d %d\n",i,sum);
        }
}




void main(void){
        int i,j,sum;
        int input[25]={
                -1, 1,-1, 1, 1,
                -1,-1,-1, 1,-1,
                -1,-1,-1, 1,-1,
                -1,-1,-1, 1,-1,
                -1, 1, 1,-1,-1
        };

/*
        int input[25]={
                -1, 1, 1, 1,-1,
                -1, 1,-1,-1,-1,
                -1, 1,-1,-1, 1,
                 1, 1,-1,-1, 1,
                -1, 1, 1, 1,-1
        };
*/

        for (i=0;i<25;i++)
                for(j=0;j<25;j++) links[i*25+j]=0;

        printf("learing\n");


        show(D);
        show(J);
        show(C);
        show(M);

        printf("example\n");
        show(input);

        // set all zero
        for (i=0;i<25;i++)
                for(j=0;j<25;j++) links[i*25+j]=0;

        // learn 'D'
/*
        learn(D);
        learn(J);
        learn(C);
        learn(M);
*/

	learn2();


//	listlinks();


        printf("recognition\n");
        //hopfield
        hopfield(input,links);
        show(input);

	calclinks();

}
