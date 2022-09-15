#include<iostream>
using namespace std;

class STRING
{
    int LEN;
    char* STR;

public:
    STRING();
    STRING(char*,int);
    void Display();
    void INSERT(char*,int,int);
    void DELETE(int,int);
    void REPLACE(char*,int,int);
};

STRING::STRING()
{
    LEN= 0;
    STR= new char[LEN + 1];
}

STRING::STRING(char* str,int len)
{
    LEN= len;
    STR= new char[LEN+1];

    for (int i=0;i<LEN;i++)
    {
        STR[i]= str[i];
    }
    STR[LEN]= '\0';
}

void STRING::INSERT(char* subs1,int sublen,int pos)
{
   
    STRING TEMP(STR,LEN);
    LEN= LEN+sublen;
    delete STR;
    
    STR= new char[LEN+1];
    
    for(int i=0;i<=pos;i++)
    {
        STR[i]= TEMP.STR[i];
    } 
    
    for(int j=pos;j<=sublen+1;j++)
    {
        STR[j]= subs1[j-pos];
    }
   
    for (int k=0;k<LEN-sublen+1;k++)
    {
        STR[pos+sublen+k]= TEMP.STR[pos+k];
    }

    STR[LEN]='\0';
}

void STRING::DELETE(int POS,int SUBLEN)
{
    for(int i=POS;i<=POS+SUBLEN;i++)
    {
        STR[i]=STR[i+SUBLEN];
    }

    LEN=LEN-SUBLEN;
    char TEMP[LEN];
    
    for(int i=0;i<LEN;i++)
    {
        TEMP[i]=STR[i];
    }

    delete STR;

    STR= new char[LEN + 1];

    for(int i=0;i<LEN;i++)
    {
        STR[i]= TEMP[i];
    }

    STR[LEN]= '\0';

}

void STRING::REPLACE(char* SUB,int POS,int SUBLEN)
{
    for(int i=POS;i<POS+SUBLEN;i++ )
    {
        STR[i]= SUB[i-POS];
    }
}

void STRING::Display()
{
    for(int i=0;i<LEN-1;i++)
    {
        cout<<STR[i];
    }
    cout<<STR[LEN-1]<<endl;
}

int main()
{
    int len,sublen,pos,option,choice=1;
    char* str;
    char* sub;

    cout<<"   "<<endl;
    cout<<"   ------ STRING OPERATIONS ------"<<endl;
    cout<<"   "<<endl;

    cout<<"   Enter the length of the string : ";
    cin>>len;
    cout<<"   "<<endl;

    str= new char [len+1];

    cout<<"   Enter the string : ";
    for(int i=0;i<len;i++)
    {
        cin>>str[i];
    }
    cout<<"   "<<endl;
    

    STRING STRM(str,len);
    
    while(choice==1)
    {
        cout<<"   Choose the following to continue : "<<endl;
        cout<<"      1 : to perform insertion"<<endl;
        cout<<"      2 : to perform deletion"<<endl;
        cout<<"      3 : to replace"<<endl;
        cout<<"        : ";
        cin>>option;
        cout<<"   "<<endl;

        if(option== 1)
        {
            cout<<"   Enter the length of the substring : ";
            cin>>sublen;
            cout<<"   "<<endl;

            sub= new char[sublen];
            

            cout<<"   Enter the substring to be inserted : ";
            for(int i=0;i<sublen;i++)
            {
                cin>>sub[i];
            }
            
            cout<<"   "<<endl;
            
            cout<<"   Enter the position from where to be inserted : ";
            cin>>pos;
            cout<<"   "<<endl;

            STRM.INSERT(sub,sublen,pos);
           
        } 
        else if(option== 2)
        {
            cout << "   Enter the position from where to be deleted : ";
            cin>>pos;
            cout<<"   "<<endl;

            cout<< "   Enter thr length of substring to be deleted : ";
            cin>>sublen;
            cout<<"   "<<endl;

            STRM.DELETE(pos,sublen);
        }
        else if (option== 3)
        {
            cout<<"   Enter the length of the substring : ";
            cin>>sublen;
            cout<<"   "<<endl;

            sub= new char[sublen+1];

            cout<<"   Enter the substring to replace : ";
            for(int i=0;i<sublen;i++)
            {   
                cin>>sub[i];
            }
            cout<<"   "<<endl;
            
            cout<<"   Enter the position from where to be replaced : ";
            cin>>pos;
            cout<<"   "<<endl;

            STRM.REPLACE(sub,sublen,pos);
        }

        cout<<"   String after operation : ";
        STRM.Display();
        cout<<"   "<<endl;

        cout<<"   Would you like to continue"<<endl;
        cout<<"      1 : yes"<<endl;
        cout<<"      0 : no"<<endl;
        cout<<"        : ";
        cin>>choice;
    }

return 0;
}