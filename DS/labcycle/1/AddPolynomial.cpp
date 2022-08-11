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
    void Default(int **);
    void AddPoly(MATRIX &,MATRIX &);
    void ConvertDisplay();
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


void MATRIX::AddPoly(MATRIX &m1,MATRIX &m2)
{
    int i=1,j=1,k=1;
    int T1=m1.m[0][0];
    int T2=m2.m[0][0];
    
    while(i<=T1 and j<=T2)
    {
        if(m1.m[i][1]>m2.m[j][1])
        {
            m[k][0]=m1.m[i][0];
            m[k][1]=m1.m[i][1];
            i=i+1;
            k=k+1;
        }
        
        else if(m2.m[j][1]>m1.m[i][1])
        {
            m[k][0]=m2.m[j][0];
            m[k][1]=m2.m[j][1];
            j=j+1;
            k=k+1;
        }

        else
        {
            m[k][1]=m1.m[i][1];
            m[k][0]=m1.m[i][0]+m2.m[j][0];
            if(m1.m[i][0]+m2.m[j][0]!=0)
            {
                k=k+1;
            }
            else if(m1.m[i][1]==0 and (m1.m[i][0]+m2.m[j][0]==0))
            {
                k=k+1;
            }
            j=j+1;
            i=i+1;
        }
    }

    while(i<=T1)
    {
        m[k][0]=m1.m[i][0];
        m[k][1]=m1.m[i][1];
        i=i+1;            
        k=k+1;
    }

    while(j<=T2)
    {
        m[k][0]=m2.m[j][0];
        m[k][1]=m2.m[j][1];
        j=j+1;            
        k=k+1;
    }

    row=k;
    m[0][0]=k-1;
    m[0][1]=m[1][1];
}

void MATRIX::ConvertDisplay()
{
    if(m[1][0]>0)
    {
        cout<<m[1][0]<<"x^"<<m[1][1];
    }
    else
    {
       cout<<m[1][0]<<"x^"<<m[1][1]; 
    }
    
    for(int i=2;i<row;i++)
    {
        if(m[i][0]>0)
        {
            cout<<" + "<<m[i][0]<<"x^"<<m[i][1];
        }
        else
        {
            cout<<" - "<<-(m[i][0])<<"x^"<<m[i][1];
        }
        
    }
    
}

int main()
{
    int **M=new int *[4];

    for(int k=0;k<7;k++)
    {
        M[k]=new int[2];
    }

    M[0][0]=3;
    M[0][1]=4;
    
    M[1][0]=3;
    M[1][1]=4;
    

    M[2][0]=2;
    M[2][1]=2;

    M[3][0]=5;
    M[3][1]=0;

    int **L=new int *[5];

    for(int k=0;k<7;k++)
    {
        L[k]=new int[2];
    }

    L[0][0]=4;
    L[0][1]=3;

    L[1][0]=4;
    L[1][1]=3;

   L[2][0]=5;
   L[2][1]=2;

   L[3][0]=1;
   L[3][1]=1;

   L[4][0]=1;
   L[4][1]=0;

    MATRIX M1(4,2);
    MATRIX M2(5,2);
    MATRIX M3(8,2);

    M1.Default(M);
    M2.Default(L);
    M3.AddPoly(M1,M2);
    M3.Display();
    M1.ConvertDisplay();
    cout<<" "<<endl;
    M2.ConvertDisplay();
    cout<<" "<<endl;
    M3.ConvertDisplay();
    
return 0;
}