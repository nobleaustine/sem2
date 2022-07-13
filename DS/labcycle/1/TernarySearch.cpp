# include <iostream>
using namespace std;

int TERNARY_SEARCH(float DATA[],float ITEM,int N)
{
    int BEGIN=0;
    int END=N-1;
    int MID1,MID2,LOC=-1;
    
    while(BEGIN<=END && LOC==-1)
    {
        MID1=BEGIN + END-
        if(ITEM<DATA[MID])
        {
            END=MID-1;
        }
        else if(ITEM>DATA[MID])
        {
            BEGIN=MID+1;
        }
        MID=(BEGIN+END)/2;
    }
    
     if(DATA[MID]==ITEM)
        {
          LOC=MID;
          return LOC;
        }
        else
        {
           return LOC;
        }

}
