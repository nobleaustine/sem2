# include <iostream>
using namespace std;

void SELECTION_SORT(float* DATA,int N)
{
    float TEMP;

   for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(DATA[j]<DATA[i])
            {
                TEMP=DATA[j];
                DATA[j]=DATA[i];
                DATA[i]=TEMP;
            }
        }
    }
}


int main()
{
    int n,choice=1;
    float *data;

    cout<<"   "<<endl;
    cout<<"      ------ SELECTION SORT ------"<<endl;
    
    while(choice==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the size of the array : ";
        cin>>n;
        cout<<"   "<<endl;
        
        data=new float[n];

        cout<<"   Enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin>>data[i];
        }
        cout<<"   "<<endl;

        SELECTION_SORT(data,n);
        
        cout<<"   Array after sorting : ";
        for(int i=0;i<n-1;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<data[n-1]<<endl;
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