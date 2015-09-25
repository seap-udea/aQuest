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

/*
  Function: Calculate the time at a given date.

  Parameters:

     date: Date for conversion
     outsys: Time system where it should be returned
 */
int whatTimeIsIt(SpiceChar* date,double *t,SpiceChar* outsys="ET")
{
  SpiceDouble et;
  str2et_c(date,&et);
  *t=unitim_c(et,"ET",outsys);
  return 0;
}
