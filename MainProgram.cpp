// ============================================================
// Lab: Strings and String Operations with Function & Operator
//       Overloading in C++
// Course: Object-Oriented Programming for Engineers
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

class MyString {
private:
    string data;

public:
    MyString();
    MyString(const string& str);
    MyString(const char* str);

    string getData() const;

    int length() const;
    char charAt(int index) const;
    MyString substring(int start, int len) const;

    MyString toUpperCase() const;
    MyString toLowerCase() const;
    MyString trim() const;
    MyString reverse() const;

    int find(const MyString& target) const;
    int count(char ch) const;

    MyString append(const MyString& other) const;
    MyString append(const char* cstr) const;
    MyString append(char ch) const;
    MyString append(int number) const;

    MyString replace(char oldCh, char newCh) const;
    MyString replace(const string& oldStr, const string& newStr) const;

    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    char operator[](int index) const;
    MyString operator*(int times) const;

    friend ostream& operator<<(ostream& os, const MyString& s);
    friend istream& operator>>(istream& is, MyString& s);
};

// ================================
// FUNCTION IMPLEMENTATIONS
// ================================

// ---- Constructors ----

MyString::MyString() {
    data = "";
}

MyString::MyString(const string& str) {
    data = str;
}

MyString::MyString(const char* str) {
    data = string(str);
}

// ---- Getter ----

string MyString::getData() const {
    return data;
}

// ---- Basic String Operations ----

int MyString::length() const {
    return data.length();
}

char MyString::charAt(int index) const {
    if (index < 0 || index >= (int)data.length())
        throw out_of_range("charAt: index out of range");
    return data[index];
}

MyString MyString::substring(int start, int len) const {
    if (start < 0 || start >= (int)data.length())
        throw out_of_range("substring: start index out of range");
    return MyString(data.substr(start, len));
}

// ---- String Manipulation ----

MyString MyString::toUpperCase() const {
    string result = data;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return MyString(result);
}

MyString MyString::toLowerCase() const {
    string result = data;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return MyString(result);
}

MyString MyString::trim() const {
    const string whitespace = " \t\n\r";
    int start = data.find_first_not_of(whitespace);
    if (start == (int)string::npos)
        return MyString("");
    int end = data.find_last_not_of(whitespace);
    return MyString(data.substr(start, end - start + 1));
}

MyString MyString::reverse() const {
    string result = data;
    std::reverse(result.begin(), result.end());
    return MyString(result);
}

// ---- Search Operations ----

int MyString::find(const MyString& target) const {
    size_t pos = data.find(target.data);
    if (pos == string::npos)
        return -1;
    return (int)pos;
}

int MyString::count(char ch) const {
    int counter = 0;
    for (char c : data)
        if (c == ch) counter++;
    return counter;
}

// ---- Function Overloading: append ----

MyString MyString::append(const MyString& other) const {
    return MyString(data + other.data);
}

MyString MyString::append(const char* cstr) const {
    return MyString(data + string(cstr));
}

MyString MyString::append(char ch) const {
    return MyString(data + ch);
}

MyString MyString::append(int number) const {
    return MyString(data + to_string(number));
}

// ---- Function Overloading: replace ----

MyString MyString::replace(char oldCh, char newCh) const {
    string result = data;
    for (char& c : result)
        if (c == oldCh) c = newCh;
    return MyString(result);
}

MyString MyString::replace(const string& oldStr, const string& newStr) const {
    string result = data;
    size_t pos = 0;
    while ((pos = result.find(oldStr, pos)) != string::npos) {
        result.std::string::replace(pos, oldStr.length(), newStr);
        pos += newStr.length();  // advance past the replaced part
    }
    return MyString(result);
}

// ---- Operator Overloading ----

MyString MyString::operator+(const MyString& other) const {
    return MyString(data + other.data);
}

bool MyString::operator==(const MyString& other) const {
    return data == other.data;
}

