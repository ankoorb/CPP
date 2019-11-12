#include <iostream>
#include <cstdlib>


using namespace std;

class Array{

private:
    int* A;
    int size;
    int length;

public:
    Array(int size, int length, bool sorted=false, bool zeros=false){

        this->size = size;
        this->length = length;

        A = new int [size];

        if (sorted){
            cout << "Enter ints in sorted manner" << endl;
            for (int i = 0; i < length; i++){
                cout << "Enter element " << i << " : " << flush;
                cin >> A[i];
            }
        } else if (zeros) {
            for (int i = 0; i < length; i++){
                A[i] = 0;
            }
        } else {
            for (int i = 0; i < length; i++){

                int val;
                val = rand() % 100;  // Random int in range 0 to 100

                // Generate random binary int
                if (rand() % 2){
                    A[i] = -1 * val;
                } else {
                    A[i] = val;
                }

            }
        }
    }

    Array(const Array& B){
        size = B.size;
        length = B.length;

        A = new int [size];

        // Copy values from B
        for (int i = 0; i < B.length; i++){
            A[i] = B.A[i];
        }
    }

    int Get(int index){
        if (index >= 0 && index < length){
            return A[index];
        }
    }

    void Set(int index, int x){
        if (index >= 0 && index < length){
            A[index] = x;
        }
    }

    int Max(){
        int max = 0;
        for (int i = 0; i < length; i++){
            if (A[i] > max){
                max = A[i];
            }
        }
        return max;
    }

    int Min(){
        int min = 0;
        for (int i = 0; i < length; i++){
            if (A[i] < min){
                min = A[i];
            }
        }
        return min;
    }

    int Sum(){
        int s = 0;
        for (int i=0; i < length; i++){
            s += A[i];
        }
        return s;
    }

    double Avg(){
        double s = 0;
        for (int i=0; i < length; i++){
            s += A[i];
        }
        return s/length;
    }

    void Append(int x){
        if (length < size){
            A[length] = x;
            length++;
        }
    }

    void Insert(int index, int x){
        if (index >= 0 && index <= length){
            for (int i = length; i > index; i--){
                A[i] = A[i-1];
            }
            A[index] = x;
            length++;
        }
    }

    void AuxiliaryReverse(){
        int* B = new int [length];  // Length is # of elements

        for (int i = length - 1, j = 0; i >= 0; i--, j++){
            B[j] = A[i];
        }

        for (int i = 0; i < length; i++){
            A[i] = B[i];
        }

        delete[] B;
        B = nullptr;
    }

    void Reverse(){
        for (int i = 0, j = length - 1; i < j; i++, j--){
            swap(&A[i], &A[j]);
        }
    }

    void LeftRotate(){
        int temp = A[0];
        for (int i = 0; i < length; i++){
            A[i] = A[i+1];
        }
        A[length-1] = temp;
    }

