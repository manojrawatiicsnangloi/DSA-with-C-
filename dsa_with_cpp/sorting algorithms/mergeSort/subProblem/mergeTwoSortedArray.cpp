#include <iostream>
using namespace std;

int merge (int lArr [], int rArr[], int resultArr [], int size1, int size2){
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < size1 && j < size2){
        if (lArr[i] > rArr[j]){
            resultArr[k++] = rArr[j++];
        }
        else{
            resultArr[k++] = lArr[i++];
        }
    }
    
    while(i < size1){
            resultArr[k++] = lArr[i++];
    }
    
    while (j < size2){
            resultArr[k++] = rArr[j++];
    }
    
    return 1;
}
int main() {
    int arr1 []= { 16, 17, 19, 23, 54, 67, 89 };
    int arr2 [] = {12, 13, 15, 90, 98, 101};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size = size1 + size2;
    int resultArr [size];
    
    merge(arr1, arr2, resultArr, size1, size2);
     for (int i : resultArr){
         cout << i << ' ';
     };
    return 0;
}