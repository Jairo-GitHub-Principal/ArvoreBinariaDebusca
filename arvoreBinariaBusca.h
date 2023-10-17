#include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;

     int fatorB; //acrescentada
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
    void removerbusca(Aluno aluno, No*& noatual,bool& diminuiu);
    void deletarNo(No*& noatual,bool& diminuiu);
    void obterSucessor(Aluno& alunoSucessor,No* temp);
    void buscar(Aluno& aluno, bool& buscar);
    void imprimirpreordem(No* Noatual);
    void imprimirEmOrdem(No* Noatual);
    void imprimirPosOrdem(No* Noatual);


    // novos metodos

    void rotacaodireita(No*& tree);
    void rotacaoesquerda(No*& tree);  
    void rotacaoesquerdadireita(No*& tree);
    void rotacaodireitaesquerda(No*& tree);
    void realizarotacao(No*& tree);
    void insererecursivo(No*& noatual, Aluno alunoNovo, bool& cresceu);

    

};