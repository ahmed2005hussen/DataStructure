#include <iostream>

using namespace std;

class heap {
private:
    int *arr;
    int size;
    int heapSize;
public:
    heap(int s = 10) {
        size = s;
        heapSize = 0;
        arr = new int[s];
    }

    heap(int arr[], int n) {

        size = n+1;
        heapSize = n;
        this->arr = new int[size];
        for (int i = 1; i < size; i++) {
            this->arr[i] = arr[i];
        }
    }

    void MAX_HEAPIFY(int i){
        int largest = i;
        int l = i*2; int r = l + 1;
        if(l <= heapSize && arr[l] > arr[largest]){
            largest = l ;
        }

        if(r<= heapSize && arr[r] > arr[largest]){
            largest = r ;
        }

        if(largest != i ){
             swap(arr[i], arr[largest]);
            MAX_HEAPIFY(largest);
        }
    }

    void BUILD_MAX_HEAP() {
        for(int i = heapSize/2 ; i >= 1; i--){
            MAX_HEAPIFY(i);
        }
    }

    void HEAPSORT() {
        int newsize = heapSize;

        for(int i = heapSize ; i >=2; i--){
            swap(arr[i],arr[1]);
            heapSize--;
            MAX_HEAPIFY(1);
        }
        heapSize = newsize;
    }

    void print(){
        if(heapSize==0){
            cout<< "empty heap "<< endl;
            return;
        }
        cout<< "Heap is: ";
        for(int i = 1 ; i <= heapSize ;i++){
            cout<< arr[i] << " ";
        }
        cout<< endl;
    }


    ~heap() {
        delete[]arr;
    }
};


int main(){
    int arr[11] = {0,4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heap a(arr,10);
    a.BUILD_MAX_HEAP() ;
    a.HEAPSORT();
    a.print();
}
