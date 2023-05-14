#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void addValue(vector<int>& vec, int value) {
    if (vec.empty()){
        vec.push_back(value);
    } else {
        int i = 0;
        int size = vec.size();
        while (vec[i]>value && i<size){
            i++;
        }

        vec.insert(vec.begin()+i, value);
    }
}

void findMedian(int arr[], int n) {
    vector<int> myvec;
    for (int k=0; k<n; k++){
        addValue(myvec, arr[k]);
        int mid = myvec.size()/2;
        if (myvec.size()%2==0){
            cout << fixed << setprecision(1) << (myvec[mid]+myvec[mid-1])/2.0 << endl;
        } else {
            cout << fixed << setprecision(1) << myvec[mid]/1.0 << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the Number of entries: ";
    cin >> n;
    cout << endl;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;

    findMedian(arr, 4);

    return 0;
}
