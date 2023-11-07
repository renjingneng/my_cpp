//reference：https://zhuanlan.zhihu.com/p/366372612
#include <stdio.h>
#include <stdlib.h>
#define STR1 "AGGTAB"
#define STR2 "GXTXAYB"
#define M 6
#define N 7

void LCS_print(int b[M][N],char * s1,char *s2 ,int i, int j)
{
	if (i < 0 || j < 0) return;
	if (b[i][j] == 1)
	{
		LCS_print(b,s1,s2,i - 1, j - 1);
		printf("%c",s1[i]);
	}
	else if (b[i][j] == 2)
	{
		LCS_print(b,s1,s2,i - 1, j );
	}
	else{
        LCS_print(b,s1,s2,i, j-1 );
    }	
}

int main()
{
	char* S1 = STR1;
	char* S2 = STR2;
    int L[M+1 ][N+1 ];
    int B[M][N];
    
    
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0){
                L[i][j] = 0;
            }else if (S1[i - 1] == S2[j - 1]){
				L[i][j] = L[i - 1][j - 1] + 1;
                B[i-1][j-1] = 1;//diagonal
            }else if(L[i - 1][j]>L[i][j - 1]){
                L[i][j] = L[i - 1][j];
                B[i-1][j-1] = 2;// vertical
            }else{
                L[i][j] = L[i][j - 1];
                B[i-1][j-1] = 3;//horizontal
            }				
		}
	}

	printf("Length of LCS is %d \n",L[M][N]);

    printf("Content of LCS is ");
    LCS_print(B,S1,S2,M-1,N-1);
	return 0;
}
