#include <iostream>
using namespace std;

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
    int* arr = new int[n]{2,4,7,8,9,1,3,5,6,10};

    int* inicio = arr;
    int* fin = arr + n - 1;
    int* mitad = arr + (n/2) - 1;

    merge(arr, mitad, fin);

    for (int* p = arr; p <= fin; p++) {
        cout << *p << ",";
    }

    delete[] arr;
    return 0;
}
