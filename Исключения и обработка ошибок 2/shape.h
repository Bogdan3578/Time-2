#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "geometry_exception.h"
inline bool feq(double a, double b, double eps = 1e-6) {
    return std::fabs(a - b) < eps;
}
class Shape {
public:
    virtual ~Shape() = default;
    virtual void print() const = 0;
};

class Triangle : public Shape {
private:
    double a, b, c;      
    double A, B, C;      
public:
    Triangle(double a_, double b_, double c_, double A_, double B_, double C_);
    void print() const override;
};
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B, double C);
};
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C);
};
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side);
};

class Quadrilateral : public Shape {
private:
    std::vector<double> sides;      
    std::vector<double> angles;     
public:
    Quadrilateral(const std::vector<double>& sides_, const std::vector<double>& angles_);
    void print() const override;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b);  
};
class Square : public Rectangle {
public:
    explicit Square(double side);
};
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A); 
};
class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double A);
};
