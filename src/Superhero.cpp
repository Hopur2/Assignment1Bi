#include "Superhero.h"

Superhero::Superhero()
{
    _name = "";
    _age = 0;
    _power = 'n';
    verbose = true;
    //ctor
}
Superhero::Superhero(string name, int age, char power)
{
    _name = name;
    _age = age;
    _power = power;
    verbose = true;
}

void Superhero::setverbose(bool v)
{
    verbose = v;
}

ostream& operator << (ostream& out, const Superhero& superhero)
{
    if(superhero.verbose)
    {
        out << superhero._name << " ";
        out << "(" << superhero._age << "): ";
        switch(superhero._power)
        {
            case 'f':
                out << "Flying";
                break;
            case 'g':
                out << "Giant";
                break;
            case 'h':
                out << "Hacker";
                break;
            case 'n':
                out << "None";
                break;
            default:
                out << "Weakling";
                break;
        }
    }
    else
    {
        out << superhero._name << " ";
        out << superhero._age << " ";
        out << superhero._power;
    }
    out << endl;
    return out;
}
istream& operator >> (istream& in, Superhero& superhero)
{
    in >> superhero._name >> superhero._age >> superhero._power;
    return in;
}
