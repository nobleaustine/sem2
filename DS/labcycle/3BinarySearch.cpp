# include <iostream>
using namespace std;

int BINARY_SEARCH(float DATA[],int N,float ITEM)
{
    int BEGIN=0,END=N-1,LOC=-1;
    int MID=(BEGIN+END)/2;
    
    while(DATA[MID]!=ITEM && BEGIN<=END)
    {
        if(DATA[MID]<ITEM)
        {
            BEGIN=MID+1;
        }
        else if(DATA[MID]>ITEM)
        {
            END=MID-1;
        }

        MID=(BEGIN+END)/2;
    }
    
    if(DATA[MID]==ITEM)
        {
          LOC=MID;
        }
    
    return LOC;
}

int main()
{
    int n,loc,choice=1;
    float item;
    cout<<"   "<<endl;
    cout<<"      ------ BINARY SEARCH ------"<<endl;
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
        
        loc=BINARY_SEARCH(data,n,item);

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
