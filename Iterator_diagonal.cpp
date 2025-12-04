#include <iostream>
using namespace std;

template<class T>
class Iterator{
    T* it;
    int dim;
    public:
    void operator=(T* valor){
        it = valor;  
        dim = 10;
    }
    void operator=(T valor){
        *it = valor;
        dim = 10;
    }
    bool operator!=(T* it2){
        return it != it2;
    }
    T* operator++(int){
        return it = it + dim + 1;
    }
    T operator*(){
        return *it;
    }
};

template<class T, class I, int dim = 10>
class Matriz{
    T a[dim][dim];
    public:
    typedef I it_diagonal;
    T* begin(){
        return &a[0][0];
    }
    T* end(){
        return &a[dim][dim];
    }
};

int main() {
    Matriz<int,Iterator<int>> Ent;
    Matriz<int,Iterator<int>>:: it_diagonal It;
    
    int x = 10;
    for(It = Ent.begin(); It != Ent.end(); It++){
        It = x;
        x += 1;
    }
    for(It = Ent.begin(); It != Ent.end(); It++){
        cout << *It << ',';
    }
    return 0;
}
