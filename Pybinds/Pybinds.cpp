// Pybinds.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <fstream>
#include <sstream>
#include "TabelaVerdade.h"
#include <pybind11/functional.h>
namespace py = pybind11;


PYBIND11_EMBEDDED_MODULE(fast_math, m) {
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

}

std::string slurp(std::ifstream& in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

int main()
{
    std::ifstream is("C:\\Users\\MALRY\\source\\repos\\Pybinds\\Pybinds\\Code.py");
    std::string str = slurp(is);
    py::scoped_interpreter guard{};


    py::exec(str.data());
}