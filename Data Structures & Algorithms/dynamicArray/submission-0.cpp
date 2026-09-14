class DynamicArray {
public:

    DynamicArray(int capacity) : capacity(capacity), len(0){
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (len == capacity)
            resize();
        
        arr[len++] = n;
    }

    int popback() {
        return arr[--len];
    }

    void resize() {
        capacity *= 2;

        int* newArr = new int[capacity];

        for (int i = 0; i < len; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;

        arr = newArr;
    }

    int getSize() {
        return len;
    }

    int getCapacity() {
        return capacity;
    }

    int* arr = NULL;
    int capacity;
    int len;
};
