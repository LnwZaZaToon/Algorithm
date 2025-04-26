#include<stdio.h>

int M[100][100];

int max(int x, int y)
{  return x > y? x:y;
}

int knapsack(int Wt, int w[], int v[], int n) {
    if (n == 0 || Wt == 0)
        return 0;

    if (M[n][Wt] != -1)
        return M[n][Wt];

    if (w[n - 1] > Wt)
        return M[n][Wt] = knapsack(Wt, w, v, n - 1);

    return M[n][Wt] = max(v[n-1] + knapsack(Wt-w[n-1], w, v, n-1),
                          knapsack(Wt, w, v, n-1));
}

int main()
{ int val[] = {1000, 1500, 2000};
  int w[] = {2,2,2};
  int Wt = 4;
  int N = 3;

  for(int i=0;i<=N;i++)
    for(int j=0; j<=Wt; j++)
      {  if(j == 0 || i == 0)
             M[i][j] = 0;
         else
             M[i][j] = -1;
      }

  printf("%d\n", knapsack (Wt, w, val, N));
  for(int i = 0 ; i <= N ; i++ ){
  	for(int j = 0 ; j <= Wt ; j++){
  		printf("%d ",M[i][j]);
	  }
	  printf("\n");
  }

}
