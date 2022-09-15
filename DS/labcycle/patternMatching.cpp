# include <iostream>
using namespace std;

int MATCHING(char* T,char* P,int S,int R)
{
    int c,k=0,Max=S-R+1;

    while(k<=Max)
    {
        c=0;
        for(int i=0;i<R;i++)
        {
            
            if(T[k+i]!=P[i])
            {
                k=k+1;
                break;
            }
            c=c+1;
        }
        if(c==R)
        {
            return k;
        }
        
    }
    return 0;

}

int main()
{
    int l,n,pos;
    cout<<"   "<<endl;
    cout<<"          ------ PATTERN MATCHING ------"<<endl;
    cout<<"   "<<endl;
   
    cout<<"   Enter the length of the text for pattern matching  "<<endl;
    cout<<"   >>>";
    cin>>n;
    char *T = new char[n];
    cout<<"   "<<endl;

    cout<<"   Enter the text for pattern matching  "<<endl;
    cout<<"   >>>";
    for(int j=0;j<n;j++)
    {
        cin>>T[j];
    }
    cout<<"   "<<endl;

    cout<<"   Enter the length of the pattern  "<<endl;
    cout<<"   >>>";
    cin>>l; 
    char* P= new char[l];
    cout<<"   "<<endl;
    
    cout<<"   Enter the pattern for matching  "<<endl;
    cout<<"   >>>";
    for(int j=0;j<l;j++)
    {
        cin>>P[j];
    }
    cout<<"   "<<endl;
    

   pos=MATCHING(T,P,n,l);
   

    if(pos!=0)
    {
        cout<<"   The pattern present at position "<<pos+1<<endl;
    }
    else
    {
        cout<<"   The pattern is not present "<<endl;

    }
    cout<<"   "<<endl;









    return 0;
}