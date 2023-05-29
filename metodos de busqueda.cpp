#include <iostream>
using namespace std;

void bubbleSort(int array[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

void insertSort(int array[], int n){
    int i;
    for(i = 1; i < n; i++){
        int key = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void selectSort(int array[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        int min_idx = i;
        for(j = i+1; j < n; j++){
            if(array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        swap(array[i], array[min_idx]);
    }
}

void shellSort(int array[], int n){
    int gap, i, j;
    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            int temp = array[i];
            for(j = i; j >= gap && array[j-gap] > temp; j -= gap){
                array[j] = array[j-gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
    int opcion, n;
    cout<<"Ingrese la cantidad de elementos que desea en el vector: ";
    cin>>n;
    int array[n];
    cout<<"Ingrese los elementos del vector: ";
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }
    cout<<"Elija el metodo de busqueda:\n";
    cout<<"1. Bubble Sort\n";
    cout<<"2. Select Sort\n";
    cout<<"3. Insert Sort\n";
    cout<<"4. Shell Sort\n";
    cout<<"Opcion: ";
    cin>>opcion;
    switch(opcion){
        case 1: bubbleSort(array, n);
                break;
        case 2: insertSort(array, n);
                break;
        case 3: selectSort(array, n);
                break;
        case 4: shellSort(array, n);
                break;
        default: cout<<"Opcion no valida\n";
        return 0;
    }
    cout<<"El vector ordenado es: ";
    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}