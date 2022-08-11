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
    char str[6]="noble";
    char sub[4];

    SUBSTRING_EXTRACTION(str,1,3,sub);
    cout<<sub<<endl;

    return 0;


}