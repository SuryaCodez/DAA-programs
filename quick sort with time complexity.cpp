#include<iostream>
#include<ctime>
#define MAX 20

using namespace std;

int partition(int arr[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    
    while(i<=high)
    {
        if(arr[i]>pivot)
            i++;
        else
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort(int arr[], int low, int high)
{
    int pivot, pos;
    if(low<high)
    {
        pivot = arr[high];
        pos = partition(arr, low, high, pivot);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos+1, high);
    }
}

int main()
{
    int arr[MAX], size;
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Enter elements: "<<endl;
    for (int i=0;i<size;i++)
        cin>>arr[i];
    clock_t start = clock();
    quickSort(arr, 0, size-1);
    clock_t end = clock();
    cout<<"printing array: "<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
    double time = double(end-start)/CLOCKS_PER_SEC;
    cout<<"time taken: "<<time*1000000<<" Microsseconds\n";
    return 0;
}


