#include <iostream>
#include <cmath>

#define PI 3.1415926
using namespace std;

// NNomal menber function Ver.
class ShapeNormal {
public:
    void getArea() const {
        cout << "Normal Shape area: 0" << endl;
    }
};

class RectangleNormal : public ShapeNormal {
private:
    double length;
    double width;

public:
    RectangleNormal(double l, double w) : length(l), width(w) {}

    void getArea() const {
        cout << "Normal Rectangle area: " << length * width << endl;
    }
};

class CircleNormal : public ShapeNormal {
private:
    double radius;

public:
    CircleNormal(double r) : radius(r) {}

    void getArea() const {
        cout << "Normal Circle area: " << PI * radius * radius << endl;
    }
};

// virtual memeber function Ver.
class ShapeVirtual {
public:
    virtual ~ShapeVirtual() {}

    virtual void getArea() const {
        cout << "Virtual Shape area: 0" << endl;
    }
};

class RectangleVirtual : public ShapeVirtual {
private:
    double length;
    double width;

public:
    RectangleVirtual(double l, double w) : length(l), width(w) {}

    void getArea() const {
        cout << "Virtual Rectangle area: " << length * width << endl;
    }
};

class CircleVirtual : public ShapeVirtual {
private:
    double radius;

public:
    CircleVirtual(double r) : radius(r) {}

    void getArea() const {
        cout << "Virtual Circle area: " << PI * radius * radius << endl;
    }
};

// pure virtual member function Ver.
class ShapeAbstract {
public:
    virtual ~ShapeAbstract() {}
    virtual void getArea() const = 0;
};

class RectangleAbstract : public ShapeAbstract {
private:
    double length;
    double width;

public:
    RectangleAbstract(double l, double w) : length(l), width(w) {}

    void getArea() const {
        cout << "Pure Virtual Rectangle area: " << length * width << endl;
    }
};

class CircleAbstract : public ShapeAbstract {
private:
    double radius;

public:
    CircleAbstract(double r) : radius(r) {}

    void getArea() const {
        cout << "Pure Virtual Circle area: " << PI * radius * radius << endl;
    }
};

int main() {
    cout << "Normal Member Function " << endl;
    ShapeNormal* p1;
    ShapeNormal s1;
    RectangleNormal r1(4, 5);
    CircleNormal c1(2);

    p1 = &s1;
    p1->getArea();
    p1 = &r1;
    p1->getArea();
    p1 = &c1;
    p1->getArea();

    cout << "Direct call from derived objects:" << endl;
    r1.getArea();
    c1.getArea();

    cout << "\nVirtual Member Function" << endl;
    ShapeVirtual* p2;
    ShapeVirtual s2;
    RectangleVirtual r2(4, 5);
    CircleVirtual c2(2);

    p2 = &s2;
    p2->getArea();
    p2 = &r2;
    p2->getArea();
    p2 = &c2;
    p2->getArea();

    cout << "\nPure Virtual Member Function" << endl;
    ShapeAbstract* p3;
    RectangleAbstract r3(4, 5);
    CircleAbstract c3(2);

    p3 = &r3;
    p3->getArea();
    p3 = &c3;
    p3->getArea();

    return 0;
}
