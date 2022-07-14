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

void DELETION (float* DATA,int* N,float ITEM)
{
    for(int j=0;j<*N;j++)
    {
        if(DATA[j]==ITEM)
        {
            for(int k=j;k<*N-1;k++)
            {
                DATA[k]=DATA[k+1];
            }
        }
    }
    *N=*N-1;

}

int main()
{
    float item;
    int n,k,option,select,choice=1;
    
    cout<<"   ------ INSERTION AND DELETION ON LINEAR ARRAY ------"<<endl;
    cout<<"   "<<endl;
    while(choice==1)
    {
        float *data1;
        float data2[12]={3,9,21,36,45,49,56,64,81,90,100};
        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : Enter a new array"<<endl;
        cout<<"      2 : Use a default array"<<endl;
        cout<<"   >>>";
        cin>>option;
        cout<<"   "<<endl;
        
        if(option==1)
        {
           cout<<"   Enter the number of elements in the array"<<endl;
           cout<<"   >>>";
           cin>>n;
           cout<<"   "<<endl; 

           data1=new float[n+1];
           cout<<"   >>>";
           for(int i=0;i<n;i++)
           {
               cin>>data1[i];
           }
           cout<<"   "<<endl;
        }
        
        else if(option==2)
        {
            n=11;

            cout<<"   Default array : "<<endl;
            for(int i=0;i<n-1;i++)
            {
                cout<<data2[i]<<", ";
            }
            cout<<data2[n-1]<<endl;
            cout<<"   "<<endl;

        }

        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : Insert an element to the array"<<endl;
        cout<<"      2 : Delete an element from the array"<<endl;
        cout<<"   >>>";
        cin>>select;
        cout<<"   "<<endl;

        if(select==1)
        {
            cout<<"   Enter the element to be inserted "<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;

            cout<<"   Enter the position where to be inserted "<<endl;
            cout<<"   >>>";
            cin>>k;
            cout<<"   "<<endl;

            if(option==1)
            {
                INSERTION(data1,&n,k-1,item);
                cout<<"   Array after insertion : "<<endl;
                cout<<"      ";
                for(int i=0;i<n-1;i++)
                {
                    cout<<data1[i]<<", ";
                }
                cout<<data1[n-1]<<endl;
            }
            else if(option==2)
            {
                INSERTION(data2,&n,k-1,item);
                cout<<"   Array after insertion : "<<endl;
                cout<<"      ";
                for(int i=0;i<n-1;i++)
                {
                    cout<<data2[i]<<", ";
                }
                cout<<data2[n-1]<<endl;
            }
            cout<<"   "<<endl;
        }
            
        else if(select==2)
        {
            cout<<"   Enter the element to be deleted "<<endl;
            cout<<"   >>>";
            cin>>item;
            cout<<"   "<<endl;

            if(option==1)
            {
                DELETION(data1,&n,item);
                cout<<"   Array after deletion : "<<endl;
                cout<<"      ";
                for(int i=0;i<n-1;i++)
                {
                    cout<<data1[i]<<", ";
                }
                cout<<data1[n-1]<<endl;
            }
            else if(option==2)
            {
                DELETION(data2,&n,item);
                cout<<"   Array after deletion : "<<endl;
                cout<<"      ";
                for(int i=0;i<n-1;i++)
                {
                    cout<<data2[i]<<", ";
                }
                cout<<data2[n-1]<<endl;
            }
            cout<<"   "<<endl;
        }

         cout<<"   Would you like to continue"<<endl;
         cout<<"      1 : yes"<<endl;
         cout<<"      0 : no"<<endl;
         cout<<"   >>>";
         cin>>choice;


    }
   
    return 0;
}