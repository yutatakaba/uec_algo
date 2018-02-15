#	include <stdio.h>
#	include "clock.h"
#	define	N	4096
#	define	M	4100
#	define	BLOCK	256
double	a[M][M];
double	b[M][M];
double	c[M][M];
int main(void){
  int	i,j,k,ii,jj,kk;
  startClock();
  for (i	= 0;	i	<N;	i+=BLOCK){
    for(j	= 0;	j	<	N;	j+=BLOCK){
      for(k	= 0;	k	<	N;	k+=BLOCK){
        for(ii	=	i;	ii	< (i	+	BLOCK);	ii++){
          for (kk	=	k;	kk	< (k	+	BLOCK);	kk++){
            for (jj	=	j;	jj	< (j	+	BLOCK);	jj++){
              c[ii][jj]+=a[ii][kk]*b[kk][jj];
            }
          }
        }
      }
    }
  }
  stopClock();
  printClock();
  return 0;
}
