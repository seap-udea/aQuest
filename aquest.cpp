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
     outsys: Time system where it should be returned.

  Returns:

     t: Time in output system.
 */
int whatTimeIsIt(SpiceChar* date,double *t,SpiceChar* outsys="ET")
{
  SpiceDouble et;
  str2et_c(date,&et);
  *t=unitim_c(et,"ET",outsys);
  return 0;
}

/*
  Function: Calculate the state vector of an object.

  Parameters:

     object: ID of the target.
     t: ephemeris time.
     origin: object in the origin.
     frame: frame of reference.

  Returns:
  
     state: State vector (x,y,z,vx,vy,vz)
 */
int whereIsIt(SpiceChar* object,SpiceDouble t,SpiceChar* origin,SpiceChar* frame,SpiceDouble state[])
{
  SpiceDouble state[6],lt
  spkezr_c(object,t,frame,"NONE",origin,state,&lt);
  return 0;
}
