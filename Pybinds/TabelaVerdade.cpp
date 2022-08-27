#include "TabelaVerdade.h"

bool TabelaVerdade::Not(bool a)
{
    return !a;
}

pybind11::dict TabelaVerdade::TableNot()
{
    pybind11::dict v;

    v["0"] = Not(false);
    v["1"] = Not(true);
    return v;
}

bool TabelaVerdade::And(bool a, bool b)
{
    return a && b;
}

pybind11::dict TabelaVerdade::TableAnd()
{
    return pybind11::dict();
}

bool TabelaVerdade::Or(bool a, bool b)
{
    return a || b;
}

pybind11::dict TabelaVerdade::TableOr()
{
    pybind11::dict v;

    v["00"] = Or(false, false);
    v["01"] = Or(false, true);
    v["10"] = Or(true, false);
    v["11"] = Or(true, true);

    return v;
}

bool TabelaVerdade::Con(bool a, bool b)
{
    return a == b || b;
}

pybind11::dict TabelaVerdade::TableCon()
{
    pybind11::dict v;

    v["00"] = Con(false, false);
    v["01"] = Con(false, true);
    v["10"] = Con(true, false);
    v["11"] = Con(true, true);

    return v;
}

bool TabelaVerdade::BiCon(bool a, bool b)
{
    return a == b;
}

pybind11::dict TabelaVerdade::TableBiCon()
{
    pybind11::dict v;

    v["00"] = BiCon(false, false);
    v["01"] = BiCon(false, true);
    v["10"] = BiCon(true, false);
    v["11"] = BiCon(true, true);

    return v;
}

const char* TabelaVerdade::ToVF(bool v)
{
    return v ? "V" : "F";
}

