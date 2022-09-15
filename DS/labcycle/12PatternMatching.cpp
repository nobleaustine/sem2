# include <iostream>
using namespace std;

int MATCHING(char* T,char* P,int S,int R)
{
    int COUNT,K=0,MAX=S-R+1,INDEX=0;

    while(K<=MAX)
    {
        COUNT=0;
        for(int i=0;i<R;i++)
        {
            
            if(T[K+i]!=P[i])
            {
                K=K+1;
                break;
            }
            COUNT=COUNT+1;
        }
        if(COUNT==R)
        {
            INDEX=K;
            return INDEX;
        }
        
    }
    return INDEX;

}

int main()
{
    int l,n,index,choice=1;
    char *t;
    char *p;
    cout<<"   "<<endl;
    cout<<"          ------ PATTERN MATCHING ------"<<endl;

    while(choice ==1)
    {
        cout<<"   "<<endl;
        cout<<"   Enter the length of the text : ";
        cin>>n;

        t = new char[n];
        cout<<"   "<<endl;

        cout<<"   Enter the text for pattern matching : ";
        for(int j=0;j<n;j++)
        {
            cin>>t[j];
        }
        cout<<"   "<<endl;

        cout<<"   Enter the length of the pattern : ";
        cin>>l; 

        p= new char[l];
        cout<<"   "<<endl;
        
        cout<<"   Enter the pattern for matching : ";
        
        for(int j=0;j<l;j++)
        {
            cin>>p[j];
        }
        cout<<"   "<<endl;
        

       index=MATCHING(t,p,n,l);
    

        if(index!=0)
        {
            cout<<"   The pattern present at position "<<index+1<<endl;
        }
        else
        {
            cout<<"   The pattern is not present "<<endl;

        }

        delete t;
        delete p;

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