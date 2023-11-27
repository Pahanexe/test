#pragma once
#include "matrix.h"

class InverseLUPMatrixSolver {
private:
public:
	InverseLUPMatrixSolver() = delete;
	static Matrix* solve(Matrix* input);
};
