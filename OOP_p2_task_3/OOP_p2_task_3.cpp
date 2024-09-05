#include <string>
#include <Windows.h>
#include <iostream>

class Figure {
protected:
    int sides_count;
    std::string name;
    int side_a, side_b, side_c, side_d;
    int angle_A, angle_B, angle_C, angle_D;

    Figure(int sides, const std::string& fig_name)
        : sides_count(sides), name(fig_name), side_a(0), side_b(0), side_c(0), side_d(0),
        angle_A(0), angle_B(0), angle_C(0), angle_D(0) {}

public:
    Figure() : Figure(0, "Фигура") {}

    virtual void print_info() {
        std::cout << get_name() << ": " << std::endl;

        if (sides_count == 3) {
            if ((side_a == side_b && side_b == side_c) && (angle_A == 60 && angle_B == 60 && angle_C == 60)) {
                std::cout << "Правильная" << std::endl;
            }
            else {
                std::cout << "Неправильная" << std::endl;
            }
            std::cout << "Количество сторон: " << sides_count << std::endl;
            std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << std::endl;
            std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << std::endl;
            std::cout << std::endl;
        }
        else if (sides_count == 4) {
            if ((side_a == side_b && side_b == side_c && side_c == side_d) &&
                (angle_A == 90 && angle_B == 90 && angle_C == 90 && angle_D == 90)) {
                std::cout << "Правильная" << std::endl;
            }
            else {
                std::cout << "Неправильная" << std::endl;
            }
            std::cout << "Количество сторон: " << sides_count << std::endl;
            std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d << std::endl;
            std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << " D=" << angle_D << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Правильная" << std::endl;
            std::cout << "Количество сторон: " << sides_count << std::endl;
            std::cout << std::endl;
        }
    }

    int get_sides_count() { return sides_count; }
    std::string get_name() { return name; }
};

class Triangle : protected Figure {
protected:
    Triangle(int sides, const std::string& fig_name, int a, int b, int c, int A, int B, int C)
        : Figure(sides, fig_name) {
        side_a = a;
        side_b = b;
        side_c = c;
        angle_A = A;
        angle_B = B;
        angle_C = C;
    }

public:
    Triangle() : Triangle(3, "Треугольник", 10, 20, 30, 50, 60, 70) {}

    void print_info() override {
        Figure::print_info();
    }

    Figure* get_parent() {
        return static_cast<Figure*>(this);
    }
};

class Right_triangle : public Triangle {
public:
    Right_triangle() : Triangle(3, "Прямоугольный треугольник", 10, 20, 30, 90, 45, 45) {}

    void print_info() override {
        Figure::print_info();
    }
};

class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle() : Triangle(3, "Равнобедренный треугольник", 10, 20, 10, 50, 60, 50) {}

    void print_info() override {
        Figure::print_info();
    }
};

class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle() : Triangle(3, "Равносторонний треугольник", 30, 30, 30, 60, 60, 60) {}

    void print_info() override {
        Figure::print_info();
    }
};

class Quadrangle : protected Figure {
protected:
    Quadrangle(int sides, const std::string& fig_name, int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure(sides, fig_name) {
        side_a = a;
        side_b = b;
        side_c = c;
        side_d = d;
        angle_A = A;
        angle_B = B;
        angle_C = C;
        angle_D = D;
    }

public:
    Quadrangle() : Quadrangle(4, "Четырёхугольник", 10, 20, 30, 40, 50, 60, 70, 80) {}

    void print_info() override {
        Figure::print_info();
    }

    Figure* get_parent() {
        return static_cast<Figure*>(this);
    }
};

class Square : public Quadrangle {
public:
    Square() : Quadrangle(4, "Квадрат", 20, 20, 20, 20, 90, 90, 90, 90) {}

    void print_info() override {
        Figure::print_info();
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram() : Quadrangle(4, "Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40) {}

    void print_info() override {
        Figure::print_info();
    }
};

class Rhombus : public Quadrangle {
public:
    Rhombus() : Quadrangle(4, "Ромб", 30, 30, 30, 30, 60, 60, 60, 60) {}

    void print_info() override {
        Figure::print_info();
    }
};

class Rect : public Quadrangle {
public:
    Rect() : Quadrangle(4, "Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {}

    void print_info() override {
        Figure::print_info();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);   

    Figure* figure = new Figure();
    figure->print_info();

    Triangle triangle;
    Figure* base_triangle = triangle.get_parent();  
    base_triangle->print_info();
   
    Right_triangle right_triangle;
    Figure* base_right_triangle = right_triangle.get_parent();
    base_right_triangle->print_info();
   
    Isosceles_triangle isosceles_triangle;
    Figure* base_isosceles_triangle = isosceles_triangle.get_parent();
    base_isosceles_triangle->print_info();
   
    Equilateral_triangle equilateral_triangle;
    Figure* base_equilateral_triangle = equilateral_triangle.get_parent();
    base_equilateral_triangle->print_info();
   
    Quadrangle quadrangle;
    Figure* base_quadrangle= quadrangle.get_parent();
    base_quadrangle->print_info();
   
    Rect rectangle;
    Figure* base_rectangle = rectangle.get_parent();
    base_rectangle->print_info();
    
    Square square;
    Figure* base_square = square.get_parent();
    base_square->print_info();
    
    Parallelogram parallelogram;
    Figure* base_parallelogram = parallelogram.get_parent();
    base_parallelogram->print_info();

    Rhombus rhombus;
    Figure* base_rhombus = rhombus.get_parent();
    base_rhombus->print_info();
    
    delete figure;

    return 0;
}
