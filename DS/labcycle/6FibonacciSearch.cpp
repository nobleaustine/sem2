# include <iostream>
using namespace std;

int FIBONACCI_SEARCH(float *DATA,int N,float ITEM)
{
    int i,F2=0,F1=1,FB=1,OFFSET=-1,LOC=-1;

    while(FB<N)
    {
        F2=F1;
        F1=FB;
        FB=F2+F1;
        
    }

    while(FB>1)
    {
        i=OFFSET+F2;
        if(DATA[i]<ITEM)
        {
            FB=F1;
            F1=F2;
            F2=FB-F1;
            OFFSET=i;
        }
        else if(DATA[i]>ITEM)
        {
            FB=F2;
            F1=F1-F2;
            F2=FB-F1;
        }
        else
        {
            LOC=i;
            return LOC;
        }
    }

    if(FB==1 && DATA[OFFSET+1]==ITEM)
    {
        LOC=OFFSET+1;
        return LOC;
    }
    
    return LOC;
    
}

int main()
{
    int n,loc,choice=1;
    float item;
    cout<<"   "<<endl;
    cout<<"      ------ FIBONACCI SEARCH ------"<<endl;
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
        
        loc=FIBONACCI_SEARCH(data,n,item);

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


