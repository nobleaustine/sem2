#include <iostream>
using namespace std;

class SEARCH // class with different types of searchs as functions
{
    public:
    int LINEAR_SEARCH(float DATA[],float ITEM,int UB,int LB=1);
    int BINARY_SEARCH(float DATA[],float ITEM,int UB,int LB=1);
    int TERNARY_SEARCH(float DATA[],float ITEM,int UB,int LB=1);
    int FIBONACCI_SEARCH(float DATA[],float ITEM,int UB,int LB=1);
    int INTERPOLATION_SEARCH(float DATA[],float ITEM,int UB,int LB=1);

}

int SEARCH:: LINEAR_SEARCH(float DATA[],float ITEM,int UB,int LB=1) // algorithm of linear search
{
    int LOC=-1; // LOC :- location variable, to return the position of item. -1 value to indicate failed search
    int j=LB-1; // variable to iterate through the array

    while(j<UB)
    {
        if(DATA[j]==ITEM)
        {
            LOC=j;
            return LOC; // search successful
        }
        j=j+1;
    }
    return LOC; // search failed
}

int SEARCH:: BINARY_SEARCH(float DATA[],float ITEM,int UB,int LB=1) // algorithm of binary search
{
    int BEGIN=LB-1;
    int END=UB-1;
    int MID=(BEGIN+END)/2; // variable to find the position to search
    int LOC=-1; // LOC :- location variable, to return the position of item, -1 value to indicate failed search
    
    while(DATA[MID]!=ITEM && BEGIN<=END) // reducing the area of search in the absence of ITEM
    {
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
    
     if(DATA[MID]==ITEM) // search successful
        {
          LOC=MID;
          return LOC;
        }
        else // search failed
        {
           return LOC;
        }
}

int SEARCH:: TERNARY_SEARCH(float DATA[],float ITEM,int UB,int LB=1) // algorithm of binary search
{
    int BEGIN=LB-1;
    int END=UB-1;
    int MID1=(BEGIN+(END-BEGIN)/3); // variable to find the position to search
    int MID2=(BEGIN+2(END-BEGIN)/3); // variable to find the position to search
    int LOC=-1; // LOC :- location variable, to return the position of item, -1 value to indicate failed search
    
    while(DATA[MID1]!=ITEM && DATA[MID2]!=ITEM && BEGIN<=MID1 && MID1<=MID2 && MID2<=END) // reducing the area of search in the absence of ITEM
    {
        if(DATA[MID1]<ITEM<DATA[MID2])
        {
            END=MID-1;
        }
        else if(ITEM>DATA[MID])
        {
            BEGIN=MID+1;
        }
        MID=(BEGIN+END)/2;
    }
    
     if(DATA[MID]==ITEM) // search successful
        {
          LOC=MID;
          return LOC;
        }
        else // search failed
        {
           return LOC;
        }
}
