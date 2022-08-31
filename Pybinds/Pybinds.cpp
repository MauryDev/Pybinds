// Pybinds.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <fstream>
#include <sstream>
#include "TabelaVerdade.h"
#include "Matrix.h"
#include <pybind11/functional.h>
#include <tuple> 
namespace py = pybind11;


PYBIND11_MODULE(fast_mathcpp, m) {
    std::tuple<int, char> foo(10, 'x');
    m.def("Not",TabelaVerdade::Not);
    m.def("And", TabelaVerdade::And);
    m.def("Or", TabelaVerdade::Or);
    m.def("Con", TabelaVerdade::Con);
    m.def("BiCon", TabelaVerdade::BiCon);
    m.def("TableNot", TabelaVerdade::TableNot);
    m.def("TableAnd", TabelaVerdade::TableAnd);
    m.def("TableOr", TabelaVerdade::TableOr);
    m.def("TableCon", TabelaVerdade::TableCon);
    m.def("TableBiCon", TabelaVerdade::TableBiCon);
    m.def("TableDynamic", TabelaVerdade::TableDynamic);
    m.def("ToVF", TabelaVerdade::ToVF);
    m.def("Nor", TabelaVerdade::Nor);
    m.def("Xor", TabelaVerdade::Xor);
    m.def("TableXor", TabelaVerdade::TableXor);
    m.def("TableNor", TabelaVerdade::TableNor);

    auto matriz = py::class_<Matrix,std::unique_ptr<Matrix, MatrixDel>>(m, "Matrix");
    matriz.def(py::init(&Matrix::Create));
    matriz.def(py::init(&Matrix::Create1));
    matriz.def(py::init(&Matrix::Create2));

    matriz.def("__setitem__", py::overload_cast<int,int,double>(&Matrix::Set));
    matriz.def("__getitem__", py::overload_cast<int, int>(&Matrix::Get));
    matriz.def("__add__", &Matrix::Add);
    matriz.def("__add__", &Matrix::AddD);
    matriz.def("__sub__", &Matrix::Sub);
    matriz.def("__sub__", &Matrix::SubD);
    matriz.def("__mul__", &Matrix::MulD);
    matriz.def("__mul__", &Matrix::Mul);
    matriz.def("__div__", &Matrix::Div);
    matriz.def("__pow__", &Matrix::Pow);

    matriz.def("__eq__", &Matrix::Equal);
    matriz.def("__eq__", &Matrix::EqualD);

    matriz.def("__neg__", &Matrix::Neg);

    matriz.def("__str__", &Matrix::ToStr);
    matriz.def("Det", &Matrix::Det);
    matriz.def("Cofactor", &Matrix::Cofactor);
    matriz.def("Transpose", &Matrix::Transpose);
    matriz.def("Identity", &Matrix::Identity);
    matriz.def("Line", &Matrix::Line);
    matriz.def("Square", &Matrix::Square);
    matriz.def("Null", &Matrix::Null);
    matriz.def("Column", &Matrix::Column);
    matriz.def("MatrixCofator", &Matrix::MatrixCofator);
    matriz.def("isLine", &Matrix::isLine);
    matriz.def("isColumn", &Matrix::isColumn);
    matriz.def("isNull", &Matrix::isNull);
    matriz.def("isSquare", &Matrix::isSquare);
    matriz.def("isZero", &Matrix::isZero);
    matriz.def("isOne", &Matrix::isOne);
    matriz.def("isTranspose", &Matrix::isTranspose);
    matriz.def("isOpposite", &Matrix::isOpposite);
    matriz.def("isIdentity", &Matrix::isIdentity);
    matriz.def("L", &Matrix::L);
    matriz.def("C", &Matrix::C);
    matriz.def("Trace", &Matrix::Trace);
    matriz.def("MainDiagonal", &Matrix::MainDiagonal);
    matriz.def("Antidiagonal", &Matrix::Antidiagonal);
    matriz.def("Inverse", &Matrix::Inverse);

}
