#include "Gaus.h"

Matrix* InverseGausMatrixSolver::solve(Matrix* _input)
{
	Matrix* input = new Matrix(*_input);
	int size = input->getSize();
	Matrix* result = new Matrix(size);

	for (int i = 0; i < size; i++) {
		if (input->getValue(i,i) == 0) {
			for (int j = 0; j < size; j++) {
				if (input->getValue(j, i) != 0) {
					input->line_plus_line(i, j, 1);
					result->line_plus_line(i, j, 1);
					break;
				}
			}
		}
	}


	for (int i = 0; i < size; i++) {
		result->lineDevide(i, input->getValue(i, i));
		input->lineDevide(i, input->getValue(i, i));

		for (int j = i + 1; j < size; j++) {
			result->line_minus_line(j, i, input->getValue(j, i));
			input->line_minus_line(j, i, input->getValue(j, i));

		}
	}

	for (int i = size - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			result->line_minus_line(j, i,input->getValue(j,i));
			input->line_minus_line(j, i, input->getValue(j, i));
		}
	}

	return result;
}
