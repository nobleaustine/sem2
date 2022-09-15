# include <iostream>
using namespace std;

class MATRIX
{
    int row,col;
    int**m;

public:
    MATRIX(int,int);
    ~MATRIX();
    void Input(void);
    void Display(void);
    void Convert(MATRIX &);
    void Addition(MATRIX &,MATRIX &);
    void Transpose(MATRIX &);
    void Convert1(MATRIX &);
    void Default(int **);
    void SparseAdd(MATRIX &,MATRIX &);

};

MATRIX::MATRIX(int x,int y)
{
    row=x;
    col=y;
    m=new int*[row];
    for(int i=0;i<row;i++)
    {m[i]=new int[col];}
}

MATRIX::~MATRIX()
{
    for(int i=0;i<row;i++)
    {delete m[i];}
    delete m;
}

void MATRIX::Input()
{
    for(int i=0;i<row;i++)
    {
        cout<<"      ";
        for(int j=0;j<col;j++)
        {
            cin>>m[i][j];
        }
        cout<<" "<<endl;
    }

}

void MATRIX::Display()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
}

void MATRIX::Transpose(MATRIX &M)
{
    int k=1;
    int n1=M.m[0][1];
    int n2=M.m[0][2];
    m[0][0]=M.m[0][1];
    m[0][1]=M.m[0][0];
    m[0][2]=M.m[0][2];

    for(int i=0;i<n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(i==M.m[j][1])
            {
                m[k][0]=M.m[j][1];
                m[k][1]=M.m[j][0];
                m[k][2]=M.m[j][2];
                k=k+1;
            }

        }
    }

}

void MATRIX::Convert1(MATRIX &M)
{
    int r;
    int c;
    int n1=M.m[0][2];

    for(int i=0;i<row;i++)
    {
      for(int j=0;j<col;j++)
        {
            m[i][j]=0;
        }  
    }
    
    for(int i=1;i<=n1;i++)
    {
        r=M.m[i][0];
        c=M.m[i][1];
        m[r][c]=M.m[i][2];
    }

}

void MATRIX::Default(int **M)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            m[i][j]=M[i][j];
        }
    }
}

void MATRIX::SparseAdd(MATRIX &M1,MATRIX &M2)
{
    int i=1,j=1,k=1;
    int T1=M1.m[0][2];
    int T2=M2.m[0][2];
    m[0][0]=M1.m[0][0];
    m[0][1]=M1.m[0][1];


    while(i<=T1 and j<=T2)
    {
        if(M1.m[i][0]<M2.m[j][0])
        {
            m[k][0]=M1.m[i][0];
            m[k][1]=M1.m[i][1];
            m[k][2]=M1.m[i][2];
            i=i+1;
            k=k+1;
        }
        
        else if(M2.m[j][0]<M1.m[i][0])
        {
            m[k][0]=M2.m[j][0];
            m[k][1]=M2.m[j][1];
            m[k][2]=M2.m[j][2];
            j=j+1;
            k=k+1;
        }
        else if(M2.m[j][1]<M1.m[i][1])
        {
            m[k][0]=M2.m[j][0];
            m[k][1]=M2.m[j][1];
            m[k][2]=M2.m[j][2];
            j=j+1;
            k=k+1;
        }

        else if(M1.m[i][1]<M2.m[j][1])
        {
            m[k][0]=M1.m[i][0];
            m[k][1]=M1.m[i][1];
            m[k][2]=M1.m[i][2];
            i=i+1;
            k=k+1;
        }
        else
        {
            m[k][0]=M1.m[i][0];
            m[k][1]=M1.m[i][1];
            m[k][2]=M1.m[i][2]+M2.m[j][2];
            if(M1.m[i][2]+M2.m[j][2]!=0)
            {
                k=k+1;
            }
            j=j+1;
            i=i+1;
        }

    }

    while(i<=T1)
    {
        m[k][0]=M1.m[i][0];
        m[k][1]=M1.m[i][1];
        m[k][2]=M1.m[i][2];
        i=i+1;            
        k=k+1;
    }

    while(j<=T2)
    {
        m[k][0]=M2.m[j][0];
        m[k][1]=M2.m[j][1];
        m[k][2]=M2.m[j][2];
        j=j+1;            
        k=k+1;
    }

    row=k;
    m[0][2]=k-1;
}

int main()
{
    cout<<"   "<<endl;
    cout<<"       ------ TRANSPOSE OF SPARSE MATRIX ------"<<endl;
    cout<<"   "<<endl;
   
    int **M=new int *[7];

    for(int k=0;k<7;k++)
    {
        M[k]=new int[3];
    }

    M[0][0]=5;
    M[0][1]=6;
    M[0][2]=6;

    M[1][0]=0;
    M[1][1]=4;
    M[1][2]=9;

    M[2][0]=1;
    M[2][1]=1;
    M[2][2]=8;

    M[3][0]=2;
    M[3][1]=0;
    M[3][2]=4;

    M[4][0]=2;
    M[4][1]=3;
    M[4][2]=2;

    M[5][0]=3;
    M[5][1]=5;
    M[5][2]=5;

    M[6][0]=4;
    M[6][1]=2;
    M[6][2]=2;

   MATRIX M1(7,3);
   MATRIX M2(7,3);
   MATRIX M3(5,6);
   MATRIX M4(6,5);

    M1.Default(M);
    M2.Transpose(M1);
    M3.Convert1(M1);
    M4.Convert1(M2);

    cout<<"   Sparse Matrix M1 "<<endl;
    M3.Display();
    cout<<"   "<<endl;

    cout<<"   Triplet Representation "<<endl;
    M1.Display();
    cout<<"   "<<endl;

    cout<<"   Transpose of Sparse Matrix M1 "<<endl;
    M4.Display();
    cout<<"   "<<endl;

    cout<<"   Triplet Representation "<<endl;
    M2.Display();
    cout<<"   "<<endl;


   

    return 0;
}