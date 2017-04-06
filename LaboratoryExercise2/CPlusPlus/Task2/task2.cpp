#include <iostream>
#include <list>

struct Point {
    int x; int y;
};

class Shape {
public:
    virtual void draw() = 0;
    virtual void move(double x, double y) = 0;
};

class Circle : public Shape {
private:
    double radius_;
    Point center_;
public:
    Circle() {}
    Circle(double radius_, Point center_) : radius_(radius_), center_(center_) {}
    virtual void draw() { std::cout << "Drawing circle!\n"; }
    virtual void move(double x, double y) { std::cout << "Moving circle!\n"; }
};

class Square : public Shape{
private:
    double side_;
    Point center_;
public:
    Square() {}
    Square(double side_, Point center_) : side_(side_), center_(center_) {}
    virtual void draw() { std::cout << "Drawing square!\n"; }
    virtual void move(double x, double y) { std::cout << "Moving square!\n"; }
};

class Rhomb : public Shape{
private:
    double side_;
    Point center_;
public:
    Rhomb() {}
    Rhomb(double side_, Point center_) : side_(side_), center_(center_) {}
    virtual void draw() { std::cout << "Drawing square!\n"; }
    virtual void move(double x, double y) { std::cout << "Moving rhomb!\n"; }
};

void drawShapes(const std::list <Shape*>& fig) {
    std::list <Shape *>:: const_iterator  it;
    for (it=fig.begin (); it!=fig.end (); ++it) {
        (*it)->draw();
    }
}

void moveShapes(const std::list <Shape*>& fig, double x, double y) {
    std::list <Shape *>:: const_iterator  it;
    for (it=fig.begin (); it!=fig.end (); ++it) {
        (*it)->move(x, y);
    }
}

int task2Main() {
    std::list<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Square());
    shapes.push_back(new Square());
    shapes.push_back(new Circle());
    shapes.push_back(new Rhomb());

    drawShapes(shapes);
    moveShapes(shapes, 100, 200);
    return 0;
}
