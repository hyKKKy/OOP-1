#define _CRT_SECURE_NO_WARNINGS
#include "PointH.h"
#include <iostream>


Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int X, int Y) {
    x = X;
    y = Y;
}

int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}

void Point::print() const {
    std::cout << "X: " << x << "\t" << "Y: " << y << std::endl;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

Point Point::operator*(const Point& other) const {
    return Point(x * other.x, y * other.y);
}

Point Point::operator/(const Point& other) const {
    if (other.x == 0 || other.y == 0) {
        std::cout << "Error!";
    }
    return Point(x / other.x, y / other.y);
}

Fraction::Fraction() {
		numerator = 0;
		denominator = 1;
}

Fraction::Fraction(double n, double d) {
		numerator = n;
		if (d == 0) {
			std::cout << "error!" << std::endl;
			return;
		}
		else
		{
			denominator = d;
		}
}

Fraction Fraction::operator*(const Fraction& obj) {
		double tmp_numerator = obj.numerator * numerator;
		double tmp_denominator = obj.denominator * denominator;

		Fraction result(tmp_numerator, tmp_denominator);

		return result;
}

Fraction Fraction::operator/(const Fraction& obj) {
		double tmp_numerator = numerator * obj.denominator;
		double tmp_denominator = denominator * obj.numerator;

		Fraction result(tmp_numerator, tmp_denominator);

		return result;
}

Fraction Fraction::operator+(const Fraction& obj) {
		double common_denominator = obj.denominator * denominator;
		double new_numerator1 = numerator * obj.denominator;
		double new_numerator2 = obj.numerator * denominator;

		double tmp_numerator = new_numerator1 + new_numerator2;
		double tmp_denominator = common_denominator;

		Fraction result(tmp_numerator, tmp_denominator);

		return result;
}

Fraction Fraction::operator-(const Fraction& obj) {
		double common_denominator = obj.denominator * denominator;
		double new_numerator1 = numerator * obj.denominator;
		double new_numerator2 = obj.numerator * denominator; \

			double tmp_numerator = new_numerator1 - new_numerator2;
		double tmp_denominator = common_denominator;

		Fraction result(tmp_numerator, tmp_denominator);

		return result;
}

void Fraction::PrintResult() const{
		std::cout << "Result is: " << numerator << "/" << denominator << " or " << numerator / denominator << std::endl;
}

  
Array::Array(){
    this->arr = nullptr;
    this->size = 0;
}

Array::~Array() {
        delete[] arr;
}

Array::Array(const Array& obj) {
        size = obj.size;

        delete[] arr;

        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }
}

Array& Array::operator=(const Array& obj) {
        size = obj.size;

        delete[] arr;

        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }

        return *this;
}

int Array::operator[](int index) {
    if (index < 0 || index >= this->size) {
        std::cout << "error!" << std::endl;
    }
    return arr[index];

}

Array Array::operator+(const Array& obj) {
    Array sum_arr;
    sum_arr.size = this->size + obj.size;

    sum_arr.arr = new int[sum_arr.size];

    for (int i = 0; i < size; i++)
    {
        sum_arr.arr[i] = arr[i];
    }
    for (int i = 0; i < sum_arr.size; i++)
    {
        sum_arr.arr[size + i] = obj.arr[i];
    }

    return sum_arr;

}

   
void Array::Init(int SIZE, int min, int max) {
        size = SIZE;
        delete[] arr;  
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % (max - min) + min;
        }
}

void Array::Init_v2(int min, int max) {
    for (int i = 0; i < this->size; i++) {
        this->arr[i] = rand() % (max - min) + min;
    }
}

void Array::PrintArray() const {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
}

String::String() {
        user_str = new char[1];
        user_str[0] = '\0';
}

String::String(char* str) {
        length = strlen(str) + 1;
        user_str = new char[length];
        strcpy(user_str, str);
}

String::String(const String& str) {
        int length = strlen(str.user_str) + 1;
        user_str = new char[length];
        strcpy(user_str, str.user_str);
}

String& String::operator=(const String& obj) {
    length = strlen(obj.user_str) + 1;
    delete[] user_str;
    user_str = new char[length];
    strcpy(user_str, obj.user_str);

    return *this;
}

String String::operator+(const String& other) {
    String product;
    product.length = this->length + other.length;
    product.user_str = new char[product.length + 1];
    strcpy(product.user_str, this->user_str);
    strcat(product.user_str, " ");
    strcat(product.user_str, other.user_str);

    return product;
}

bool String::CheckStr(const String& obj) {
        return strcmp(user_str, obj.user_str) == 0;
    }

int String::ReturnLenght() {
        length = strlen(user_str);
        return length;
}

String::~String() {
        delete[] user_str;
}

void String::Print() {
        std::cout << user_str << std::endl;
}



      
