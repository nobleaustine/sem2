#include <iostream>
using namespace std;

int LINEAR_SEARCH(float *DATA,int N,float ITEM)
{
    int LOC=-1;
    
    for(int j=0;j<N;j++)
    {
        if(DATA[j]==ITEM)
        {
            LOC=j; 
            return LOC;
        }
    }
    
    return LOC; 
}

int main()
{
    int n,loc,choice=1;
    float item;
    cout<<"   "<<endl;
    cout<<"      ------ LINEAR SEARCH ------"<<endl;
    cout<<"   "<<endl;
    
    cout<<"   Enter the size of the array : ";
    cin>>n;
    cout<<"   "<<endl;
    
    float data[n];

    cout<<"   Enter the elements in the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }

    while(choice==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the item to be searched : ";
        cin>>item;
        cout<<"   "<<endl;
        
        loc=LINEAR_SEARCH(data,n,item);

        if(loc!=-1)
        {
            cout<<"   "<<"'"<<item<<"'"<<" is located at position "<<loc+1<<endl;  
        }
        else
        {
            cout<<"   "<<"'"<<item<<"'"<<" is not present in the array"<<endl;
        }
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