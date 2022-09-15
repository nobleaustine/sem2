# include <iostream>
using namespace std;

void INSERT (float* DATA,int* N,int POS,float ITEM)
{
    for(int i=*N;i>=POS;i--)  
    {
        DATA[i+1]=DATA[i];
    }
    DATA[POS]=ITEM;
    *N=*N+1;
}

void DELETE (float* DATA,int* N,float ITEM)
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
    int n,pos,select,choice=1;
    float *data;
    float item;

    cout<<"   "<<endl;
    cout<<"      ------ INSERTION AND DELETION IN AN ARRAY ------"<<endl;
    
    while(choice==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the size of the array : ";
        cin>>n;
        cout<<"   "<<endl;
        
        data=new float[n+1];

        cout<<"   Enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin>>data[i];
        }
        cout<<"   "<<endl;

        cout<<"   Choose from the following options to continue"<<endl;
        cout<<"      1 : to insert an element"<<endl;
        cout<<"      2 : to delete an element"<<endl;
        cout<<"        : ";
        cin>>select;
        cout<<"   "<<endl;

        if(select ==1)
        {
            cout<<"   Enter the element to be inserted : ";
            cin>>item;
            cout<<"   "<<endl;

            cout<<"   Enter the position where to be inserted : ";
            cin>>pos;
            cout<<"   "<<endl;

            INSERT(data,&n,pos-1,item);
            
            cout<<"   Array after insertion : ";
            for(int i=0;i<n;i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<"   "<<endl;
        }

        if(select ==2)
        {
            cout<<"   Enter the element to be deleted : ";
            cin>>item;
            cout<<"   "<<endl;

            DELETE(data,&n,item);
            
            cout<<"   Array after deletion : ";
            for(int i=0;i<n;i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<"   "<<endl;
        }
        
        delete data;
        
        cout<<"   "<<endl;
        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"        : ";
        cin>>choice;
    }
    cout<<"   "<<endl;
    
    return 0;
}