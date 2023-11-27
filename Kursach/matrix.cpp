#include "matrix.h"

Matrix::Matrix(int size)
{
	this->size = size;

	data = new float* [size];
	for (int i = 0; i < size; ++i) {
		data[i] = new float[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				data[i][j] = 1;
			}
			else {
				data[i][j] = 0;
			}
		}
	}
}

Matrix::Matrix(Matrix& source)
{
	size = source.size;

	data = new float* [size];
	for (int i = 0; i < size; ++i) {
		data[i] = new float[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			data[i][j] = source.data[i][j];
		}
	}
}


//семейство сеттеров

void Matrix::setValue(int i, int j, float value)
{
	data[i][j] = value;
}



//семейство гетеров

float Matrix::getValue(int i, int j)
{
	return data[i][j];
}

int Matrix::getSize()
{
	return size;
}

//семейство обработчиков строк матрицы

void Matrix::lineMultiply(int i, float a)
{
	for (int j = 0; j < size; j++) {
		data[i][j] = data[i][j] * a;
	}
}

void Matrix::lineDevide(int i, float a)
{
	for (int j = 0; j < size; j++) {
		data[i][j] = data[i][j] / a;
	}
}

void Matrix::line_plus_line(int i, int j, float mod)
{
	for (int k = 0; k < size; k++) {
		data[i][k] = data[i][k] + data[j][k] * mod;
	}
}

void Matrix::line_minus_line(int i, int j, float mod)
{
	for (int k = 0; k < size; k++) {
		data[i][k] = data[i][k] - data[j][k] * mod;
	}
}

//детерминант матрицы
float Matrix::DeterminantSolve() const
{
	float det = 0;
	int sign = 1;
	for (int j = 0; j < size; j++) {
		Matrix minor(size - 1);
		for (int i = 1; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (k < j) {
					minor.data[i - 1][k] = data[i][k];
				}
				else if (k > j) {
					minor.data[i - 1][k - 1] = data[i][k];
				}
			}
		}
		det += sign * data[0][j] * minor.DeterminantSolve();
		sign = -sign;
	}
	return det;
}

//деструктор
Matrix::~Matrix()
{
	if (data != nullptr) {
		for (int i = 0; i < size; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
}


