#include <iostream>
using namespace std;

class Aluno
{
private:
    /* data */
    int ra;
    std::string nome;
public:
    Aluno(/* args */);
    Aluno(int r, std::string n);
    string obterNome(); 
    int obterRa();
};


