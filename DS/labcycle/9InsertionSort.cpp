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
    int n,choice=1;
    float *data;

    cout<<"   "<<endl;
    cout<<"      ------ INSERTION SORT ------"<<endl;
    
    while(choice==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the size of the array : ";
        cin>>n;
        cout<<"   "<<endl;
        
        data=new float[n+1];

        cout<<"   Enter the elements in the array : ";
        for(int i=1;i<n+1;i++)
        {
            cin>>data[i];
        }
        cout<<"   "<<endl;

        INSERTION_SORT(data,n);
        
        cout<<"   Array after sorting : ";
        for(int i=1;i<n;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<data[n]<<endl;
        cout<<"   "<<endl;
        
        delete data;

        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"        : ";
        cin>>choice;
    }
    cout<<"   "<<endl;
    
    return 0;
}