#include "Matrix.h"
#include <sstream>
Matrix::Matrix()
{
	_L = 0;
	_C = 0;
	vals = NULL;
}

void Matrix::Del()
{
	pybind11::print("Deleted");
	if (vals != NULL)
	{
		_L = 0;
		_C = 0;
		delete[] vals;
		vals = NULL;
	}
	
}


double Matrix::Get(pybind11::tuple tuple)
{
	auto l = tuple[0].cast<int>();
	auto c = tuple[1].cast<int>();

	return Get(l,c);
}

double Matrix::Get(int l, int c)
{
	return vals[l * _C + c];
}


void Matrix::Set(pybind11::tuple tuple, double value)
{
	auto l = tuple[0].cast<int>();
	auto c = tuple[1].cast<int>();
	Set(l, c, value);
}

void Matrix::Set(int l, int c, double value)
{
	vals[l * _C + c] = value;

}

int Matrix::L()
{
	return _L;
}

int Matrix::C()
{
	return _C;
}

Matrix Matrix::Add(Matrix& othermatriz)
{
	// Aij + Bij
	if (othermatriz._L == _L && othermatriz._C == _C)
	{
		Matrix matrizresult = Matrix::Create1(_L, _C);
		auto len = _L * _C;
		for (size_t i = 0; i < len; i++)
		{
			matrizresult.vals[i] = this->vals[i] + othermatriz.vals[i];
		}
		return matrizresult;
	}
	throw std::exception("othermatriz._L != _L || othermatriz._C != _C");

}

Matrix Matrix::AddD(double val)
{
	Matrix matrizresult = Matrix::Create1(_L, _C);
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		matrizresult.vals[i] = this->vals[i] + val;
	}
	return matrizresult;
}

Matrix Matrix::Sub(Matrix& othermatriz)
{
	if (othermatriz._L == _L && othermatriz._C == _C)
	{
		Matrix matrizresult = Matrix::Create1(_L, _C);
		auto len = _L * _C;
		for (size_t i = 0; i < len; i++)
		{
			matrizresult.vals[i] = this->vals[i] - othermatriz.vals[i];
		}
		return matrizresult;
	}
	throw std::exception("othermatriz._L != _L || othermatriz._C != _C");


}

Matrix Matrix::SubD(double val)
{
	Matrix matrizresult = Matrix::Create1(_L, _C);
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		matrizresult.vals[i] = this->vals[i] - val;
	}
	return matrizresult;
}

Matrix Matrix::Mul(Matrix& othermatriz)
{
	if (_C == othermatriz._L)
	{
		Matrix matrizresult = Matrix::Create1(_L, othermatriz._C);
		for (size_t i = 0; i < _L; i++)
		{
			for (size_t i2 = 0; i2 < othermatriz._C; i2++)
			{
				double v = 0;
				for (size_t i3 = 0; i3 < _C; i3++)
				{
					v += Get(i, i3) * othermatriz.Get(i3, i2);
				}
				matrizresult.Set(i, i2, v);
			}
		}
		return matrizresult;
	}
	throw std::exception("_C != othermatriz._L");

}

Matrix Matrix::MulD(double val)
{
	Matrix matrizresult = Matrix::Create1(_L, _C);
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		matrizresult.vals[i] = this->vals[i] * val;
	}

	return matrizresult;
}

