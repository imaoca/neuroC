#include <stdio.h>

// int links[25][25];
int links[25*25];

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

void hopfield(int inp[], int lin[]){
        int sum,i,j;
        for (i=0;i<25;i++){
                sum = 0;
                for(j=0;j<25;j++){
                        sum=sum+(inp[j]) * (lin[i*25+j]);
                }
		  inp[i]=(sum>0)?1:-1;	
//                if (sum>=0) inp[i]=1;else inp[i]=-1;
//                printf("%d %d\n",i,sum);
        }
}


// ((neuros[5'd0]==1'b1)?links[{5'd0,5'd0}]:(-links[{5'd0,5'd0}]))+
// ((neuros[j]==1)?links[{i*5+j]:(-links[i*5+j]))+
void makeExec(){
	int i,j,k;
	char c;
	for (i=0;i<25;i++){
		printf("sum=");
		for (j=0;j<25;j++){
			k = i*25 + j;
			c=(j==24?';':'+');
			printf("((neuros[%d]==1)?links[%d]:(-links[%d]))%c",j,k,k,c);
		}
		printf("\nneuros[%d]=~sum[9];\n",i);	

	}
}

void main(void){
        int i,j,sum;
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
        int M[25]={
                 1,-1,-1,-1, 1,
                 1, 1,-1, 1, 1,
                 1,-1, 1,-1, 1,
                 1,-1,-1,-1, 1,
                 1,-1,-1,-1, 1
        };

        int input[25]={
                -1, 1, 1, 1,-1,
                -1, 1,-1,-1,-1,
                -1, 1,-1,-1, 1,
                 1, 1,-1,-1, 1,
                -1, 1, 1, 1,-1
        };


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
        learn(D);
        learn(J);
        learn(C);
        learn(M);

//	listlinks();

	makeExec();
        
	printf("recognition\n");
        //hopfield
        hopfield(input,links);
        show(input);

}
