#include <iostream>
#include <vector>

class Shape {
protected:
    std::string color;
public:
    Shape(std::string color) : color(color) {}

    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    int x, y, radius;
public:
    Circle(std::string color, int x, int y, int radius) : Shape(color), x(x), y(y), radius(radius) {}

    void draw() override {
        std::cout << "Drawing a " << color << " circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

class Rectangle : public Shape {
private:
    int x1, y1, x2, y2;
public:
    Rectangle(std::string color, int x1, int y1, int x2, int y2) : Shape(color), x1(x1), y1(y1), x2(x2), y2(y2) {}

    void draw() override {
        std::cout << "Drawing a " << color << " rectangle with top left corner at (" << x1 << ", " << y1 << ") and bottom right corner at (" << x2 << ", " << y2 << ")" << std::endl;
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle("red", 0, 0, 5));
    shapes.push_back(new Rectangle("blue", 2, 3, 6, 9));

    for (Shape* shape : shapes) {
        shape->draw();
    }

    // Clean up memory
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
