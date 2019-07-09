#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    int row, column;
    ifstream fileInput;
    fileInput.open("Input.txt");
    fileInput>>row>>column;
    int **Array;
    Array=new int*[row];
    for(int i=0; i<row; i++)
    {
        Array[i]=new int[column];
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            fileInput>>Array[i][j];
        }
    }
    ofstream fileOutput;
    fileOutput.open("Output.txt");
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<row; j++)
        {
            fileOutput<<Array[j][i]<<" ";
        }
        fileOutput<<endl;
    }
    return 0;
}
