#include "matrix.h"
#include "assert.h"
#include <utility>
//using namespace std;


//oppgave 2b)
Matrix::Matrix(int nRows){
    //Sjekker og avbryter om nRows er null
    //eller negativ
    assert(nRows > 0);
    rows = nRows;
    arr2d = new double*[nRows]{};
    
}
//oppgave 2b)
Matrix::Matrix(int nRows, int nColumns) : Matrix{nRows}{
    //Sjekker og avbryter om nColumns er null
    //eller negativ
    assert(nColumns > 0);
    columns = nColumns;
    for(int i = 0; i < nRows; i ++){
        arr2d[i] = new double [nColumns];
        for(int j = 0; j < nColumns; j++){
            arr2d[i][j] = 0;
        }
    }
}


//oppgave 2b)
Matrix::~Matrix(){
    for(unsigned int i = 0; i < rows; i++){
        //Sletter det indre innholdet
        delete[] arr2d[i];
    }
    //Sletter det ytre innholdet
    delete[] arr2d;
}

//Oppgave 2c)
double Matrix::get(int row, int col) const{
    return arr2d[row][col];
}
//Oppgave 2c)
void Matrix::set(int row, int col, double value){
    arr2d[row][col] = value;
}

//oppgave 2e)
int Matrix::getRows() const {
    return rows;
}
//oppgave 2e)
int Matrix::getColumns() const {
    return columns;
}

//oppgave 2f)
ostream& operator<<(ostream& os, const Matrix& matrix){
    for(int i = 0; i < matrix.getRows(); i++){
        for(int j = 0; j < matrix.getColumns(); j++){
            os << "M[" << i << "][" << j << "] = " << matrix.get(i,j) << "\n";
        }
    }
    return os;
}

//oppgave 4a)
Matrix::Matrix(const Matrix& rhs){
    arr2d = new double* [rhs.getRows()];
    rows = rhs.rows;
    columns = rhs.columns;
    for(int i = 0; i < rhs.getRows(); i++){
        arr2d[i] = new double[rhs.getRows()];
        for(int j = 0; j < rhs.getColumns(); j++){
            arr2d[i][j] = rhs.get(i,j);
        }
    }
}

//oppgave 4b)
Matrix& Matrix::operator=(Matrix rhs){
    /*
    double** arr2d2 = new double* [rhs.getRows()]; //allokerer ny plass
    for(int i = 0; i < rhs.getRows(); i++){
        arr2d2[i] = new double[rhs.getRows()];
        for(int j = 0; j < rhs.getColumns(); j++){
            arr2d2[i][j] = rhs.arr2d[i][j];
        }
    }
    //Deallokerer plassen
    for(unsigned int i = 0; i < sizeof(rhs.arr2d); i++){
        delete[] rhs.arr2d[i];
    }
    
    delete[] rhs.arr2d;

    return *this; 
    */
    std::swap(rows, rhs.rows);
    std::swap(columns, rhs.columns);
    std::swap(arr2d, rhs.arr2d);

   return *this;
}


Matrix& Matrix::operator+=(Matrix rhs){
    for(int i = 0; i < rhs.getRows(); i++){
        for(int j = 0; j < rhs.getColumns(); j++){
            double value = this->get(i,j);
            value += rhs.get(i,j);
            this->set(i,j,value);
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix rhs){
    return Matrix{*this} += rhs;
}