    void insertInSorted(int x){

        // If length = size then there is no space to add element
        if (length == size){
            return;
        }

        int i = length - 1;
        while (i >= 0 && A[i] > x){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = x;
        length++;

    }

    bool isSorted(){
        for (int i = 0; i < length - 1; i++){
            if (A[i] > A[i+1]){
                return false;
            }
        }
        return true;
    }

    void NegPosRearrange(){
        int i = 0;
        int j = length - 1;
        while (i < j){
            while (A[i] < 0){
                i++;
            }
            while (A[j] >= 0){
                j--;
            }
            if (i < j){
                swap(&A[i], &A[j]);
            }
        }
    }

    void swap(int* x, int* y){
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    int LinearSearch(int key){
        for (int i=0; i < length; i++){
            if (A[i] == key){
                //swap(&A[i], &A[i-1]);  // 1. Transposition
                swap(&A[i], &A[0]);  // 2. Move to Head
                return i;
            }
        }
        return -1;
    }

    int BinarySearch(int key){
        int l = 0;
        int h = length - 1;
        int mid;
        while (l <= h){
            mid = l + (h - l)/2;
            if (key == A[mid]){
                return mid;
            } else if (key < A[mid]){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    int RecursiveBinarySearch(int l, int h, int key){
        int mid;
        if (l <= h){
            mid = l + (h - l)/2;
            if (key == A[mid]) {
                return mid;
            } else if (key < A[mid]){
                return RecursiveBinarySearch(l, mid-1, key);
            } else {
                return RecursiveBinarySearch(mid+1, h, key);
            }
        }
        return -1;
    }

    int Delete(int index){

        if (index >= 0 && index <= length){
            int x = A[index];
            for (int i = index; i < length-1; i++){
                A[i] = A[i+1];
            }
            length--;
            return x;
        }
    }

    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }

    Array Merge(Array& B){
        Array C(length + B.length, length + B.length, false, true);  // This is wrong!
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < length && j < B.length){
            if (A[i] < B.Get(j)){
                C.Set(k++, A[i++]);
            } else {
                C.Set(k++, B.Get(j++));
            }
        }
        for (; i < length; i++){
            C.Set(k++, A[i]);
        }
        for (; j < B.length; j++){
            C.Set(k++, B.Get(j));
        }
        return C;
    }

    Array Union(Array& B){
        Array C(length + B.length, length + B.length, false, true);  // This is wrong!
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < length && j < B.length){
            if (A[i] < B.Get(j)){
                C.Set(k++, A[i++]);
            } else if (A[i] > B.Get(j)){
                C.Set(k++, B.Get(j++));
            }
            else {
                i++;
                j++;
            }
        }
        for (; i < length; i++){
            C.Set(k++, A[i]);
        }
        for (; j < B.length; j++){
            C.Set(k++, B.Get(j));
        }
        return C;
    }

    Array Intersection(Array& B){
        Array C(length + B.length, length + B.length, false, true);  // This is wrong!
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < length && j < B.length){
            if (A[i] < B.Get(j)){
                i++;
            } else if (A[i] > B.Get(j)){
                j++;
            }
            else {
                C.Set(k++, A[i]);
                i++;
                j++;
            }
        }

        return C;
    }

    Array Difference(Array& B){
        Array C(length + B.length, length + B.length, false, true);  // This is wrong!
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < length && j < B.length){
            if (A[i] < B.Get(j)){
                C.Set(k++, A[i]);
                i++;
            } else if (A[i] > B.Get(j)){
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        for (; i < length; i++){
            C.Set(k++, A[i]);
        }

        return C;
    }

    ~Array(){
        delete[] A;
    }


};


int main() {


//    Array arr(10, 10);
//    arr.display();
//
//    arr.Append(-1);
//    arr.display();
//
//    arr.Insert(2, 100);
//    arr.display();
//
//    int d = arr.Delete(2);
//    arr.display();
//    cout << d << endl;
//
//    d = arr.LinearSearch(4);
//    cout << d << endl;
//
//    d = arr.LinearSearch(44);
//    cout << d << endl;
//    arr.display();
//
//    d = arr.BinarySearch(9);
//    cout << d << endl;
//
//    d = arr.RecursiveBinarySearch(0, 9, 15);
//    cout << d << endl;
//
//    d = arr.Get(4);
//    cout << d << endl;
//
//    arr.Set(4, -1000);
//    arr.display();
//
//    d = arr.Max();
//    cout << d << endl;
//
//    d = arr.Min();
//    cout << d << endl;
//
//    d = arr.Sum();
//    cout << d << endl;
//
//    double a;
//    a = arr.Avg();
//    cout << a << endl;
//
//    cout << endl;
//    arr.display();
//    arr.AuxiliaryReverse();
//    arr.display();
//
//    cout << endl;
//    arr.Reverse();
//    arr.display();
//
//    cout << endl;
//    arr.LeftRotate();
//    arr.display();
//
//    Array B(10, 5, true);
//    cout << B.isSorted() << endl;
//
//    B.display();
//    B.insertInSorted(-1);
//    B.display();
//
//    Array C(10, 10);
//    C.display();
//    C.NegPosRearrange();
//    C.display();

//    Array D(10, 5, true);
//    Array E(10, 4, true);
//
//    Array F = D.Merge(E);
//    F.display();
//
//    Array G = D.Union(E);
//    G.display();
//
//    Array H = D.Intersection(E);
//    H.display();
//
//    Array I = D.Difference(E);
//    I.display();

    int ch;
    int size;
    int length;
    int x;
    int idx;
    cout << "Enter Size of Array: " << flush;
    cin >> size;
    cout << "Enter Length of Array: " << flush;
    cin >> length;

    Array array(size, length, false, true);

    do {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1.\t Insert" << endl;
        cout << "2.\t Delete" << endl;
        cout << "3.\t Search" << endl;
        cout << "4.\t Sum" << endl;
        cout << "5.\t Display" << endl;
        cout << "6.\t Exit" << endl;

        cout << "\nEnter your choice: " << flush;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter an element and index: " << flush;
                cin >> x;
                cin >> idx;
                array.Insert(x, idx);
                break;
            case 2:
                cout << "\nEnter index for deleting element: " << flush;
                cin >> idx;
                x = array.Delete(idx);
                cout << "\nDeleted element is: " << x << endl;
                break;
            case 3:
                cout << "\nEnter element to search: " << flush;
                cin >> x;
                idx = array.LinearSearch(x);
                cout << "\nElement index is: " << idx << endl;
                break;
            case 4:
                cout << "\nSum of elements is: " << array.Sum() << endl;
                break;
            case 5:
                array.display();
        }
    } while (ch < 6);


    return 0;
}