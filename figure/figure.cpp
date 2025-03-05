#include "figure.h"

Circle::Circle(double r) : radius_{r} {}

double Circle::Square() const {
    return 3.14 * radius_ * radius_;
}

Triangle::Triangle(double a, double b) : base_(a), height_(b) {}

double Triangle::Square() const {
    return (base_ * height_) / 2;
}

Rectangle::Rectangle(double w, double h) : width_{w}, height_{h} {}

double Rectangle::Square() const {
    return width_ * height_;
}

upf FigureFactory::CreateCircle(double radius) const {
    return std::make_unique<Circle>(radius);
}

upf FigureFactory::CreateTriangle(double base, double height) const {
    return std::make_unique<Triangle>(base, height);
}

upf FigureFactory::CreateRectangle(double width, double height) const {
    return std::make_unique<Rectangle>(width, height);
}
