#include "iostream"
#include "cstring"

using namespace std;

class SuperString {
    char *str;
    int size;

public:
    SuperString() {
        str = new char[0];
        size = 0;
    }

    SuperString(int size) {
        this->str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            this->str[i] = rand() % 127;
        }
    }

    SuperString(char *str, const int size) {
        this->str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            this->str[i] = str[i];
        }
        this->str[size] = '\0';
    }


    SuperString(char *str) {
        int length = strlen(str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }

    // Copy Constructor
    SuperString(const SuperString &other) {
        int length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }

    ~SuperString() {
        delete[] this->str;
    }

    // copying string with =
    SuperString &operator=(const SuperString &other) {
        if (this->str != nullptr) {
            delete[] str;
        }
        int length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';

        return *this;
    }

    // concat with another string
    SuperString operator+(const SuperString &other) {
        SuperString newStr;

        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);

        newStr.str = new char[thisLength + otherLength + 1];
        int i = 0;
        for (; i < thisLength; ++i) {
            newStr.str[i] = this->str[i];
        }
        for (int j = 0; j < otherLength; j++, i++) {
            newStr.str[i] = other.str[j];
        }
        newStr.str[thisLength + otherLength] = '\0';

        return newStr;
    }
    bool operator ==(SuperString &other) {
        int cur_length = strlen(str);
        int other_length = strlen(other.str);
        if (cur_length != other_length) {
            return false;
        } else {
            for (int i = 0; i < cur_length; i++) {
                if (str[i] != other.str[i]){
                    return false;
                }
            }
        }
        return true;
    }


    bool operator !=(SuperString &other) {
        return !(operator==(other));
    }
    // Hello World
    bool operator <(SuperString &other) {
        int cur_length = strlen(str);
        int other_length = strlen(other.str);
        int min = 0;
        if (cur_length < other_length) {
            min = cur_length;
        } else {
            min = other_length;
        }
        for (int i = 0; i < cur_length; i++) {
            if (cur_length == other_length) {
                if (str[i] < other.str[i]  && cur_length == other_length) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (cur_length < other_length && str[cur_length-1] < other.str[other_length - 1]) {
                    return true;
                } else {
                    return false;
                }
            }

            }
        }

    bool operator >(SuperString &other) {
        return !(operator<(other));
    }

    bool operator <=(SuperString &other) {

        return (operator<(other) || operator==(other));
    }

    bool operator >=(SuperString &other) {
        return (operator==(other) || operator>(other));
    }

    char operator[](int index) {

        int length = strlen(str);
        for (int i = 0; i < length; i++) {
            if (index == i) {
                return str[i];
            }
        }
        cout << "Invalid index" << endl;
    }

    int sizeOf() {
        int count = 0;
        while(str[count] != '\0') {
            count++;
        }
        return count;
    }

    void toUppercase() {

        for (int i = 0; i < strlen(str); i++) {
            if (int(str[i] >= 65 && (int) str[i] <= 92)) {
                continue;

            } else {
                int symbol = str[i] - 32;
                str[i] = char(symbol);
            }
        }
    }

    void toLowercase() {

        for (int i = 0; i < strlen(str); i++) {
            if (int(str[i] >= 92 && (int) str[i] <= 122)) {
                continue;
            } else {
                int symbol = str[i] + 32;
                str[i] = char(symbol);
            }
        }
    }


    void Print() {
        cout << str;
    }
};


int main() {
    char* s = "string";
    char* s2 = "hello";
    SuperString string1(s, 6);
    SuperString string2(s2, 5);
    string1.Print();
    cout << endl;
    string2.Print();

    SuperString string3 = string1 + string2;
    // Concat '+' string1 and string2
//    cout << isEqual << endl;
//    string1.Print();
//    cout << endl;
//    string2.Print();
//    cout << endl;
//    string3.Print();
//    cout << endl;
    // Copying from string1 to string2;
//    string2 = string1;
//    string1.Print();
//    cout << endl;
//    string2.Print();
//    cout << endl;
    // Uppercase and LowerCase
//    string1.toLowercase();
//    string2.toUppercase();
//    string1.Print();
//    cout << endl;
//    string2.Print();
//    cout << endl;



    return 0;
}