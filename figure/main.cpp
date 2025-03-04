#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>


using upf = std::unique_ptr<class Figure>;

class Figure {

public:

    virtual double Square() const = 0;
    virtual ~Figure() = default;

    bool operator<(const Figure& other) const {
        return this->Square() < other.Square();
    }
};

class Circle final : public Figure {

public:

    explicit Circle(double r) : radius_{r} {}

    double Square() const override {
        return 3.14 * radius_ * radius_;
    }

private:

    double radius_ = 0;
};

class Triangle final : public Figure {

public:

    explicit Triangle(double a, double b) : base_(a), height_(b) {}

    double Square() const override {
		return ((base_ * height_) / 2);
    }

private:
	double base_ = 0;
	double height_ = 0;
};

class Rectangle final : public Figure {

public:

   	explicit Rectangle(double w, double h) : width_{w}, height_{h} {}

    double Square() const override {
        return width_ * height_;
    }

private:

    double width_ = 0;
    double height_ = 0;
};

class AbstractFigureFactory {

public:

    virtual upf CreateCircle(double radius) const = 0;
    virtual upf CreateTriangle(double base, double height) const = 0;
    virtual upf CreateRectangle(double width, double height) const = 0;
    virtual ~AbstractFigureFactory() = default;
};

class FigureFactory final : public AbstractFigureFactory {

public:

    upf CreateCircle(double radius) const override {
        return std::make_unique<Circle>(radius);
    }

    upf CreateTriangle(double base, double height) const override {
        return std::make_unique<Triangle>(base, height);
    }

    upf CreateRectangle(double width, double height) const override {
        return std::make_unique<Rectangle>(width, height);
    }
};

int main() {

    std::vector<upf> figures;
    FigureFactory factory;

    figures.push_back(factory.CreateCircle(5.0));
    figures.push_back(factory.CreateTriangle(12.0, 8.0));
    figures.push_back(factory.CreateRectangle(6.0, 8.0));

    std::sort(figures.begin(), figures.end(), [](const upf& a, const upf& b) {
        return *a < *b;
    });

    for (const auto& figure : figures) {
        std::cout << "Square: " << figure->Square() << std::endl;
    }

    return 0;
}
