#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void Merge(int arr[],int x, int y,int z)
{

	int i, j, k;
	int n1=y-x+1;
	int n2=z-y;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
	   L[i]=arr[x+i];
	}
	for(j=0;j<n2;j++)
	{
	   R[j]=arr[y+j+1];
	}
	i=0;
	j=0;
	for(k=x;i<n1&&j<n2;k++)
	{
	   if(L[i]<R[j])
	   {
	      arr[k]=L[i++];
	   }
       else
	   {
	      arr[k]=R[j++];
       }
	}
	while(i<n1)
	{
	   arr[k++]=L[i++];
	}
	while(j<n2)
	{
	   arr[k++]=R[j++];
	}
}

void merge_sort(int arr[],int x,int z)
{
    int y;
	if(x<z)
	{
	   y=(x+z)/2;
	   merge_sort(arr,x,y);
	   merge_sort(arr,y+1,z);
	   Merge(arr,x,y,z);
	}
}

int main()
{
    int n=100000;
    ofstream fileInput;
    srand(89345);
    fileInput.open("Input(100000).txt");
    int*Array=new int[n];
    for(int i=0;i<n;i++)
    {
        Array[i]=rand();
        fileInput<<i+1<<") "<<Array[i]<<endl;
    }
    fileInput.close();
    clock_t startTime=clock();
    merge_sort(Array, 0, n-1);
    clock_t endTime=clock();
    ofstream fileOutput;
    fileOutput.open("Output(100000).txt");
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
