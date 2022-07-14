# include <iostream>
using namespace std;

void BUBBLE_SORT(float *DATA,int N)
{
    float TEMP;

    while(N>0)
    {
        for(int i=0;i<N-1;i++)
        {
            if(DATA[i]>DATA[i+1])
            {
                TEMP=DATA[i+1];
                DATA[i+1]=DATA[i];
                DATA[i]=TEMP;
            }

        }
        N=N-1;
    }
}

int main()
{
    int option,n,choice=1;
    float A[14]={66,33,40,22,55,88,60,11,80,20,50,44,77,30};
    float *C;

    cout<<"   ------ BUBBLE SORT ------"<<endl;
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

          C=new float[n];
          cout<<"   >>>";
          for(int i=0;i<n;i++)
           {
               cin>>C[i];
           }

            cout<<"   Array after sorting : "<<endl;
            cout<<"   >>>";
            
            BUBBLE_SORT(C,n);
        
                for(int i=0;i<n-1;i++)
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
            for(int i=0;i<n-1;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[n-1]<<endl;

            cout<<"   Array after sorting : "<<endl;
            cout<<"   >>>";
            BUBBLE_SORT(A,n);
          
                for(int i=0;i<n-1;i++)
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