#include "iostream" //cout,cin ,printf
#include "cmath" // abs
#include "string"

int main() {

    // 1. data reading.
    std::string name;
    std::string surname;

    int age;
    double points;

    std::cout << "Enter data ... \n";
    std::cin >> name >> surname >> age >> points;

    double result = std::abs(age - points);

    //"'Krmakov Edik' has a 74% chance of getting 100 points"

    //2. output data.

    std::printf("%s %s has a %.0f%% chance of getting %.0f points.", surname.data(), name.data(), result, points);
    return 0;
}
