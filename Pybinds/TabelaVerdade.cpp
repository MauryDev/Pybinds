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

bool TabelaVerdade::Nor(bool a, bool b)
{
    return !(a || b);
}

pybind11::dict TabelaVerdade::TableNor()
{
    pybind11::dict v;

    v["00"] = Nor(false, false);
    v["01"] = Nor(false, true);
    v["10"] = Nor(true, false);
    v["11"] = Nor(true, true);
}

bool TabelaVerdade::Xor(bool a, bool b)
{
    return a != b;
}

pybind11::dict TabelaVerdade::TableXor()
{
    pybind11::dict v;

    v["00"] = Nor(false, false);
    v["01"] = Nor(false, true);
    v["10"] = Nor(true, false);
    v["11"] = Nor(true, true);
}

const char* TabelaVerdade::ToVF(bool v)
{
    return v ? "V" : "F";
}




bool TabelaVerdade::GetBitFromInt(UINT32 INPUT, int N)
{
    auto result = (INPUT >> N) & 1;
    return result;
}
int TabelaVerdade::powi(int base, unsigned int exp)
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
void TabelaVerdade::TableDynamic(pybind11::function& callback, int n)
{
    UINT32 inicial = 0;
    pybind11::list ls(n);
    auto len_loop = powi(2, n);

    for (size_t i = 0; i < len_loop; i++)
    {
        for (size_t i2 = 0; i2 < n; i2++)
        {
            ls[i2] = GetBitFromInt(inicial, i2);
        }
        callback(ls, n);
        inicial++;
    }
}