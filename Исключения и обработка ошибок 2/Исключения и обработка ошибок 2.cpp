#include <iostream>
#include "shape.h"
int main() {
    try {
        Triangle t(3, 4, 5, 30, 60, 90);
        t.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Triangle badT(3, 4, 5, 30, 60, 80);
        badT.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        RightTriangle rt(3, 4, 5, 30, 60, 90);
        rt.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        IsoscelesTriangle it(5, 6, 5, 70, 40, 70);
        it.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        EquilateralTriangle et(4);
        et.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Quadrilateral q({ 2, 3, 2, 3 }, { 90, 90, 90, 90 });
        q.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Rectangle r(4, 5);
        r.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Square s(3);
        s.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Parallelogram p(3, 4, 60);
        p.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Rhombus rh(3, 60);
        rh.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    try {
        Quadrilateral badQ({ 2, 3, 2, 3 }, { 90, 90, 90, 80 });
        badQ.print();
    }
    catch (const GeometryException& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
