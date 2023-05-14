#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int start, int end) {

    int pivot = arr[end];
    int i = start - 1;

    for (int j=start; j<end; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;
}

//recursive function
void quicksort(vector<int>& arr, int start, int end){
    if (end > start) {
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }
}

//non recursive function
void quickSort(vector<int>& arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    int size = 100000;

    srand(time(nullptr));

    vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(rand());
    }

    auto start_time = chrono::high_resolution_clock::now();

    quicksort(vec, 0, size-1);

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Execution time: " << duration.count() << "ms" << endl;

    return 0;
}
