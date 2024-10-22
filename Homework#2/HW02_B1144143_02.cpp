#include <bits/stdc++.h>
using namespace std;

// SelectionSort function
void SelectionSort(int* a, const int n) {
    for (int i = 0; i < n; i++) {//run all element
        int j = i;
        for (int k = i + 1; k < n; k++) {//find remain the smallest element to chang with i
            if (a[k] < a[j]) {
                j = k;
            }
        }
        swap(a[i], a[j]);
    }
}

// measure SelectionSort worst-case runtime, run numTrials times for each n
double measureSelectionSortRuntime(int n, int numTrials) {
    if (n == 0) return 0.0;  // handle n=0 case, return 0 for empty array
    
    vector<int> arr(n); // create an array of size n
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i; // fill array in decreasing order (worst case)
    }
    
    auto start = chrono::high_resolution_clock::now(); // start timing

    for (int trial = 0; trial < numTrials; ++trial) {
        // copy the worst-case array for each trial
        vector<int> arrCopy = arr;
        SelectionSort(&arrCopy[0], n); // run SelectionSort
    }

    auto end = chrono::high_resolution_clock::now(); // end timing
    chrono::duration<double, micro> duration = end - start; // measure time
    
    return duration.count() / numTrials; // return average time per trial
}

int main() {
    cout << "Program started." << endl;
//**I have try use .xlsx, but it can't open,so i create .csv then in excel store to .xlsx,and i set my file in num and english, to easy restore**
    ofstream outFile("C:/HW02_B1144143/selectionsort_worst_case__runtimes.csv"); // open CSV file for output
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return 1;
    }

    cout << "File opened successfully." << endl;
    outFile << "n,worst_case run time" << endl; // write header in excel

    // run the measurement for different sizes of n
    for (int n = 0; n <= 3000; n += 100) { // //by exercise say[0,3000],test n from 0 to 3000 in steps of 100
        cout << "Testing for n = " << n << endl;
        
        // increase numTrials for small values of n to accumulate measurable time
        int numTrials = (n < 1000) ? 1000 : 10;

        double worstcaseTime = measureSelectionSortRuntime(n, numTrials); // measure average runtime
        cout << "n = " << n << ", Worst_case runtimes: " << worstcaseTime << " ns" << endl;
        outFile << n << "," << worstcaseTime << endl; // put results in excel
    }

    outFile.close();
    cout << "Data has been written to selectionsort_worst_case_times.csv" << endl;
    return 0;
}

