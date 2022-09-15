# include <iostream>
using namespace std;

int TERNARY_SEARCH(float DATA[],int N,float ITEM)
{
    int MID1,MID2,BEGIN=0,END=N-1,LOC=-1;
    
    while(BEGIN<=END && LOC==-1)
    {
        MID1=BEGIN + ((END-BEGIN)/3);
        MID2=BEGIN + 2*((END-BEGIN)/3);

        if(DATA[MID1]==ITEM)
        {
            LOC=MID1;
        }
        else if(DATA[MID2]==ITEM)
        {
            LOC=MID2;
        }
       else if(DATA[MID1]>ITEM)
       {
           END=MID1-1;
       }
       else if(DATA[MID2]<ITEM)
       {
            BEGIN=MID2+1;
       }
       else
       {
           BEGIN=MID1+1;
           END=MID2-1;
       }
    }
    return LOC;
}

int main()
{
    int n,loc,choice=1;
    float item;
    cout<<"   "<<endl;
    cout<<"      ------ TERNARY SEARCH ------"<<endl;
    cout<<"   "<<endl;
    
    cout<<"   Enter the size of the array : ";
    cin>>n;
    cout<<"   "<<endl;
    
    float data[n];

    cout<<"   Enter the elements in the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    
    while(choice==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the item to be searched : ";
        cin>>item;
        cout<<"   "<<endl;
        
        loc=TERNARY_SEARCH(data,n,item);

        if(loc!=-1)
        {
            cout<<"   "<<"'"<<item<<"'"<<" is located at position "<<loc+1<<endl;  
        }
        else
        {
            cout<<"   "<<"'"<<item<<"'"<<" is not present in the array"<<endl;
        }
        cout<<"   "<<endl;

        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"        : ";
        cin>>choice;
    }
    cout<<"   "<<endl;
    
    return 0;
}
