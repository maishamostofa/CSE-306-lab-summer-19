#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void insertion_sort(int arr[],int n)
{
    int i,key,index;
    for(i=1;i<n;i++)
    {
      key=arr[i];
      index=i-1;
      while((index>=0) &&  (arr[index]>key))
      {
          arr[index+1]=arr[index];
          index=index-1;
      }
      arr[index+1]=key;
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
    insertion_sort(Array,n);
    clock_t endTime=clock();
    ofstream fileOutput;
    fileOutput.open("Output2(10000).txt");
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
