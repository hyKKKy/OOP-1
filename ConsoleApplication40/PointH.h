#pragma once
class Point {
private:
    int x;
    int y;

public:
    Point();

    Point(int X, int Y);

    int GetX() const;

    int GetY() const;

    void print() const;

    Point operator+(const Point& other) const;

    Point operator-(const Point& other) const;

    Point operator*(const Point& other) const;

    Point operator/(const Point& other) const;
};

class Fraction{
private:
	double numerator;
	double denominator;
public:
    Fraction();

    Fraction(double n, double d);


    Fraction operator+(const Fraction& obj);

    Fraction operator-(const Fraction& obj);

    Fraction operator*(const Fraction& obj);

    Fraction operator/(const Fraction& obj);
        
    void PrintResult() const;
};

class Array {
private:
    int* arr;
    int size;

public:
    Array();

    ~Array();

    Array(const Array& obj);
    Array& operator=(const Array& obj);

    Array operator+(const Array& obj);

    int operator[](int index);
    
    void Init(int SIZE, int min, int max);

    void Init_v2(int min, int max);

    void PrintArray() const;
};

class String
{
private:
    char* user_str;
    int length;
public:
    String();

    String(char* str);

    String(const String& str);

    String operator+(const String& other);

    String& operator=(const String& other);

    bool CheckStr(const String& obj);

    int ReturnLenght();

    ~String();

    void Print();
};

