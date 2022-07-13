# include <iostream>
using namespace std;

void BUBBLE_SORT(float *DATA,int N)
{
    float TEMP;
    while(N>1)
    {
        for(int i=0;i<N-1;i++)
        {
            if(DATA[i]>DATA[i+1])
            {
                TEMP=DATA[i+1];
                DATA[i+1]=DATA[i];
                DATA[i]=TEMP;
            }

        }
        N=N-1;
        cout<<N<<endl;
    }
}

int main()
{
    float data[8]={32,51,27,85,66,23,13,57};
    int n=8;

    BUBBLE_SORT(data,n);

    for(int i=0;i<n;i++)
    {
        cout<<data[i]<<", ";
    }


    return 0;
}