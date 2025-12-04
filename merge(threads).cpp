#include <iostream>
#include <thread>
using namespace std;

void insertionSort(int* inicio, int* fin) {
    for (int* i = inicio + 1; i <= fin; i++) {
        int key = *i;
        int* j = i - 1;
        while (j >= inicio && *j > key) {
            *(j + 1) = *j;
            j = j - 1;
        }
        *(j + 1) = key;
    }
}

void merge(int* inicio, int* mitad, int* fin) {
    int* p = inicio;
    int* q = mitad + 1;

    while (p <= mitad && q <= fin) {
        if (*p <= *q) {
            p++; 
        } else {
            int temp = *q;
            int* j = q;
            while (j > p) {
                *j = *(j - 1);
                j--;
            }

            *p = temp;
            p++;
            mitad++;
            q++;
        }
    }
}

int main() {
    int n = 10;
    int arr[n] = {9,4,8,2,7,10,6,1,5,3};

    int* inicio = arr;
    int* fin = arr + n - 1;
    int* mitad = arr + (n/2) - 1;

    thread t1(insertionSort, inicio, mitad);
    thread t2(insertionSort, mitad + 1, fin);

    t1.join();
    t2.join();

    merge(arr, mitad, fin);

    for (int* p = arr; p <= fin; p++) {
        cout << *p << ",";
    }

    return 0;
}
