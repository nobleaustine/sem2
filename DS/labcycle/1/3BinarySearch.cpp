# include <iostream>
using namespace std;

int BINARY_SEARCH(float DATA[],float ITEM,int N)
{
    int BEGIN=0;
    int END=N-1;
    int MID=(BEGIN+END)/2;
    int LOC=-1;
    
    while(DATA[MID]!=ITEM && BEGIN<=END)
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

int main()
{
    int option,n,loc,choice=1;
    float item;
    cout<<"   ------ BINARY SEARCH ------"<<endl;
    cout<<"   "<<endl;
    
    while(choice==1)
    {
        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : Enter a new array"<<endl;
        cout<<"      2 : Use a default array"<<endl;
        cout<<"   >>>";
        cin>>option;
        cout<<"   "<<endl;
        
        if(option==1)
        {
            cout<<"   Enter the size of the array"<<endl;
            cout<<"   >>>";
            cin>>n;
            float Data[n];
            cout<<"   "<<endl;
            
            cout<<"   Enter the elements of the array in ascending order"<<endl;
            cout<<"   >>>";
            for(int i=0;i<n;i++)
            {
                cin>>Data[i];
            }
            cout<<"   "<<endl;
            cout<<"   Enter the item to be searched"<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;
            
            loc=BINARY_SEARCH(Data,item,n);

        }

        else if(option==2)
        {
            float A[12]={11,22,30,33,40,44,55,60,66,77,88,99};

            cout<<"Default array :-"<<endl;
            for(int i=0;i<11;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[11]<<endl;

            cout<<"   Enter the item to be searched"<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;
            
            loc=BINARY_SEARCH(A,item,10);
        }

            if(loc!=-1)
            {
                cout<<"   "<<item<<" is located at position "<<loc+1<<endl;  
            }
            else
            {
                cout<<"   "<<item<<" is not present in the array"<<endl;
            }
            cout<<"   "<<endl;

        
        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"   >>>";
        cin>>choice;
        cout<<"   "<<endl;
    }

 return 0;}
