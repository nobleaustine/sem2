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
    int n,choice=1;
    float *data;

    cout<<"   "<<endl;
    cout<<"      ------ BUBBLE SORT ------"<<endl;
    
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

        BUBBLE_SORT(data,n);
        
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