#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    float** data;
    int size;
public:
    Matrix(int size);
    explicit Matrix(Matrix&);
    Matrix& operator =(Matrix&) = delete;
    //семейство обработчиков строк матрицы
    void lineMultiply(int i, float a);
    void lineDevide(int i, float a);
    void line_plus_line(int i, int j, float modificator);
    void line_minus_line(int i, int j, float modificator);
    
    //семейство сеттеров
    void setValue(int i, int j, float value);
    //семейство гетеров
    float getValue(int i, int j);
    int getSize();

    float DeterminantSolve() const;
    
    ~Matrix();
};