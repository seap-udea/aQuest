#include <aquest.cpp>
using namespace std;

#define NUMARGS 2

int main(int argc,char* argv[])
{
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //INITIALIZE
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  aQuest();

  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //GET COMMAND LINE OPTIONS
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  int qverbose=0;
  int iarg=1;
  const char* usage=""
    "./whatTimeIsIt <date> <outsys>\n"
    "\t<date>: MM/DD/CCYY HH:MM:SS.DCM [UTC[-N]]\n"
    "\t<outsys>: ET (Ephemeris time, default), JED (Julian epehemeris time), TAI, TDT, TDB\n"
    "";
  if(argc<NUMARGS){fprintf(stderr,"%s",usage);exit(1);}
  if(strstr("-v",argv[iarg])){qverbose=1;iarg=2;}
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //CONFIGURE INTERFACE
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  SpiceChar date[100],outsys[10];
  strcpy(date,argv[iarg++]);
  if(argc<=NUMARGS) strcpy(outsys,"ET");
  else strcpy(outsys,argv[iarg++]);

  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //COMPUTE
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  SpiceDouble t;
  whatTimeIsIt(date,&t,outsys);
  fprintf(stderr,"Date '%s' in '%s' is : %.17le\n",date,outsys,t);

  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //OUTPUT
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  fprintf(stdout,"%.17le\n",t);
}
