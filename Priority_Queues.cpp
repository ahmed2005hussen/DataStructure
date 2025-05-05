#include <iostream>

using namespace std;
class Priority_Queues{
private:
    int *arr;
    int size;
    int heapSize;
public:

    Priority_Queues(int n = 10){
        size = n;
        heapSize = 0;
        arr = new int[n+1] ;
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

    void INSERT(int n){
        if(heapSize + 1 == size){
            int *temp = new int[size*2];
            for(int i = 1; i<= size; i++){
                temp[i]=arr[i];
            }
            delete []arr;
            arr = temp;
            size = size*2;
        }
        arr[++heapSize] = INT_MIN;
        INCREASE_KEY(heapSize,n);
    }

   int EXTRACT_MAX(){
        if(heapSize==0){
        throw runtime_error("empty");
        }
        int max = arr[1];
        swap(arr[1],arr[heapSize]);
        heapSize--;
        MAX_HEAPIFY(1);
       return max;
    }

    int  MAXIMUM(){
        if(heapSize==0){
            throw runtime_error("empty");
        }
        return arr[1];
    }

    void INCREASE_KEY(int x,int k){
         if(k<arr[x])
         {
             cout<< "this is small than the current key" <<endl;
         }
         arr[x]=k;
         while(x>1){
             if(arr[x] > arr[x/2]){
                 swap(arr[x] , arr[x/2]);
             }
             x = x / 2;
         }
    }


    ~Priority_Queues(){
        delete []arr;
    }
};

int main(){
  Priority_Queues a;
  a.INSERT(2);
  a.INSERT(122);
  a.INSERT(23);
  a.INSERT(21);
  a.INSERT(1112);
    cout<< a.MAXIMUM() <<endl;
   a.EXTRACT_MAX();
    cout<< a.MAXIMUM() <<endl;
    a.EXTRACT_MAX();
    cout<< a.MAXIMUM() <<endl;
    a.EXTRACT_MAX();
    cout<< a.MAXIMUM() <<endl;
    a.EXTRACT_MAX();
    cout<< a.MAXIMUM() <<endl;
    a.EXTRACT_MAX();
    cout<< a.MAXIMUM() <<endl;

}
