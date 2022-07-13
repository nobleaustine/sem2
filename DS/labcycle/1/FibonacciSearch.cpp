# include <iostream>
using namespace std;

int FIBONACCI_SEARCH(float *DATA,int N,float ITEM)
{
    int i,F2=0,F1=1,FB=1,OFFSET=-1;

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
            return i;
        }
    }

    if(FB==1 && DATA[OFFSET+1]==ITEM)
    {
        return OFFSET+1;
    }
    
    return -1;
    
}

int main()
{

    int option,loc,n,con,choice=0;
    float item;
    float *A;
    float B[12]={10,22,35,40,45,50,80,82,85,90,100,235};

    cout<<"   FIBONACCI SEARCH"<<endl;
    cout<<"   "<<endl;
    while(choice==0)
    {
        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : Enter a new array"<<endl;
        cout<<"      2 : Use a default array"<<endl;
        cout<<"   >>>";
        cin>>option;
        con=1;

        if(option==1)
        {
           cout<<"   Enter the number of elements in the array"<<endl;
           cout<<"   >>>";
           cin>>n; 

           A=new float[n];
           for(int i=0;i<n;i++)
           {
               cin>>A[i];
           }

            cout<<"   New array : "<<endl;
            for(int i=0;i<n-1;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[n-1]<<endl;
        }
        
        else if(option==2)
        {
            n=12;
            cout<<"   Default array : "<<endl;
            for(int i=0;i<n-1;i++)
            {
                cout<<B[i]<<", ";
            }
            cout<<B[n-1]<<endl;

        }

        while(con==1)
        {
            cout<<"   Enter the element to be searched "<<endl;
            cout<<"   >>>";
            cin>>item;

            if(option==1)
            {
                loc=FIBONACCI_SEARCH(A,n,item);
            }
            else if(option==2)
            {
                loc=FIBONACCI_SEARCH(B,n,item);
            }
            cout<<"   "<<item<<" is present at location "<<loc+1<<endl;
            
            cout<<"   Would you like to continue searching in this array "<<endl;
            cout<<"      1 : yes"<<endl;
            cout<<"      0 : no"<<endl;
            cout<<"   >>>";
            cin>>con;
        }

         cout<<"   Would you like to exit the program"<<endl;
            cout<<"      1 : yes"<<endl;
            cout<<"      0 : no"<<endl;
            cout<<"   >>>";
            cin>>choice;


    }
   
    return 0;
}



