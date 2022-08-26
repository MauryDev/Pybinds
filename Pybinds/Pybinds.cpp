// Pybinds.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include <fstream>
#include <sstream>
namespace py = pybind11;

bool Not(bool a)
{
    return !a;
}
py::dict TableNot()
{
    py::dict v;
    
    v["0"] = Not(false);
    v["1"] = Not(true);
    return v;
}

bool And(bool a, bool b)
{
    return a && b;
}
py::dict TableAnd()
{
    py::dict v;

    v["00"] = And(false,false);
    v["01"] = And(false,true);
    v["10"] = And(true,false);
    v["11"] = And(true,true);

    return v;
}
bool Or(bool a, bool b)
{
    return a || b;
}
py::dict TableOr()
{
    py::dict v;

    v["00"] = Or(false, false);
    v["01"] = Or(false, true);
    v["10"] = Or(true, false);
    v["11"] = Or(true, true);

    return v;
}
bool Con(bool a, bool b)
{
    return a == b || b;
}
py::dict TableCon()
{
    py::dict v;

    v["00"] = Con(false, false);
    v["01"] = Con(false, true);
    v["10"] = Con(true, false);
    v["11"] = Con(true, true);

    return v;
}

bool BiCon(bool a, bool b)
{
    return a == b;
}
py::dict TableBiCon()
{
    py::dict v;

    v["00"] = BiCon(false, false);
    v["01"] = BiCon(false, true);
    v["10"] = BiCon(true, false);
    v["11"] = BiCon(true, true);

    return v;
}


PYBIND11_EMBEDDED_MODULE(fast_math, m) {
    m.def("Not", Not);
    m.def("And", And);
    m.def("Or", Or);
    m.def("Con", Con);
    m.def("BiCon", BiCon);
    m.def("TableNot", TableNot);
    m.def("TableAnd", TableAnd);
    m.def("TableOr", TableOr);
    m.def("TableCon", TableCon);
    m.def("TableBiCon", TableBiCon);

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