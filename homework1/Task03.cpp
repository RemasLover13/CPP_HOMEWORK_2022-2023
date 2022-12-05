#include <iostream> // cout, cin

using namespace std;


void exchangeValues(int *, int *);

int main() {

    int number1, number2;
    int *ptr1 = &number1;
    int *ptr2 = &number2;
    cout << "Enter 2 numbers : ";
    cin >> number1 >> number2;

    cout << "Value a: " << number1 << "\t Value b: " << number2 << endl;
    cout << "Address a: " << &number1 << "\t Address b: " << &number2 << endl;
    cout << "================================================" << endl;


    cout << "Passing pointers: " << endl;
    exchangeValues(ptr1, ptr2);
    cout << "Passing references: " << endl;
    exchangeValues(&number1, &number2);


    return 0;
}


void exchangeValues(int *a, int *b) {
    cout << "Before changing: " << endl;
    cout << "Value a: " << *a << "\t Value b: " << *b << endl;
    cout << "Address a: " << &a << "\t Address b: " << &b << endl;
    int *ptr = nullptr;
    ptr = a;
    a = b;
    b = ptr;
    cout << "After changing: " << endl;
    cout << "Value a: " << *a << "\t Value b: " << *b << endl;
    cout << "Address a: " << a << "\t Address b: " << b << endl;
    cout << "================================================" << endl;
}