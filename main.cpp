#include "includes/factorial.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Shape
{
    virtual ~Shape(){};
    virtual void Area() const = 0;
    virtual void Perimeter() const = 0;
};

struct Square : public Shape
{
    // virtual ~Square() = default;
    void Area() const override
    {
        int i;
        cout << "What is the length : ";
        cin >> i;
        cout << "Area : " << i * i;
    }
    void Perimeter() const override
    {
        int i;
        cout << "What is the length : ";
        cin >> i;
        cout << "Area : " << i * 4;
    }
};

struct Rectangle : public Shape
{
    // virtual ~Square() = default;
    void Area() const override
    {
        int a, b;
        cout << "What is the length : ";
        cin >> a;
        cout << "What is the height : ";
        cin >> b;
        cout << "Area : " << a * b;
    }
    void Perimeter() const override
    {
        int a, b, c;
        cout << "What is the side 1 : ";
        cin >> a;
        cout << "What is the side 2 : ";
        cin >> b;
        cout << "What is the base : ";
        cin >> c;
        cout << "Area : " << a + b + c;
    }
};

struct Triangle : public Shape
{
    // virtual ~Square() = default;
    void Area() const override
    {
        int a, b;
        cout << "What is the length : ";
        cin >> a;
        cout << "What is the height : ";
        cin >> b;
        cout << "Area : " << (a * b) / 2;
    }
    void Perimeter() const override
    {
        int a, b;
        cout << "What is the length : ";
        cin >> a;
        cout << "What is the height : ";
        cin >> b;
        cout << "Area : " << 2 * (a * b);
    }
};

template <class T>
Shape *create()
{
    return new T;
}

typedef Shape *(*CreateFN)();

void maker(map<string, CreateFN> &m, string shape, int type)
{

    Shape *creator = m[shape]();

    switch (type)
    {
    case 1:
        creator->Area();
        break;

    case 2:
        creator->Perimeter();
        break;

    default:
        break;
    }

    delete creator;
}

template <typename K, typename V>
void print_map(map<K, V> const &m)
{
    for (auto const &pair : m)
    {
        cout << "- " << pair.first << endl;
    }
    cout << "- exit" << endl;
}

int main()
{
    int fac = 10;

    cout << "Factorial of " << fac << endl;
    cout << "Normal : " << Factorial_Recursive(fac) << endl;
    cout << "Recursive : " << Factorial_Biasa(fac) << endl;
    cout << endl;

    string shape_choice;
    int type_choice;

    map<string, CreateFN> m;

    m["square"] = &create<Square>;
    m["triangle"] = &create<Triangle>;
    m["rectangle"] = &create<Rectangle>;

    while (m.find(shape_choice) == m.end())
    {
        print_map(m);

        cout << "Select the shape : ";
        cin >> shape_choice;

        if (shape_choice == "exit")
            break;
    }

    if (shape_choice == "exit")
        return 0;

    cout << "" << endl;

    cout << "1) area " << endl;
    cout << "2) perimeter " << endl;

    cout << "Select the method : ";
    cin >> type_choice;

    cout << "" << endl;

    maker(m, shape_choice, type_choice);

    return 0;
}
