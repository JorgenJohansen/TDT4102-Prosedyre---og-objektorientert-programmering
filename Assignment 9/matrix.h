#pragma once
#include "ostream"
using std::ostream;
//Oppgave 2a)
class Matrix {
    int rows;
    int columns;
    double** arr2d;

public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();

    Matrix(const Matrix& rhs);
    Matrix& operator=(Matrix rhs);
    Matrix& operator += (Matrix rhs);
    Matrix operator + (Matrix rhs);

    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const;
    int getColumns() const;
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
};
