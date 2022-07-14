# include <iostream>
using namespace std;

int INTERPOLATION_SEARCH(float DATA[],float ITEM,int N)
{
    int POS,BEGIN=0,END=N-1,LOC=-1;
    
    while(BEGIN<=END && ITEM>=DATA[BEGIN] && ITEM<=DATA[END])
    {
        POS=BEGIN + (((ITEM-DATA[BEGIN])/(DATA[END]-DATA[BEGIN]))*(END-BEGIN));

        if(DATA[POS]==ITEM)
        {
            LOC=POS;
            return LOC;
        }
        else if(ITEM>DATA[POS])
        {
            BEGIN=POS+1;
        }
        else
        {
            END=POS-1;
        }
    }
    return LOC;
}

int main()
{
    int option,n,loc,choice=1;
    float item;
    cout<<"   ------ INTERPOLATION SEARCH ------"<<endl;
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
            
            loc=INTERPOLATION_SEARCH(Data,item,n);

        }

        else if(option==2)
        {
            float A[20]={10,13,15,26,28,50,56,88,94,127,159,356,480,567,689,699,780,850,956,995};

            cout<<"Default array :-"<<endl;
            for(int i=0;i<19;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[19]<<endl;
            cout<<"   "<<endl;

            cout<<"   Enter the item to be searched"<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;
            
            loc=INTERPOLATION_SEARCH(A,item,20);
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
