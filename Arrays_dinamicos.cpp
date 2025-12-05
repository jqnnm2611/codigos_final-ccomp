#include <iostream>
using namespace std;

int main() {
    
    cout << "Array dinámico creado con 1 solo array (primera forma):" << endl;
    int N = 3;
    int* A = new int[N*N];
    
    int cont1 = 1;
    for(int*p = A; p < A + (N*N); p++, cont1++)
        *p = cont1;
    
    for(int* j = A; j < A + (N*N); j++)
        cout << *j << ' '; 
    
    delete[] A;
    
    cout << endl;
    cout << endl;
    
    cout << "Array dinámico creado con varios arrays (segunda forma):" << endl;
    int F = 3;
    int C = 3;
    int** B = new int*[F];
    
    int cont2 = 1;
    for(int** p = B; p < B + F; p++){
        *p = new int[C];
        for(int* q = *p; q < *p + C; q++, cont2++)
            *q = cont2;
    }
    
    for(int** x = B; x < B + F; x++){
        for(int* y = *x; y < *x + C; y++)
            cout << *y << ' '; 
    }
    
    for(int** p = B; p < B + F; p++)
        delete[] *p;
    delete[] B;
    
    return 0;
}
