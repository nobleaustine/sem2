# include <iostream>
using namespace std;

void INSERTION_SORT(float* DATA,int N)
{
    DATA[0]=-999;
    float TEMP;
    int PTR;

   for(int i=2;i<N;i++)
    {
        TEMP=DATA[i];
        PTR=i-1;
        while(TEMP<DATA[PTR])
        {
            DATA[PTR+1]=DATA[PTR];
            PTR=PTR-1;
        }
        DATA[PTR+1]=TEMP;
    }
}


int main()
{
    int option,n,choice=1;
    float A[15]={-999,66,33,40,22,55,88,60,11,80,20,50,44,77,30};
    float *C;

    cout<<"   ------ SELECTION SORT ------"<<endl;
    cout<<"   "<<endl;
    while(choice==1)
    {
        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : Enter a new array"<<endl;
        cout<<"      2 : Use a default array"<<endl;
        cout<<"   >>>";
        cin>>option;
        

        if(option==1)
        {
           cout<<"   Enter the number of elements in the array"<<endl;
           cout<<"   >>>";
           cin>>n; 

          C=new float[n+1];
          cout<<"   >>>";
          for(int i=1;i<n+1;i++)
           {
               cin>>C[i];
           }

            cout<<"   Array after sorting : "<<endl;
            cout<<"   >>>";
            
            INSERTION_SORT(C,n);
        
                for(int i=1;i<n-1;i++)
                {
                    cout<<C[i]<<", ";
                }
                cout<<C[n-1]<<endl;
        }
        
        else if(option==2)
        {
            n=14;
            cout<<"   Default array : "<<endl;
            cout<<"   >>>";
            for(int i=1;i<n-1;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[n-1]<<endl;

            cout<<"   Array after sorting : "<<endl;
            cout<<"   >>>";
            INSERTION_SORT(A,n);
          
                for(int i=1;i<n-1;i++)
                {
                    cout<<A[i]<<", ";
                }
                cout<<A[n-1]<<endl;
        }
        
        
        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"   >>>";
        cin>>choice;
        cout<<"   "<<endl;


    }

    return 0;
}