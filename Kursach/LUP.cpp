#include "LUP.h"

Matrix* InverseLUPMatrixSolver::solve(Matrix* _input)
{
	Matrix* input = new Matrix(*_input);
	int size = input->getSize();
	Matrix* result = new Matrix(size);

	Matrix L(size), U(size);

	float** data = new float* [size];
	for (int i = 0; i < size; ++i) {
		data[i] = new float[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			data[i][j] = input->getValue(i, j);
		}

	}

	for (int i = 0; i < size; i++) {
		L.setValue(i, 0, data[i][0] / data[0][0]);
		U.setValue(0, i, data[0][i]);
	}

	for (int i = 1; i < size; i++) {
		int k = 0;
		for (int j = i; j < size; j++) {
			U.setValue(i, j, data[i][j] - (L.getValue(j, k) * U.getValue(k, j)));
			L.setValue(j, i, (data[j][i] - (L.getValue(j, k) * U.getValue(k, i)) / U.getValue(i, i)));
		}
		k++;
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			result->line_minus_line(i + 1, i, L.getValue(i + 1, j));
			L.line_minus_line(i + 1, i, L.getValue(i + 1, j));
		}

	}

	for (int i = 0; i < size; i++) {
		if (U.getValue(i, i) != 0) {
			result->lineDevide(i, U.getValue(i, i));
			U.lineDevide(i, U.getValue(i, i));
		}
	}

	for (int i = size - 1; i > 0; i--) {
		for (int j = size - 1; j > 0; j--) {
			result->line_minus_line(i - 1, i, U.getValue(i - 1, j));
			U.line_minus_line(i - 1, i, U.getValue(i - 1, j));
		}

	}


	return result;
}
