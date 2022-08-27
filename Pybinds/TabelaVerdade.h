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
	const char* ToVF(bool v);
};