bool Matrix::Equal(Matrix& othermatriz)
{
	if (othermatriz._L == _L && othermatriz._C == _C)
	{
		auto len = _L * _C;
		for (size_t i = 0; i < len; i++)
		{
			if (this->vals[i] != othermatriz.vals[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::EqualD(double val)
{
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		if (this->vals[i] != val)
		{
			return false;
		}
	}
	return true;
}

Matrix Matrix::Neg()
{
	Matrix matrizresult = Matrix::Create1(_L, _C);
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		matrizresult.vals[i] = -this->vals[i];
	}
	return matrizresult;
}

Matrix Matrix::Div(double v)
{
	Matrix matrizresult = Matrix::Create1(_L, _C);
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		matrizresult.vals[i] = this->vals[i] / v;
	}
	return matrizresult;
}

Matrix Matrix::Pow(double v)
{
	Matrix matrizresult = Matrix::Create1(_L, _C);
	auto len = _L * _C;
	for (size_t i = 0; i < len; i++)
	{
		matrizresult.vals[i] = pow(this->vals[i], v);
	}
	return matrizresult;
}

int Matrix::GetValueByRange(int v, int max)
{
	auto rest = v % max;
	return v < 0 ? (rest == 0 ? 0 : max + rest) : rest;
}

double Matrix::Det()
{
	if (_L == _C)
	{
		if (_L <= 0)
		{
			return 0;
		}
		if (_L == 1)
		{
			return this->Get(0, 0);
		}
		if (_L == 2)
		{
			return this->Get(0, 0) * this->Get(1, 1) - this->Get(0, 1) * this->Get(1, 0);
		}
		if (_L == 3)
		{
			double DP = double(), DS = double();
			for (size_t i = 0; i < 3; i++)
			{
				DP += this->Get(0, i) * this->Get(1, GetValueByRange(i + 1, 3)) * this->Get(2, GetValueByRange(i + 2, 3));
				DS += this->Get(0, i) * this->Get(1, GetValueByRange(i - 1, 3)) * this->Get(2, GetValueByRange(i - 2, 3));

			}
			return DP - DS;
		}
		if (_L >= 4)
		{
			double D = double();
			for (size_t i = 0; i < _C; i++)
			{
				double a1j = this->Get(0, i);
				double A1j = this->Cofactor(0, i);

				D += a1j * A1j;
			}
			return D;
		}
	}
	else
	{
		return 0;
	}
}

double Matrix::Cofactor(int l, int c)
{
	int soma = (c + l) % 2 == 0 ? 1 : -1;
	Matrix matriz = Matrix::Create1(_L - 1, _C - 1);
	int i3 = 0;
	for (size_t i = 0; i < _L; i++)
	{
		int i4 = 0;
		if (i != l)
		{
			for (size_t i2 = 0; i2 < _C; i2++)
			{
				if (i2 != c)
				{
					
					matriz.Set(i3, i4, this->Get(i, i2));
					++i4;
				}
			}
			i3++;
		}
	}
	auto result = soma* matriz.Det();
	matriz.Del();
	return result;
}

double Matrix::Trace()
{
	if (isSquare())
	{
		double result = 0;
		for (size_t i = 0; i < _L; i++)
		{
			result += Get(i, i);
		}
		return result;
	}
	throw std::exception("No square");
}

pybind11::list Matrix::MainDiagonal()
{
	if (isSquare())
	{
		pybind11::list result(_L);
		for (size_t i = 0; i < _L; i++)
		{
			result[i] = Get(i, i);
		}
		return result;
	}
	throw std::exception("No square");

}

pybind11::list Matrix::Antidiagonal()
{
	if (isSquare())
	{
		pybind11::list result(_L);
		auto lmem = _L - 1;
		for (size_t i = 0; i < _L; i++)
		{
			result[i] = Get(i, lmem - i);
		}
		return result;
	}
	throw std::exception("No square");
}



Matrix Matrix::Transpose()
{
	Matrix matriz = Matrix::Create1(_C, _L);
	for (size_t i = 0; i < _L; i++)
	{
		for (size_t i2 = 0; i2 < _C; i2++)
		{
			matriz.Set(i2, i, Get(i, i2));
		}
	}
	return matriz;
}

Matrix Matrix::MatrixCofator()
{
	auto result = Matrix::Create1(_L, _C);
	for (size_t i = 0; i < _L; i++)
	{
		for (size_t i2 = 0; i2 < _C; i2++)
		{
			result.Set(i, i2, Cofactor(i, i2));
		}
	}
	return result;
}

Matrix Matrix::Inverse()
{
	auto detA = Det();
	if (detA != 0)
	{
		auto cofA = MatrixCofator();
		auto cofAt = cofA.Transpose();

		auto Ai = cofAt.Div(detA);

		cofA.Del();
		cofAt.Del();
		return Ai;
	}
	throw std::exception("DetA == 0");

}

Matrix Matrix::Identity(int v)
{
	auto matriz = Create1(v, v);
	for (size_t i = 0; i < v; i++)
	{
		for (size_t i2 = 0; i2 < v; i2++)
		{
			auto value = (i == i2 ? 1 : 0);
			matriz.Set(i, i2, value);
		}
	}
	return matriz;
}

Matrix Matrix::Line(int c)
{
	auto matriz = Create1(1, c);

	return matriz;
}

Matrix Matrix::Column(int l)
{
	auto matriz = Create1(l, 1);

	return matriz;
}

Matrix Matrix::Null(int l, int c)
{
	auto matriz = Create1(l, c);
	auto total = l * c;
	for (size_t i = 0; i < total; i++)
	{
		matriz.vals[i] = 0.0;
	}

	return matriz;
}

Matrix Matrix::Square(int v)
{
	auto matriz = Create1(v, v);

	return matriz;
}

bool Matrix::isLine()
{
	return _L == 1;
}

bool Matrix::isColumn()
{
	return _C == 1;
}

bool Matrix::isNull()
{
	auto size = _L * _C;
	for (size_t i = 0; i < size; i++)
	{
		if (vals[i] != 0.0)
		{
			return false;
		}
	}
	return true;
}

bool Matrix::isSquare()
{
	return _L == _C;
}

bool Matrix::isZero()
{
	return _L == 0 && _C == 1;
}

bool Matrix::isOne()
{
	return isLine() && isColumn();
}

bool Matrix::isTranspose(Matrix& other)
{
	if (_L == other._L && _C == other._C)
	{
		for (size_t i = 0; i < _L; i++)
		{
			for (size_t i2 = 0; i2 < _C; i2++)
			{
				if (Get(i, i2) != Get(i2, i))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool Matrix::isOpposite(Matrix& other)
{
	if (_L == other._L && _C == other._C)
	{
		for (size_t i = 0; i < _L; i++)
		{
			for (size_t i2 = 0; i2 < _C; i2++)
			{
				if (Get(i, i2) != -Get(i, i2))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool Matrix::isIdentity(Matrix& other)
{
	if (_L == other._L && _C == other._C)
	{
		for (size_t i = 0; i < _L; i++)
		{
			for (size_t i2 = 0; i2 < _C; i2++)
			{
				auto flag = i == i2 ? 1 : 0;
				if (Get(i, i2) != flag)
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

pybind11::str Matrix::ToStr()
{
	std::stringstream str;
	str << "Matriz " << _L << " x " << _C << std::endl;
	for (size_t i = 0; i < _L; i++)
	{
		for (size_t i2 = 0; i2 < _C; i2++)
		{
			str << Get(i, i2) << " ";

		}
		str << std::endl;
	}
	auto f = pybind11::str(str.str());
	
	return f;
}

Matrix Matrix::Create1(int L, int C)
{
	
	Matrix mt;
	mt.vals = new double[L * C];
	mt._L = L;
	mt._C = C;
	return mt;

}

Matrix Matrix::Create(int L, int C, pybind11::list ls)
{
	Matrix mt;

	mt.vals = new double[L * C];
	mt._L = L;
	mt._C = C;
	INT64 i = 0;
	for (auto c : ls)
	{
		auto value = c.cast<double>();
		mt.vals[i++] = value;
	}
	return mt;
}

Matrix Matrix::Create2(int L, int C, pybind11::tuple ls)
{
	Matrix mt;

	mt.vals = new double[L * C];
	mt._L = L;
	mt._C = C;
	INT64 i = 0;
	for (auto c : ls)
	{
		auto value = c.cast<double>();
		mt.vals[i++] = value;
	}
	return mt;
}

void MatrixDel::operator()(Matrix* v)
{
	v->Del();
}
