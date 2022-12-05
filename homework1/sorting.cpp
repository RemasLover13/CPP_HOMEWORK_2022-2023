#include "iostream"

using namespace std;

class BubbleSortStrategy;

class Insertion;

class SelectionSortStrategy;

class BogoSortStrategy;

class SortStrategy {
public:
    virtual void sort(int *arr, int size) = 0;

    virtual ~SortStrategy() = default;
};


class BubbleSortStrategy : public SortStrategy {
    void sort(int *arr, int size) override {
        cout << "Bubble sorting" << endl;
        int temp = 0;
       for (int i = 0; i < size; i++) {
           for (int j = (size - 1); j > (i + 1); j--) {
               if (arr[j] < arr[j - 1]) {
                   temp = arr[j];
                   arr[j] = arr[j - 1];
                   arr[j - 1] = temp;
               }
           }
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};


class Insertion : public SortStrategy {

    void sort(int *arr, int size) override {
        cout << "Insertion sorting" << endl;
        int key = 0;
        int i = 0;
        for (int j = 1; j < size; j++) {
            key = arr[j];
            i = j - 1;
            while(i>=0 && arr[i] > key) {
                arr[i + 1] = arr[i];
                i = i - 1;
                arr[i + 1] = key;
            }

        }

        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

    }
};

class SelectionSortStrategy : public SortStrategy {
    void sort(int *arr, int size) override {
        cout << "Selection Sorting" << endl;
        int j = 0;
        int temp = 0;
        for (int i = 0; i < size; i++) {
            j = i;
            for (int k = i; k < size; k++) {
                if (arr[j] > arr[k]) {
                    j = k;
                }
            }

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class BogoSortStrategy : public SortStrategy {
    void sort(int *arr, int size) override {
        cout << "Bogo Sorting" << endl;
        int randomPos = 0;
        int temp = 0;

        do {

            for (int i = 0; i < size; i++) {
                randomPos = rand() % (size - 1) + 0;
                temp = arr[i];
                arr[i] = arr[randomPos];
                arr[randomPos] = temp;

            }
        } while (!isSorted(arr, size));

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
  }

    static bool isSorted(const int *arr, int size) {
        for (int i = 1; i < size; i++ ) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};



class Sort {
private:
    SortStrategy *sort_strategy;
public:

    Sort() {
        sort_strategy = nullptr;
    }

    ~Sort() {
        delete sort_strategy;
    }

    void SetSortStrategy(SortStrategy *sortStrategy) {
        this->sort_strategy = sortStrategy;

    }

    void execSort(int *arr, int size) {
        this->sort_strategy->sort(arr, size);
    }
};


int main() {
    const int size = 10;
    int *arr = new int[size]{1, 3, 5, 2, 6, 7, 2, 10, 50, 2};
    Sort *sort = new Sort();
    sort->SetSortStrategy(new BogoSortStrategy());
    sort->execSort(arr, size);
    sort->SetSortStrategy(new Insertion());
    sort->execSort(arr, size);
    sort->SetSortStrategy(new SelectionSortStrategy());
    sort->execSort(arr, size);
    sort->SetSortStrategy(new BubbleSortStrategy());
    sort->execSort(arr, size);


    return 0;
}
