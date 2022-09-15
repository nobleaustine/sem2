#include <iostream>
using namespace std;

// creating a class named matrix to make the magic square
class MATRIX
{
    int row,col;
    int**m;

public:
    MATRIX(int,int);
    ~MATRIX();
    void Display(void);// function to display magic square
    void MagicSquare();// function to create magic square

};

MATRIX::MATRIX(int x,int y)
{
    //intitializing the matrix
    row=x;
    col=y;
    m=new int*[row];
    for(int i=0;i<row;i++)
    {m[i]=new int[col];}

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            m[i][j]=0;
        }
       
    }
}

MATRIX::~MATRIX()
{
    // creating a destructor to free memory
    for(int i=0;i<row;i++)
    {delete m[i];}
    delete m;
}

void MATRIX::Display()
{
    // function to display the matrix
    for(int i=0;i<row;i++)
    {
        cout<<"      ";
        for(int j=0;j<col;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
}

void MATRIX :: MagicSquare()
{
    // creating and intializing R and C to input 1
    int R=row/2;
    int C=row-1;
    int input=1;
    
    // loop to continue insertion till the insertion of row^2 have been done
    while(input<=row*row)
    {
        // condition to check if row bound and coloumn bound is broken
        if(R==-1 and C==row)
        {
            R=0;
            C=row-2;
        }
         // condition to check if only row bound is broken
        else if(R==-1)
        {
            R=row-1;
        }
         // condition to check if only coloumn bound is broken
        else if(C==row)
        {
            C=0;
        }
        
        // condition to check if that position have already been filled

        if(m[R][C]!=0)
        {
            R=R+1;
            C=C-2;
            continue; // to recheck all old conditions as R and C is modified
        }

    m[R][C]=input;  //inserting the value
    input=input+1;  // incrementing input
    
    // modifying R and C for new insertion
    R=R-1;
    C=C+1;

}
}
int main()
{
    int N,choice=1;

    cout<<"   "<<endl;
    cout<<"         Program to print an odd magic square"<<endl;
    cout<<"        --------------------------------------"<<endl;
    cout<<"   "<<endl;

    while(choice==1)
    {
        cout<<"   Enter an odd number n to print nxn magic square : ";
        cin>>N;
        MATRIX M1(N,N);
        cout<<"   "<<endl;
        
        M1.MagicSquare();
        cout<<"   MAGIC SQUARE "<<endl;
        cout<<"   "<<endl;
        M1.Display();
        cout<<"   "<<endl;
        cout<<"   MAGIC CONSTANT : "<<(N*(N*N+1))/2<<endl;
        cout<<"   "<<endl;

        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"   >>>";
        cin>>choice;
        cout<<"   "<<endl;

    }
    

 return 0;
}