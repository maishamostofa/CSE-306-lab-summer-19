#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n=10000;
    ofstream fileInput;
    srand(89345);
    fileInput.open("Input(10000).txt");
    int*Array=new int[n];
    for(int i=0;i<n;i++)
    {
        Array[i]=rand();
        fileInput<<i+1<<") "<<Array[i]<<endl;

    }
    fileInput.close();
    clock_t startTime=clock();
    bubble_sort(Array,n);
    clock_t endTime=clock();
    ofstream fileOutput;
    fileOutput.open("Output1(10000).txt");
    for(int i=0;i<n;i++)
    {
        fileOutput<<i+1<<") "<<Array[i]<<endl;
    }
    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"timelapse: "<<timelapse<<endl;
    fileOutput<<endl<<"timelapse: "<<timelapse;
    fileOutput.close();
    delete[] Array;
}
