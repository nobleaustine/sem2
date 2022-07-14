# include <iostream>
using namespace std;

int LINEAR_SEARCH(float *DATA,int N,float ITEM)
{
    int LOC=-1;
    for(int i=0;i<N;i++)
    {
        if(DATA[i]==ITEM)
        {
            LOC=i;
            return LOC;
        }
    }

    return LOC;
}

int main()
{
    int option,n,loc,choice=1;
    float item;
    cout<<"   ------ LINEAR SEARCH ------"<<endl;
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
            float data[n];
            cout<<"   "<<endl;
            
            cout<<"   Enter the elements of the array in ascending order"<<endl;
            cout<<"   >>>";
            for(int i=0;i<n;i++)
            {
                cin>>data[i];
            }
            cout<<"   "<<endl;
            cout<<"   Enter the item to be searched"<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;
            
            loc=LINEAR_SEARCH(data,n,item);

        }

        else if(option==2)
        {
            float A[10]={2,4,6,8,10,12,14,16,18,20};

            cout<<"Default array :-"<<endl;
            for(int i=0;i<9;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[9]<<endl;

            cout<<"   Enter the item to be searched"<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;
            
            loc=LINEAR_SEARCH(A,10,item);
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
    }

 return 0;}