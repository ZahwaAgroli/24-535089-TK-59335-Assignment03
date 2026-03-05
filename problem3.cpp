// Compilation command: g++ -std=c++17 -Wall -Wextra -g -fsanitize=address -o problem3 problem3.cpp

#include <iostream>
using namespace std;

// O(n) — checks each element one by one
// Returns index or -1 if not found
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// O(log n) — requires sorted array, narrows range by half each step
// Returns index or -1 if not found
int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // avoids overflow
        if (arr[mid] == target)      return mid;
        else if (arr[mid] < target)  lo = mid + 1;
        else                         hi = mid - 1;
    }
    return -1;
}

// Generates sorted even-numbered array: 0, 2, 4, ..., 2(n-1)
// Caller is responsible for delete[]
int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i * 2;
    return arr;
}

void runTest(int n) {
    int* arr = generateSortedArray(n);
    int existingTarget    = arr[n / 2];
    int nonExistingTarget = -1; // array only contains values >= 0

    cout << "--- Testing Array Size n = " << n << " ---" << endl;

    // target exists (middle element)
    int resLin = linearSearch(arr, n, existingTarget);
    int resBin = binarySearch(arr, n, existingTarget);
    cout << "Search existing (" << existingTarget << "): Linear=" << resLin
         << ", Binary=" << resBin << " -> " << (resLin == resBin ? "MATCH" : "FAIL") << endl;

    // target missing
    resLin = linearSearch(arr, n, nonExistingTarget);
    resBin = binarySearch(arr, n, nonExistingTarget);
    cout << "Search missing (" << nonExistingTarget << "): Linear=" << resLin
         << ", Binary=" << resBin << " -> " << (resLin == resBin ? "MATCH" : "FAIL") << endl;

    cout << endl;
    delete[] arr;
}

int main() {
    int sizes[] = {10, 100, 1000};
    for (int n : sizes)
        runTest(n);
    return 0;
}