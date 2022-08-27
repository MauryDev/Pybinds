#pragma once

#include <pybind11/pybind11.h>

namespace TabelaVerdade
{
	bool Not(bool a);
	pybind11::dict TableNot();
	bool And(bool a, bool b);
	pybind11::dict TableAnd();
	bool Or(bool a, bool b);
	pybind11::dict TableOr();
	bool Con(bool a, bool b);
	pybind11::dict TableCon();
	bool BiCon(bool a, bool b);
	pybind11::dict TableBiCon();
	bool Nor(bool a, bool b);
	pybind11::dict TableNor();
	bool Xor(bool a, bool b);
	pybind11::dict TableXor();
	const char* ToVF(bool v);
	void TableDynamic(pybind11::function& callback, int n);
	int powi(int base, unsigned int exp);
	bool GetBitFromInt(UINT32 INPUT, int N);

};


