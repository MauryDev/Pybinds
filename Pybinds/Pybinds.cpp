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

bool GetBitFromInt(UINT32 INPUT,int N)
{
    auto result = (INPUT >> N) & 1;
    return result;
}
int powi(int base, unsigned int exp)
{
    int res = 1;
    while (exp) {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}
void TableDynamic(py::function& callback,int n)
{
    UINT32 inicial = 0;
    py::list ls(n);
    auto len_loop = powi(2, n);

    for (size_t i = 0; i < len_loop; i++)
    {
        for (size_t i2 = 0; i2 < n; i2++)
        {
            ls[i2] = GetBitFromInt(inicial, i2);
        }
        callback(ls,n);
        inicial++;
    }
}
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
    m.def("TableDynamic", TableDynamic);
    m.def("ToVF", TabelaVerdade::ToVF);

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