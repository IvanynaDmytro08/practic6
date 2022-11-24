#include <iostream>
#include <cassert>

class SomeString {

public:

    SomeString(std::string str = "") {

        if (str.empty()) {
            size = 0;
        }
        else {
            array = new char[str.size()];
            size = str.size();

            for (int i = 0; i < size; i++) {
                array[i] = str[i];
            }
        }
    }

    SomeString(const SomeString &obj) {

        if (obj.size > 0) {
            array = new char[obj.size];
            size = obj.size;

            for (int i = 0; i < obj.size; i++) {
                array[i] = obj.array[i];
            }
        }

    }

    int getSize() {
        return size;
    }


    ~SomeString() {
        std::cout << "This is Destructor" << std::endl;
        delete [] array;
    }

    SomeString& operator = (SomeString& obj1){

        if (obj1.size > 0) {
            array = new char[obj1.size];
            size = obj1.size;

            for (int i = 0; i < obj1.size; i++) {
                array[i] = obj1.array[i];
            }
        }
        return *this;

    }

    bool find(char &ele){

        for (int i = 0; i < size; i++) {
            if (ele == array[i])
                return true;
        }
        return false;
    }

    SomeString& operator += (SomeString& str) {

        char *ptr = nullptr;

        if (str.size > 0) {
            ptr = new char[size + str.size];

            for (int i = 0; i < size; i++) {
                ptr[i] = array[i];
            }

            for (int i = size, j = 0; i < (size + str.size); i++) {
                ptr[i] = str.array[j];
            }

            delete [] array;
        }

        if (ptr != nullptr) {
            array = ptr;
        }

        return *this;
    }

    char operator[](int index) {

        assert(index < size && index >= 0);
        return array[index];
    }

    friend std::ostream& operator << (std::ostream &out, const SomeString &o);
    friend bool operator == (SomeString& str, SomeString& str2);

private:

    char* array;
    int size;

};

bool operator == (SomeString& str, SomeString& str2) {

    if (str.size != str2.size )
        return false;

        for (int i = 0; i < str.size; i++) {

            if(str.array[i] != str2.array[i])
                 return false;
        }
    return true;
}


std::ostream& operator << (std::ostream &out, const SomeString &str){
    for (int i = 0; i < str.size; i++) {
        out << str.array[i];
    }
    return out;
}

int main() {

    SomeString str ("Hello, World");
    SomeString str2(str);
    SomeString str3;


    int size = str3.getSize();
    std::cout << size << std::endl;


    if (str.getSize() > 0)
        std::cout << " STR " << str << "  SIZE IS " << str.getSize() << std::endl;
    if (str2.getSize() > 0)
        std::cout << " STR2 " << str2 << "  SIZE IS " << str2.getSize() << std::endl;
    if (str3.getSize() > 0)
        std::cout << " STR3 " << str3 << "  SIZE IS " << str3.getSize() << std::endl;

    str3 = str2;
    if (str3.getSize() > 0)
        std::cout << " STR3 " << str3 << "  SIZE IS " << str3.getSize() << std::endl;


    char m_find;

    std::cout <<  "Input element which you want looking for - ";
    std::cin >> m_find;

    bool findRezult = str.find(m_find);

    if (findRezult) {
        std::cout << "Char " << m_find << " is find in your array " << std::endl;
    }
    else {
        std::cout << "Char " << m_find << " is not find in your array " << std::endl;
    }


    std::cout << "After joining 2 array - " << std::endl;
    str += str2;
    std::cout << str << std::endl;

    if (str == str2) {
        std::cout << "Arrays is equal " << std::endl;
    }
    else {
        std::cout << "Arrays is not equal " << std::endl;
    }

    int index;

    std::cout << "Input index element which you want return " << std::endl;
    std::cin >> index;

    std::cout << "Your return element - " << str[index] << std::endl;

    return 0;
}