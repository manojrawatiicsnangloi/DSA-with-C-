// Selection Sort
#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {45, 35, 87, 64, 36, 98, 100, 42, 1, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printArr(arr, size);
    return 0;
}