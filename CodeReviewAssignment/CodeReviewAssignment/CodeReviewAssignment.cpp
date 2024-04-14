#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

// Abstract base class for shapes
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void display() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class for rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
    void display() const override {
        std::cout << "Rectangle with length " << length << " and width " << width << std::endl;
    }
};

// Derived class for circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    void display() const override {
        std::cout << "Circle with radius " << radius << std::endl;
    }
};

int main() {
    // Array of Shape pointers
    Shape* shapes[2];

    // Creating objects of derived classes and storing their addresses in Shape pointers
    shapes[0] = new Rectangle(5, 4);
    shapes[1] = new Circle(3);

    // Polymorphic behavior: calling area() and display() through Shape pointers
    for (int i = 0; i < 2; ++i) {
        shapes[i]->display();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
    }

    // Deleting objects
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}
