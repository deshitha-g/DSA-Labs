#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int l = 2*root + 1;
    int r = 2*root + 2;
    int largest = root;

    if (l < n && arr[l] > arr[root]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (root != largest) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}


// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int i=n-1; i>=1; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        n--;

        heapify(arr, n, 0);
    }
}


/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    cout << arr[i] << " ";
    cout << "\n";
}


// main program
int main()
{
    cout << "Enter the array" << endl;
    string input;
    getline(cin, input);
    istringstream iss(input);

    vector<int> numbers;
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    int heap_arr[numbers.size()];
    for (int i=0; i<numbers.size(); i++) {
        heap_arr[i] = numbers[i];
    }

    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

    cout << endl << "Input array:" << endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array:" << endl;
    displayArray(heap_arr, n);
}
