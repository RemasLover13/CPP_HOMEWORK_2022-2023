#include <iostream>


using namespace std;

int factRecursion(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return n * factRecursion(n - 1);
}

int factLoop(int n) {
    int factorial = 1;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}



int main() {

    cout << factRecursion(6) << " - factorial with recursion. " << endl;
    cout << factLoop(6) << " - factorial with loop. " << endl;

    return 0;
}
