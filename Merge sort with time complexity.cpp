#include<iostream>
#define MAX 30
#include<time.h>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high-low+1];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];
    }
}


void mergeSort(int arr[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, size-1);
    clock_t end = clock();
    cout<<"printing array: "<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
    double time = double(end-start)/CLOCKS_PER_SEC;
    cout<<"time taken: "<<time*1000000<<" Microsseconds\n";
    return 0;
}


