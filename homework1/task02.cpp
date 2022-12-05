#include "iostream" // cout, cin
#include "cmath" // sqrt

double averageWithoutStep(double *, int);

double averageWithStep(double *, int, int);

double calculateVariance(double *, int);


int main() {
    // посчитать дисперсию
    int size = 0;

    std::cout << "Enter the size of array: ";
    std::cin >> size;

    double *arr = new double[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter value of " << i << " : ";
        std::cin >> arr[i];
    }
    double simpleAverage = averageWithoutStep(arr, size);
    double withStepAverage = averageWithStep(arr,size,2);
    double variance = calculateVariance(arr, size);

    std::cout << "average without step: " << simpleAverage << std::endl;
    std::cout << "average with step: " << withStepAverage << std:: endl;
    std::cout << "Variance: " << variance;
    delete[] arr;
    return 0;
}

double averageWithoutStep(double *arr, int size) {
    double sum = 0;
    double average = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    average = sum / size;

    return average;
}

double averageWithStep(double *arr, int size, int step) {
    double sum = 0;
    double average = 0;

    for (int i = step; i < size; i+=step) {
        sum += arr[i];
    }
    average = sum / size;
    return average;
}

double calculateVariance(double *arr, int size) {
    double sum = 0;
    double average = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    average = sum / size;
    sum = 0;

    for (int i = 0; i < size; i++) {
       sum += pow(arr[i] - average, 2);
    }
    average = sum / size;
    return average;
}
