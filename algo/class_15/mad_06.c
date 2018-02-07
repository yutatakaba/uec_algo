#	include <stdio.h>
#	include "clock.h"

#	define	N	512
#	define	itr	50
int main(void){
  double	a[N][N];
  double	b[N][N];
  double	c[N][N];
  int	i,j,k,l;
  startClock();
  for(l=0 ;	l	<	itr	;	l++){
    for (j=0;	j<N;	j++){
      for (i=0;	i<N;	i++){
        for (k=0;	k<N;	k++){
          c[i][j] +=	a[i][k] *b[k][j];
        }
      }
    }
  }
  stopClock();
  printClock();
  return 0;
}
