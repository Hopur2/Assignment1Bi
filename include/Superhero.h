#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>

using namespace std;


class Superhero
{
    public:
        Superhero();
        Superhero(string name, int age, char power);
        void setverbose(bool v);
        friend ostream& operator << (ostream& out, const Superhero& superhero);
        friend istream& operator >> (istream& in, Superhero& superhero);


    protected:

    private:
        string _name;
        int _age;
        char _power;
        bool verbose;
};

#endif // SUPERHERO_H
