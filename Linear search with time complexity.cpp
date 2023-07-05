#include<iostream>
#include<ctime>
#define max 20
using namespace std;
int lin(int arr[],int key,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}
int main()
{
    int arr[max],size,i,elem,idx;
    cout<<"enter the size of array:\n";
    cin>>size;
    cout<<"enter the elements of array:\n";
    for(i=0;i<size;i++)
        cin>>arr[i];
    cout<<"enter element to be searched:\n";
    cin>>elem;
    clock_t start=clock();
    idx=lin(arr,size,elem);
    clock_t end=clock();
    (idx==-1)?cout<<"element not found":cout<<"element found at index:"<<idx;
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"\nthe time taken for linear search is:\n"<<time*1000000<<"microsecs";
    return 0;
}
