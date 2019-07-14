#include <iostream>

using namespace std;
void maximum(int cointype[], int n, int value)
{
    int i, j, Count=0;
    for(i=0; i<n; i++)
    {
        if(value>=cointype[i])
        {
            value=value-cointype[i];
            cout<<cointype[i]<<" ";
            Count++;
        }

    }
    cout<<endl<<"Maximum number of coins: "<<Count<<endl;
    cout<<endl;
}
void minimum(int cointype[], int n, int value)
{
    int i, j, Count=0;
    for(i=n-1; i>0; i--)
    {
        if(value>=cointype[i])
        {
            value=value-cointype[i];
            cout<<cointype[i]<<" ";
            Count++;

        }

    }
    cout<<endl<<"Minimum number of coins: "<<Count<<endl;
    cout<<endl;
}
int main()
{
    int i, j, k=0, value=50, n=10, cointype[10];
    int coins[4]={5, 10, 20, 25};
    int numberOfCoin[4]={2, 3, 3, 2};
    cout<<"The coins are: ";
    for(i=0; i<4; i++)
    {
        for(j=0; j<numberOfCoin[i]; j++)
        {
            cointype[k]=coins[i];
            cout<< cointype[k]<<" ";
            k++;
        }
    }
    cout<<endl<<endl<<"The coins are: ";
    minimum(cointype, n, value);
    cout<<endl<<endl<<"The coins are: ";
    maximum(cointype, n, value);
    return 0;
}
