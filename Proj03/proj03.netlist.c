
/******************************************************************************
  Project #3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal s, ResetA, ResetB, w, x, y, z, Present, a, b, c, d, e, f, g;
  
  Pulser((SD("2a"), "r -- Reset counter"), ResetA, 'r', 10000);
  Pulser((SD("3a"), "s -- Strobe counter"), s, 's', 10000);
  
  Not (SD("2b"), ResetA, ResetB);
  
  Counter((SD("2c-3c"), "4-bit counter"), (ResetB, s), (w,x,y,z));
  
  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);
 
  Probe((SD("1g"), "Present"), Present);
  Probe((SD("2g"), "a"), a);
  Probe((SD("3h"), "b"), b);
  Probe((SD("5h"), "c"), c);
  Probe((SD("6g"), "d"), d);
  Probe((SD("5f"), "e"), e);
  Probe((SD("3f"), "f"), f);
  Probe((SD("4g"), "g"), g);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7;
  
  //NOTE ON POSITIONING: Tried to spread out the gates as much as possible so it
  //is readable when you zoom into the circuit
  Not (SD(sd, "1f"), w, notw);
  Not (SD(sd, "3f"), x, notx);
  Not (SD(sd, "5f"), y, noty);
  Not (SD(sd, "7f"), z, (notz, e));
  
  And (SD(sd, "1n"), (notw, y), and1); //AND Gates
  And (SD(sd, "2n"), (notw, x, z), and2);
  And (SD(sd, "3n"), (notx, y, e), and3);
  And (SD(sd, "4n"), (y, z), and4);
  And (SD(sd, "5n"), (notw, notx), and5);
  And (SD(sd, "6n"), (notw, e), and6);
  And (SD(sd, "7n"), (x, e), and7);
  
  Or (SD(sd, "1y"), (and1, and2, and3), Present); //OR Gates
  Or (SD(sd, "2y"), (One, One), a);
  Or (SD(sd, "3y"), (notx, and4), b);
  Or (SD(sd, "4y"), (z,x,w), c);
  Or (SD(sd, "5y"), (noty, and5, and6), d);
  Or (SD(sd, "7y"), (noty, w, and7), f);
  Or (SD(sd, "8y"), (notx, noty, e), g);
}