bool MyString::operator!=(const MyString& other) const {
    return data != other.data;
}

bool MyString::operator<(const MyString& other) const {
    return data < other.data;
}

bool MyString::operator>(const MyString& other) const {
    return data > other.data;
}

char MyString::operator[](int index) const {
    if (index < 0 || index >= (int)data.length())
        throw out_of_range("operator[]: index out of range");
    return data[index];
}

MyString MyString::operator*(int times) const {
    if (times <= 0) return MyString("");
    string result = "";
    for (int i = 0; i < times; i++)
        result += data;
    return MyString(result);
}

// ---- Stream Overloading ----

ostream& operator<<(ostream& os, const MyString& s) {
    os << s.data;
    return os;
}

istream& operator>>(istream& is, MyString& s) {
    string temp;
    is >> temp;
    s.data = temp;
    return is;
}

// ================================
// MAIN FUNCTION
// ================================

int main() {
    cout << "=== MyString Lab Demo ===" << endl;

    MyString s1("Hello World");
    MyString s2("hello world");
    MyString s3;
    MyString s4(string("C++ Programming"));

    cout << "\n--- Basic Operations ---" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s4: " << s4 << endl;
    cout << "Length of s1: " << s1.length() << endl;
    cout << "charAt(0) of s1: " << s1.charAt(0) << endl;
    cout << "charAt(6) of s1: " << s1.charAt(6) << endl;
    cout << "substring(0,5) of s1: " << s1.substring(0, 5) << endl;
    cout << "substring(6,5) of s1: " << s1.substring(6, 5) << endl;

    cout << "\n--- String Manipulation ---" << endl;
    cout << "toUpperCase of s1: " << s1.toUpperCase() << endl;
    cout << "toLowerCase of s1: " << s1.toLowerCase() << endl;

    MyString padded("   spaces around   ");
    cout << "Before trim: [" << padded << "]" << endl;
    cout << "After  trim: [" << padded.trim() << "]" << endl;
    cout << "Reverse of s1: " << s1.reverse() << endl;

    cout << "\n--- Search Operations ---" << endl;
    cout << "find 'World' in s1: " << s1.find(MyString("World")) << endl;
    cout << "find 'xyz' in s1:   " << s1.find(MyString("xyz")) << endl;
    cout << "count 'l' in s1:    " << s1.count('l') << endl;
    cout << "count 'z' in s1:    " << s1.count('z') << endl;

    cout << "\n--- Function Overloading: append ---" << endl;
    MyString base("Data");
    cout << "append(MyString): " << base.append(MyString("Base")) << endl;
    cout << "append(C-str):    " << base.append("_v2") << endl;
    cout << "append(char):     " << base.append('!') << endl;
    cout << "append(int):      " << base.append(42) << endl;

    cout << "\n--- Function Overloading: replace ---" << endl;
    MyString rep("aabcaabc");
    cout << "Original:                " << rep << endl;
    cout << "replace('a','x'):        " << rep.replace('a', 'x') << endl;
    cout << "replace(\"abc\",\"XYZ\"): " << rep.replace(string("abc"), string("XYZ")) << endl;

    cout << "\n--- Operator Overloading ---" << endl;
    MyString a("Hello");
    MyString b(" World");
    MyString c("Hello");

    cout << "a + b:  " << a + b << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    MyString apple("Apple");
    MyString banana("Banana");
    cout << "Apple < Banana: " << (apple < banana) << endl;
    cout << "Banana > Apple: " << (banana > apple) << endl;

    cout << "a[0]: " << a[0] << endl;
    cout << "a[4]: " << a[4] << endl;

    cout << "a * 3: " << a * 3 << endl;
    cout << "a * 0: [" << a * 0 << "]" << endl;

    cout << "\n--- Stream Operators ---" << endl;
    MyString x("Stream");
    MyString y("Test");
    cout << "Chained output: " << x << " " << y << endl;

    cout << "\nAll demos complete!" << endl;
    return 0;
}
