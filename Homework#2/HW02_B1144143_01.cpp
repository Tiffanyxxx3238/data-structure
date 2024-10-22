#include<bits/stdc++.h>
using namespace std;

//Binary Search function
int BinarySearch(int* a, const int x, const int n) { 
    int left = 0;//set left edge
    int right = n - 1;//set right edge
    while (left <= right) {//if left not bigger than right continue
        int middle = (left + right) / 2;//count middle index
        if (x < a[middle]) right = middle - 1;//if goal smaller than middle, then make right move to middle-1
        else if (x > a[middle]) left = middle + 1;//if goal bigger than middle, then make left move to middle+1
        else return middle;//if goal = middle, return middle
    }
    return -1;//if can't find goal, return -1
}
//measure Binary Search average runtime, each n make numTrials times test function
double measureTotalRuntime(int n, int numTrials) {
    if (n == 0) return 0.0;  //special process n=0 situation, because can't in none num run Binary Search, so return 0 
    
    vector<int> arr(n);//create the array n big
    for (int i = 0; i < n; ++i) {//use num[0,n-1] to put 
        arr[i] = i;
    }
    srand(time(NULL));//set random , basic by current time
    auto start = chrono::high_resolution_clock::now();  //use high float clock to record start runtime

    for (int trial = 0; trial < numTrials; ++trial) {//run numTrials times Binary Search, every time find random goal 
        int target = rand() % n;//create random goal in [0,n-1]
        BinarySearch(&arr[0], target, n);//in array run Binary Search
    }

    auto end = chrono::high_resolution_clock::now();  //reacord end runtime
    chrono::duration<double, nano> duration = end - start;//count how much time runtime
    
    return duration.count() / numTrials;  //return average each time Binary Search time, and all time /test num=one time runtime average time
}

int main() {
    cout << "Program started." << endl;
	//**I have try use .xlsx, but it can't open,so i create .csv then in excel store to .xlsx,and i set my file in num and english, to easy restore**
    ofstream outFile("C:/HW02_B1144143/binary_search_times.csv");//put the output in this excel 
    if (!outFile.is_open()) {//check excel current open or not
        cerr << "Error: Unable to open file for writing." << endl;
        return 1;
    }
    
    cout << "File opened successfully." << endl;
    outFile << "n,average_time_ns" << endl;//write header in excel

    for (int n = 0; n <= 100; n += 5) {  //by exercise say[0,100]
        cout << "Testing for n = " << n << endl;
        double avgTime = measureTotalRuntime(n, 1000000); 
        cout << "n = " << n << ", Average time: " << avgTime << " ns" << endl;
        outFile << n << "," << avgTime << endl;//put result in excel
    }

    outFile.close();
    cout << "Data has been written to binary_search_times.csv" << endl;
    return 0;
}


