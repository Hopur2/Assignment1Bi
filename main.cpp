#include <iostream>
#include <fstream>
#include "Superhero.h"

using namespace std;

void savehero(Superhero& superhero);
void seeheroes();
void createhero();
void menu();

int main()
{
    menu();
}

void menu()
{
    char option;
    cout << "What would you like to do?" << endl;
    cout << "c - create a hero" << endl;
    cout << "v - View all heroes" << endl;
    cin >> option;
    switch(option)
    {
        case 'c':
            system("cls");
            createhero();
            break;
        case 'v':
            system("cls");
            seeheroes();
            break;
        default:
            system("cls");
            menu();
            break;
    }
}

void savehero(Superhero& superhero)
{
    ofstream fout;
    fout.open("justiceleague.txt", ios::app);

    if(fout.is_open())
    {
        superhero.setverbose(false);
        fout << superhero;
        fout.close();
        superhero.setverbose(true);
    }
    else
    {
        cout << "Could not open file";
    }
    cout << superhero << endl << "has been saved" << endl;
    menu();
}

void seeheroes()
{
    ifstream fin;
    Superhero hero;
    fin.open("justiceleague.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            fin >> hero;
            if(fin.eof())
                break;
            cout << hero;
        }
    }
    else
    {
        cout << "Could not open file";
    }

    menu();
}

void createhero()
{
    char option;
    string name;
    int age;
    char power;
    cout << "What would you like the hero to be called? ";
    cin >> name;
    cout << "How old is the hero? ";
    cin >> age;
    cout << "What superpower does the hero have?" << endl;
    cout << "f - Flying" << endl << "g - Giant" << endl << "h - Hacker" << endl << "n - None" << endl;
    cin >> power;
    Superhero hero(name, age, power);
    cout << "That's a nice hero" << endl;
    cout << hero;
    cout << "Would you like to save it? (y/n)";
    cin >> option;
    if(option == 'y')
    {
        savehero(hero);
    }
    else
    {
        menu();
    }
}
