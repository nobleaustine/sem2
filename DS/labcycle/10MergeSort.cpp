# include <iostream>
using namespace std;

void MERGING(float *A,int R,int LBA,float* B,int S,int LBB,float *C,int LBC)
{
    int NA=LBA,NB=LBB,PTR=LBC;
    int UBA=LBA+R-1,UBB=LBB+S-1;

    while(NA<=UBA && NB<=UBB)
    {
        if(A[NA]<B[NB])
        {
            C[PTR]=A[NA];
            NA=NA+1;
            PTR=PTR+1;
        }
        else
        {
            C[PTR]=B[NB];
            NB=NB+1;
            PTR=PTR+1;
        }
    }

    if(NA>UBA)
    {
        for(int i=0;i<=UBB-NB;i++)
        {
            C[PTR+i]=B[NB+i];
        }
    }
    else
    {
        for(int i=0;i<=UBA-NA;i++)
        {
            C[PTR+i]=A[NA+i];
        }

    }
}

void MERGE_PASS(float *A,int N,int L,float *B)
{
    int Q=N/(2*L);
    int S=2*L*Q;
    int R=N-S;
    int LB;

     for(int j=1;j<=Q;j++)
    {
        LB=(2*j-2)*L;
        MERGING(A,L,LB,A,L,LB+L,B,LB);
    }

    if(R<=L)
    {
        for(int k=0;k<R;k++)
        {
            B[S+k]=A[S+k];
        }
    }
    else
    {
        MERGING(A,L,S,A,R-L,L+S,B,S);
    }
}

void MERGE_SORT(float *A,float *B,int N)
{
    int L=1;
    
    while(L<N)
    {
        MERGE_PASS(A,N,L,B);
        MERGE_PASS(B,N,2*L,A);
        L=4*L;
    }

}

int main()
{
    int n,choice=1;
    float *A;
    float *B;
    

    cout<<"   "<<endl;
    cout<<"      ------ MERGE SORT ------"<<endl;
    
    while(choice==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the size of the array : ";
        cin>>n;
        cout<<"   "<<endl;
        
        A=new float[n];
        B=new float[n];


        cout<<"   Enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        cout<<"   "<<endl;

        MERGE_SORT(A,B,n);
        
        cout<<"   Array after sorting : ";
        for(int i=0;i<n-1;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<A[n-1]<<endl;
        cout<<"   "<<endl;
        
        delete A;
        delete B;

        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"        : ";
        cin>>choice;
    }
    cout<<"   "<<endl;
    
    return 0;
}
