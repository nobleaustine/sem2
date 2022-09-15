# include <iostream>
using namespace std;

class NODE{
    
    public:
       float info;
       NODE * link=NULL;
};


class LinkedList{

    NODE START;

    public:
      void Default();
      void Traverse();

};

void LinkedList ::Traverse(){
        NODE *DPTR;
        DPTR = START.link;
        while(DPTR!=NULL)
        {
           cout<<DPTR->info<<endl;
           DPTR=DPTR->link;
        }
}


void LinkedList :: Default(){

    NODE* PTR;
    START.link=new NODE();
    PTR=START.link;

    for(int i=1;i<6;i++)
    {
        PTR->info=i;
        PTR->link=new NODE();
        PTR=PTR->link;
    }
    PTR->info=6;
    
}


int main()
{
    LinkedList L1;
    L1.Default();
    L1.Traverse();


    return 0;
}


