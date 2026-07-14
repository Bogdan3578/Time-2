#include "shape.h"

Triangle::Triangle(double a_, double b_, double c_, double A_, double B_, double C_)
    : a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {

    if (a <= 0 || b <= 0 || c <= 0) {
        throw GeometryException("Ошибка создания фигуры. Причина: длины сторон должны быть положительными.");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw GeometryException("Ошибка создания фигуры. Причина: нарушено неравенство треугольника.");
    }

    double sumAngles = A + B + C;
    if (!feq(sumAngles, 180.0)) {
        throw GeometryException("Ошибка создания фигуры. Причина: сумма углов не равна 180.");
    }
}

void Triangle::print() const {
    std::cout << "Треугольник (стороны " << a << ", " << b << ", " << c
        << "; углы " << A << ", " << B << ", " << C << ") создан\n";
}

RightTriangle::RightTriangle(double a, double b, double c, double A, double B, double C)
    : Triangle(a, b, c, A, B, C) {

    bool hasRightAngle = feq(A, 90.0) || feq(B, 90.0) || feq(C, 90.0);
    if (!hasRightAngle) {
        throw GeometryException("Ошибка создания фигуры. Причина: в прямоугольном треугольнике один из углов должен быть равен 90.");
    }
}

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double c, double A, double B, double C)
    : Triangle(a, b, c, A, B, C) {

    bool sidesOk = feq(a, c);
    bool anglesOk = feq(A, C);
    if (!sidesOk || !anglesOk) {
        throw GeometryException("Ошибка создания фигуры. Причина: у равнобедренного треугольника должны быть равны боковые стороны и соответствующие углы.");
    }
}

EquilateralTriangle::EquilateralTriangle(double side)
    : Triangle(side, side, side, 60.0, 60.0, 60.0) {
    if (side <= 0) {
        throw GeometryException("Ошибка создания фигуры. Причина: длина стороны должна быть положительной.");
    }
}

Quadrilateral::Quadrilateral(const std::vector<double>& sides_, const std::vector<double>& angles_)
    : sides(sides_), angles(angles_) {

    if (sides.size() != 4 || angles.size() != 4) {
        throw GeometryException("Ошибка создания фигуры. Причина: четырёхугольник должен иметь 4 стороны и 4 угла.");
    }

    for (double s : sides) {
        if (s <= 0) {
            throw GeometryException("Ошибка создания фигуры. Причина: длины сторон должны быть положительными.");
        }
    }

    // Сумма углов без std::accumulate
    double sumAngles = 0.0;
    for (size_t i = 0; i < angles.size(); ++i) {
        sumAngles += angles[i];
    }

    if (!feq(sumAngles, 360.0)) {
        throw GeometryException("Ошибка создания фигуры. Причина: сумма углов четырёхугольника не равна 360.");
    }
}

void Quadrilateral::print() const {
    std::cout << "Четырёхугольник (стороны ";
    for (size_t i = 0; i < sides.size(); ++i) {
        std::cout << sides[i];
        if (i + 1 < sides.size()) std::cout << ", ";
    }
    std::cout << "; углы ";
    for (size_t i = 0; i < angles.size(); ++i) {
        std::cout << angles[i];
        if (i + 1 < angles.size()) std::cout << ", ";
    }
    std::cout << ") создан\n";
}

Rectangle::Rectangle(double a, double b)
    : Quadrilateral({ a, b, a, b }, { 90.0, 90.0, 90.0, 90.0 }) {
    if (a <= 0 || b <= 0) {
        throw GeometryException("Ошибка создания фигуры. Причина: стороны прямоугольника должны быть положительными.");
    }
}

Square::Square(double side)
    : Rectangle(side, side) {
    if (side <= 0) {
        throw GeometryException("Ошибка создания фигуры. Причина: сторона квадрата должна быть положительной.");
    }
}

Parallelogram::Parallelogram(double a, double b, double A)
    : Quadrilateral({ a, b, a, b }, { A, 180.0 - A, A, 180.0 - A }) {
    if (a <= 0 || b <= 0) {
        throw GeometryException("Ошибка создания фигуры. Причина: стороны параллелограмма должны быть положительными.");
    }
    if (A <= 0 || A >= 180) {
        throw GeometryException("Ошибка создания фигуры. Причина: угол параллелограмма должен быть строго между 0 и 180.");
    }
}

Rhombus::Rhombus(double side, double A)
    : Parallelogram(side, side, A) {
    if (side <= 0) {
        throw GeometryException("Ошибка создания фигуры. Причина: сторона ромба должна быть положительной.");
    }
}
