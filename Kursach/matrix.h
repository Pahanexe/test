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
    //��������� ������������ ����� �������
    void lineMultiply(int i, float a);
    void lineDevide(int i, float a);
    void line_plus_line(int i, int j, float modificator);
    void line_minus_line(int i, int j, float modificator);
    
    //��������� ��������
    void setValue(int i, int j, float value);
    //��������� �������
    float getValue(int i, int j);
    int getSize();

    float DeterminantSolve() const;
    
    ~Matrix();
};