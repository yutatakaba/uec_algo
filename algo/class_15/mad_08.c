#	include <stdio.h>
#	include "clock.h"

#	define	N	2050
double	a[N][N];
double	b[N][N];
double	c[N][N];
int main(void){
  int	i,j,k;
  startClock();
  for (i=0;	i<N-2;	i++){
    for (k=0;	k<N-2;	k++){
      for (j=0;	j<N-2;	j++){
        c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  stopClock();
  printClock();
  return 0;
}
