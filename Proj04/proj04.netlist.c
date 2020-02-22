
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  Pulser((SD("2a"), "i - Init"), Init, 'i', 1000);
  Pulser ((SD("3a"), "c - Clock"), Clock, 'c',  1000);
  
  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  Probe ((SD("1d"), "w"), w);
  Probe ((SD("2d"), "x"), x);
  Probe ((SD("3d"), "y"), y);
  Probe ((SD("4d"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );
  Signal notw, notx, noty, notz, andxyz, andnxnz, W, X, Y, Z;
  
  Dff ((SD(sd,"1a"), "Dff3"), (Init, W, Clock, Zero), w);
  Dff ((SD(sd,"2a"), "Dff2"), (Zero, X, Clock, Init), x);
  Dff ((SD(sd,"3a"), "Dff1"), (Init, Y, Clock, Zero), y);
  Dff ((SD(sd,"4a"), "Dff0"), (Zero, Z, Clock, Init), z);
  
  Not (SD(sd, "1f"), w, notw);
  Not (SD(sd, "2f"), x, notx);
  Not (SD(sd, "3f"), y, noty);
  Not (SD(sd, "4f"), z, notz);
  
  And (SD(sd, "1n"), (x, y, z), andxyz);
  And (SD(sd, "3n"), (notx, notz), andnxnz);
  
  Or (SD(sd, "1y"), (andxyz, andxyz), W);
  Or (SD(sd, "2y"), (notx, notx), X);
  Or (SD(sd, "3y"), (notw, notw), Y);
  Or (SD(sd, "4y"), (noty, andnxnz), Z);
}

