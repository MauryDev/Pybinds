#pragma once
#include <pybind11/pybind11.h>

class Matrix
{
public:
	Matrix();
	void Del();
	double Get(pybind11::tuple tuple);
	double Get(int l,int c);

	void Set(pybind11::tuple tuple, double value);
	void Set(int l, int c, double value);

	int L();
	int C();

	Matrix Add(Matrix& othermatriz);
	Matrix AddD(double val);

	Matrix Sub(Matrix& othermatriz);
	Matrix SubD(double val);
	
	Matrix Mul(Matrix& othermatriz);
	Matrix MulD(double val);

	bool Equal(Matrix& othermatriz);
	bool EqualD(double val);

	Matrix Neg();

	Matrix Div(double v);
	Matrix Pow(double v);

	int GetValueByRange(int v, int max);
	double Det();
	double Cofactor(int l, int c);
	double Trace();
	pybind11::list MainDiagonal();
	pybind11::list Antidiagonal();

	Matrix Transpose();
	Matrix MatrixCofator();
	Matrix Inverse();

	static Matrix Identity(int v);
	static Matrix Line(int c);
	static Matrix Column(int l);
	static Matrix Null(int l,int c);
	static Matrix Square(int v);

	bool isLine();
	bool isColumn();
	bool isNull();
	bool isSquare();
	bool isZero();
	bool isOne();
	bool isTranspose(Matrix& other);
	bool isOpposite(Matrix& other);
	bool isIdentity(Matrix& other);

	// Inverse,IsInverse
	pybind11::str ToStr();
	static Matrix Create1(int L, int C);
	static Matrix Create(int L, int C,pybind11::list ls);
	static Matrix Create2(int L, int C, pybind11::tuple ls);

private:
	int _L, _C;
	double* vals;
};


struct MatrixDel {
	void operator()(Matrix* v);
};