# include <iostream>
using namespace std;

void SUBSTRING_EXTRACTION(char *STR,int POS,int L,char *SUB)
{
 
    for(int i=0;i<L;i++)
    {
        SUB[i]=STR[POS +i];
    }
    SUB[POS + L]='\0';
}

int main()
{
    int l,n,pos;
    cout<<"   "<<endl;
    cout<<"       ------ SUBSTRING EXTRACTION ------"<<endl;
    cout<<"   "<<endl;
   
    cout<<"   Enter the length of the string for extraction  "<<endl;
    cout<<"   >>>";
    cin>>n;
    char* str=new char[n+1];
    cout<<"   "<<endl;

    cout<<"   Enter the string for extraction  "<<endl;
    cout<<"   >>>";
    for(int j=0;j<n;j++)
    {
        cin>>str[j];
    }
    str[n]='\0';
    cout<<"   "<<endl;

    cout<<"   Enter the length of the substring to be extracted  "<<endl;
    cout<<"   >>>";
    cin>>l; 
    char* sub= new char[l+1];
    cout<<"   "<<endl;


    cout<<"   Enter the position from where substring extraction is done  "<<endl;
    cout<<"   >>>";
    cin>>pos; 
    cout<<"   "<<endl;

    SUBSTRING_EXTRACTION(str,pos-1,l,sub);

    cout<<"   The extracted substring  "<<endl;
    cout<<"   >>>";
    for(int k=0;k<l;k++)
    {
        cout<<sub[k];
    }
    cout<<"   "<<endl;


    return 0;


}