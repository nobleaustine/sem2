# include <iostream>
using namespace std;

void INSERTION (float* DATA,int* N,int K,float ITEM)  
{
    for(int i=*N;i>=K;i--)  
    {
        DATA[i+1]=DATA[i];
    }
    DATA[K]=ITEM;
    *N=*N+1;
}

void DELETION (float* DATA,int* N,int K)
{
    for(int j=K;K<*N-1;j++)
    {
        DATA[j]=DATA[K+1];
    }
    *N=*N-1;

}

int main()
{
    float B[13]={10,22,35,40,45,50,80,82,85,90,100,235};
    float *data;
    float item;
    int option,n,k,con,choice=0;
    
    cout<<"   INSERTION AND DELETION ON LINEAR ARRAY"<<endl;
    cout<<"   "<<endl;
    while(choice==0)
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

           data=new float[n+1];
           for(int i=0;i<n;i++)
           {
               cin>>data[i];
           }

            cout<<"   New array : "<<endl;
            for(int i=0;i<n-1;i++)
            {
                cout<<data[i]<<", ";
            }
            cout<<data[n-1]<<endl;
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

        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : Insert an element to the array"<<endl;
        cout<<"      2 : Delete an element from the array"<<endl;
        cout<<"   >>>";
        cin>>con;

        if(con==1)
        {
            cout<<"   Enter the element to be inserted "<<endl;
            cout<<"   >>>";
            cin>>item;

            cout<<"   Enter the position where to be inserted "<<endl;
            cout<<"   >>>";
            cin>>k;

            if(option==1)
            {
                INSERTION(data,&n,k-1,item);
                cout<<"   Array after insertion : "<<endl;
                for(int i=0;i<n-1;i++)
                {
                    cout<<data[i]<<", ";
                }
                cout<<data[n-1]<<endl;
            }
            else if(option==2)
            {
                INSERTION(B,&n,k-1,item);
                cout<<"   Array after insertion : "<<endl;
                for(int i=0;i<n-1;i++)
                {
                    cout<<B[i]<<", ";
                }
                cout<<B[n-1]<<endl;
            }
        }
            
        else if(con==2)
        {
            cout<<"   Enter the position where deletion is done "<<endl;
            cout<<"   >>>";
            cin>>k;

            if(option==1)
            {
                DELETION(data,&n,k-1);
                cout<<"   Array after insertion : "<<endl;
                for(int i=0;i<n-1;i++)
                {
                    cout<<data[i]<<", ";
                }
                cout<<data[n-1]<<endl;
            }
            else if(option==2)
            {
                DELETION(B,&n,k-1);
                cout<<"   Array after insertion : "<<endl;
                for(int i=0;i<n-1;i++)
                {
                    cout<<B[i]<<", ";
                }
                cout<<B[n-1]<<endl;
            }
        }

         cout<<"   Would you like to exit the program"<<endl;
            cout<<"      1 : yes"<<endl;
            cout<<"      0 : no"<<endl;
            cout<<"   >>>";
            cin>>choice;


    }
   
    return 0;
}