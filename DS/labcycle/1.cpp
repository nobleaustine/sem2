# include <iostream>
using namespace std;

void INSERTION (int* DATA,int* N,int K,int ITEM)
{
    for(int i=*N;i>=K;i--)  
    {
        DATA[i+1]=DATA[i];
    }
    DATA[K]=ITEM;
    *N=*N+1;
    int *B=new int[*N];
    for(int k=0;k<*N;k++)
    {
        B[k]=DATA[k];
    }
    delete DATA;
    DATA=new int[*N+1];
    for(int j=0;j<*N-1;j++)
    {
        DATA[j]= B[j];
    }
    delete B;
}


int main()
{
    int k,l;
    int n=1;
    int *A;
    A=new int[k+1];
    cout<<" enter k"<<endl;
    cin>>k;
    for(int i=0;i<k;i++)
        {
            cin>>A[i];
        }
    while(n==1)
    {
        cout<<" enter item"<<endl;
        cin>>l;
        
        
        INSERTION(A,&k,3,l);

         for(int i=0;i<k-1;i++)
        {
            cout<<A[i]<<", ";
        }
        cout<<A[n-1]<<endl;
        
    }
}