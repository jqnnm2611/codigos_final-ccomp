#include <iostream>
using namespace std;

int main() {
    int N = 10;
    int* A = new int[N * N];
    
    for(int* p = A; p < A + (N*N); p++)
        *p = 0;
    
    *(A + 22) = 1;
    *(A + 23) = 1;
    *(A + 24) = 1;
    *(A + 34) = 1;
    
    
    int cont = 0;
    for(int* p = A; p < A + (N*N); p++){
        cout << *p << ' ';
        cont++;
        if(cont == N){
            cout << endl;
            cont = 0;
        }
    }
    cout << endl;
    
    int n;
    cout << "Ingresa un número para el desplazamiento: ";
    cin >> n;
    cout << endl;
    
    auto desp = [&](int n){
        for(int* p = A + (N*N) - 1; p >= A; p--){
            if(*p == 1){
                *(p + (n*N) + n) = 1;
                *p = 0;
            }
        }
    };
    
    desp(n);
    
    for(int* p = A; p < A + (N*N); p++){
        cout << *p << ' ';
        cont++;
        if(cont == N){
            cout << endl;
            cont = 0;
        }
    }
    
    delete[] A;
    return 0;
}
