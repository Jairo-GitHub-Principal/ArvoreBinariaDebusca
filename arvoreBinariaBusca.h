#include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;
};


class ArvoreBB{
    private:
    No* raiz;

    public:
    ArvoreBB();
    ~ArvoreBB();
    void deletarArvore(No* Noatual);
    No* obterRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void removerbusca(Aluno aluno, No*& noatual);
    void deletarNo(No*& noatual);
    void obterSucessor(Aluno& alunoSucessor,No* temp);
    void buscar(Aluno& aluno, bool& buscar);
    void imprimirpreordem(No* Noatual);
    void imprimirEmOrdem(No* Noatual);
    void imprimirPosOrdem(No* Noatual);



};