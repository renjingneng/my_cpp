//reference：https://zhuanlan.zhihu.com/p/366372612
#include <stdio.h>
#include <stdlib.h>
#define STR1 "AGGTAB"
#define STR2 "XGWTABL"
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
    int res = 0;
    int res_x = 0;
    
    
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0){
                L[i][j] = 0;
            }else if (S1[i - 1] == S2[j - 1]){
				L[i][j] = L[i - 1][j - 1] + 1;
                if(L[i][j]>res){
                    res=L[i][j];
                    res_x = i;
                }
            }else{
                L[i][j] = 0;
            }				
		}
	}

	printf("Length of LCS is %d \n",res);

    printf("Content of LCS is ");
    for (size_t i = 0; i < res; i++)
    {
        printf("%c",S1[res_x-res+i]);
    }
	return 0;
}
