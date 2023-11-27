#pragma once
#include "matrix.h"

class InverseGausMatrixSolver {
private:
public:
	InverseGausMatrixSolver() = delete;
	static Matrix* solve(Matrix* input);
};
