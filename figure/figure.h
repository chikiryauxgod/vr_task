#ifndef FIGURE_H
#define FIGURE_H

#include <memory>

using upf = std::unique_ptr<class Figure>;

class Figure 
{
public:
    virtual double Square() const = 0;
    virtual ~Figure() = default;

    bool operator<(const Figure& other) const {
        return this->Square() < other.Square();
    }
};

class Circle final : public Figure
 {
public:
    explicit Circle(double r);
    double Square() const override;

private:
    double radius_ = 0;
};

class Triangle final : public Figure 
{
public:
    explicit Triangle(double a, double b);
    double Square() const override;

private:
    double base_ = 0;
    double height_ = 0;
};

class Rectangle final : public Figure 
{
public:
    explicit Rectangle(double w, double h);
    double Square() const override;

private:
    double width_ = 0;
    double height_ = 0;
};

class AbstractFigureFactory 
{
public:
    virtual upf CreateCircle(double radius) const = 0;
    virtual upf CreateTriangle(double base, double height) const = 0;
    virtual upf CreateRectangle(double width, double height) const = 0;
    virtual ~AbstractFigureFactory() = default;
};

class FigureFactory final : public AbstractFigureFactory 
{
public:
    upf CreateCircle(double radius) const override;
    upf CreateTriangle(double base, double height) const override;
    upf CreateRectangle(double width, double height) const override;
};

#endif 
