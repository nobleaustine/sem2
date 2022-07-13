# include <iostream>
using namespace std;


int main()
{
    cout<<"       ------ INSERTING AND DELETING AN ELEMENT ------"<<endl;
    cout<<"   "<<endl;
    int option1,option2,n,k,choice=1;
    float Item;
    while(choice==1)
    {
        cout<<"   Enter the following options to continue :-"<<endl;
        cout<<"      1: enter a sorted array"<<endl;
        cout<<"      2: use a default array"<<endl;
        cout<<"   >>>";
        cin>>option1;
        cout<<"   "<<endl;
        
        if(option1==1)
        {
            cout<<"   Enter the size of the array"<<endl;
            cout<<"   >>>";
            cin>>namespace;
            float Data[n];
            cout<<"   "<<endl;
            
            cout<<"   Enter the elements of the array in ascending order"<<endl;
            cout<<"   >>>";
            for(int i=0;i<N;i++)
            {
                cin>>Data[i];
            }
            cout<<"   "<<endl;
            cout<<"   Choose an operation to continue :-"<<endl;
            cout<<"      1: to insert an element to the array"<<endl;
            cout<<"      2: to delete an element from the array"<<endl;
            cout<<"   >>>";
            cin>>option2;
            cout<<"   "<<endl;

            if(option2==1)
            {

            }

        }
         else if(option2==2)
        {
            float A[10]={2,4,6,8,10,12,14,16,18,20};

            cout<<"Default array :-"<<endl;
            for(int i=0;i<9;i++)
            {
                cout<<A[i]<<", ";
            }
            cout<<A[9]<<endl;
            cout<<"   "<<endl;

            cout<<"   Enter the element to be inserted"<<endl;
            cout<<"   >>>";
            cin>>Item;
            cout<<"   "<<endl;

            cout<<"   Enter the position where to be inserted"<<endl;
            cout<<"   >>>";
            cin>>k;
            cout<<"   "<<endl;
            int*B;
            B=INSERT(A,10,25,4)
            for(int i=0;i<10;i++)
            {
                cout<<B[i]<<", ";
            }

        }
        cout<<"   Would you like to continue :-"<<endl;
        cout<<"      1: to continue"<<endl;
        cout<<"      2: to exit"<<endl;
        cout<<"   >>>";
        cin>>choice;
        cout<<"   "<<endl;
    }
}
 cout<<"   Enter the number of elements in the array"<<endl;
    cout<<"   >>>";
    cin>>m;
    cout<<"   "<<endl;

    A= new int[m+1];

    cout<<"   1: to insert an element"<<endl;
    cout<<"   >>>";
    cin>>option;
    
    while(option==1)
    {
        cout<<"   Enter the position of the element"<<endl;
        cout<<"   >>>";
        cin>>k;
        cout<<"   "<<endl;


        cout<<"   Enter the element"<<endl;
        cout<<"   >>>";
        cin>>Item;
        cout<<"   "<<endl;

    
        

    }

  

int main()
{
    float *A;
    float *B;
    float Item;
    int m,n,k,option=1;
    
    cout<<"   Enter the size of the array"<<endl;
    cout<<"   >>>";
    cin>>m;
    A=new float[m+1]
    cout<<"   "<<endl;
    cout<<"   Enter the elements of the array in ascending order"<<endl;
    cout<<"   >>>";
    for(int i=0;i<n-1;i++)
    {
        cin>>A[i];
    }
    cout<<"   "<<endl;

    while(option==1)
    {
        cout<<"   Enter the position in the array"<<endl;
        cout<<"   >>>";
        cin>>k;
        cout<<"   "<<endl;

        cout<<"   Enter the item in the array"<<endl;
        cout<<"   >>>";
        cin>>Item;
        cout<<"   "<<endl;

        n=m+1;
        
        B=INSERT(A,m,9,int K)
    }

   


    cout<<"   Would you like to continue :-"<<endl;
    cout<<"      1: to continue"<<endl;
    cout<<"      2: to exit"<<endl;
    cout<<"   >>>";
    cin>>option;
    cout<<"   "<<endl; 
    return 0;