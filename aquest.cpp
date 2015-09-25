#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <SpiceUsr.h>

////////////////////////////////////////////////////////////
//MACROS
////////////////////////////////////////////////////////////
#define DEG (x*M_PI/180)
#define RAD (x*180/M_PI)
#define POWI(x,n) gsl_pow_int(x,n)
#define SGN(x) (x<0?-1:+1)

int aQuest(void)
{
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //LOAD KERNELS
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  furnsh_c("kernels");
  return 0;
}

int whatTimeIsIt(SpiceChar* date,SpiceChar* outsys,double *t)
{
  
}
