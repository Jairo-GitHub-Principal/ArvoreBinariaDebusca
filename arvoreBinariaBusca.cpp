#include <iostream>
#include <cstddef>
#include "arvoreBinariaBusca.h"


using namespace std;

    ArvoreBB::ArvoreBB(){
        raiz = NULL;
    }
    ArvoreBB::~ArvoreBB(){ // implementar depois de percurso
        deletarArvore(raiz);
    }
    void ArvoreBB::deletarArvore(No* Noatual){ // implementar depois de percurso
        if(Noatual!=NULL){
            deletarArvore(Noatual->filhoesquerda);
            deletarArvore(Noatual->filhodireita); 
            delete Noatual;  
        }
    }
    No*ArvoreBB::obterRaiz(){
        return raiz;
    }
    bool ArvoreBB::estaVazio(){
        return(raiz == NULL);
    }
    bool ArvoreBB::estaCheio(){
        try{
            No* temp = new No;
            delete temp;
            return false;
        }catch(bad_alloc exception){
            return true;
        }
    }
    void ArvoreBB::inserir(Aluno alunoNovo){
        bool cresceu;
        insererecursivo(raiz, alunoNovo, cresceu);
        
    }
    void ArvoreBB::insererecursivo(No*& noatual,Aluno aluno,bool& cresceu){
          // novo
        if (noatual == NULL) {
            noatual = new No;
            noatual->filhodireita = NULL;
            noatual->filhoesquerda = NULL;
            noatual->aluno = aluno;
            noatual->fatorB = 0;
            cresceu = true;
            return;
        }  
        if (aluno.obterRa() < noatual->aluno.obterRa()) {
            insererecursivo(noatual->filhoesquerda, aluno, cresceu);
            if (cresceu){
                noatual->fatorB-=1;   
            } 
        } else {
            insererecursivo(noatual->filhodireita, aluno, cresceu);
            if (cresceu){
                noatual->fatorB+=1;
            }    
        } 
        realizarotacao(noatual);

        if (cresceu && noatual->fatorB == 0){
            cresceu = false;
        }
    }
    void ArvoreBB::remover(Aluno aluno){
          bool diminuiu;
        removerbusca(aluno,raiz,diminuiu);
    }
      void  ArvoreBB::removerbusca(Aluno aluno, No*& noatual,bool& diminuiu){
            if(aluno.obterRa() < noatual->aluno.obterRa()){
                removerbusca(aluno,noatual->filhoesquerda,diminuiu);
                if (diminuiu){
                noatual->fatorB+=1;
            }
            }else if(aluno.obterRa() > noatual->aluno.obterRa()){
                removerbusca(aluno,noatual->filhodireita,diminuiu);
                 if (diminuiu){
                noatual->fatorB-=1;
            }
            }else{
                deletarNo(noatual,diminuiu);
            }
      }
    void  ArvoreBB::deletarNo(No*& noatual,bool& diminuiu){
        No* temp = noatual;
        if(noatual->filhoesquerda == NULL){ // se o filho da esquerda for null, vamos para a direita e deletar o filho a diireita
            noatual = noatual->filhodireita;
            diminuiu = true;
            delete temp;
        }else if(noatual->filhodireita == NULL){
            noatual = noatual->filhoesquerda;
            diminuiu = true;
            delete temp;
        }else{
            Aluno alunoSucessor;
            obterSucessor(alunoSucessor,noatual);
            noatual->aluno = alunoSucessor;
            removerbusca(alunoSucessor,noatual->filhodireita,diminuiu);
             if (diminuiu){
                noatual->fatorB-=1;
            }
        }

    }
    void  ArvoreBB::obterSucessor(Aluno& alunoSucessor,No* temp){
        temp = temp->filhoesquerda;
        while (temp->filhoesquerda != NULL)
        {
             temp = temp->filhoesquerda;
        }
         alunoSucessor = temp->aluno;
        
    }
    void ArvoreBB::buscar(Aluno& aluno, bool& buscar){
        buscar = false;
        No* Noatual = raiz;
        while (Noatual !=NULL)
        {           
            if(aluno.obterRa() < Noatual->aluno.obterRa()){
                Noatual = Noatual->filhoesquerda;
            }else if(aluno.obterRa() > Noatual->aluno.obterRa()){
                Noatual = Noatual->filhodireita;
            }else{
                buscar = true;
                aluno = Noatual->aluno;
                break;
            }
        }
        

    }
    void ArvoreBB::imprimirpreordem(No* Noatual){
         if(Noatual != NULL){
            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;
            imprimirpreordem(Noatual->filhoesquerda);
            imprimirpreordem(Noatual->filhodireita);
                      
         }

    }
    void ArvoreBB::imprimirEmOrdem(No* Noatual){
        if(Noatual != NULL){
        imprimirEmOrdem(Noatual->filhoesquerda);
        cout << Noatual->aluno.obterNome()<< ": ";
        cout << Noatual->aluno.obterRa()<< endl;
        imprimirEmOrdem(Noatual->filhodireita);
        }
    }
    void ArvoreBB::imprimirPosOrdem(No* Noatual){
        if(Noatual != NULL){
            imprimirPosOrdem(Noatual->filhoesquerda);
            imprimirPosOrdem(Noatual->filhodireita);
            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;
        }
    }

     void ArvoreBB::rotacaodireita(No*& pai) //novo
    {
        No* novopai = pai->filhoesquerda;
        pai->filhoesquerda = novopai->filhodireita;
        novopai->filhodireita = pai;
        pai = novopai;
    }

     void ArvoreBB::rotacaoesquerda(No*& pai) //novo
    {
        No* novopai = pai->filhodireita;
        pai->filhodireita = novopai->filhoesquerda;
        novopai->filhoesquerda = pai;
        pai = novopai;
    }

     void ArvoreBB::rotacaoesquerdadireita(No*& pai)
    {
        No* filho = pai->filhoesquerda;
        rotacaoesquerda(filho);
        pai->filhoesquerda = filho;
        rotacaodireita(pai);
    }


    void ArvoreBB::rotacaodireitaesquerda(No*& pai)
    {
        No* filho = pai->filhodireita;
        rotacaodireita(filho);
        pai->filhodireita = filho;
        rotacaoesquerda(pai);
    }

    void ArvoreBB::realizarotacao(No*& pai)
    {
        No* filho;
        No* neto; // Caso precise da rotação dupla

        if (pai->fatorB == -2){ //rotaciona para a direita

                filho = pai->filhoesquerda;

                if (filho->fatorB == -1){ // Simples para a direita
                    pai->fatorB = 0;
                    filho->fatorB = 0;
                    rotacaodireita(pai);
                } else if (filho->fatorB == 0){ // Simples para a direita
                    pai->fatorB = -1;
                    filho->fatorB = 1;
                    rotacaodireita(pai);
                } else if (filho->fatorB == 1){ // Rotação dupla
                    neto = filho->filhodireita;
                    if (neto->fatorB == -1){
                        pai->fatorB = 1;
                        filho->fatorB = 0;
                    } else if (neto->fatorB == 0){
                        pai->fatorB = 0;
                        filho->fatorB = 0;                
                    } else if (neto->fatorB == 1){
                        pai->fatorB = 0;
                        filho->fatorB = -1;                
                    }
                    neto->fatorB = 0; 
                    rotacaodireitaesquerda(pai);            
                }


        } else if(pai->fatorB == 2){ //rotaciona para a esquerda
                    filho = pai->filhodireita;
                    if (filho->fatorB == 1) { // Simples para a esquerda
                        pai->fatorB = 0;
                        filho->fatorB = 0;
                        rotacaoesquerda(pai);
                    } else if (filho->fatorB == 0){ // Simples para a esquerda         
                        pai->fatorB = 1;
                        filho->fatorB = -1;
                        rotacaoesquerda(pai);
                    } else if (filho->fatorB == -1){ // Rotacao dupla
                        neto = filho->filhoesquerda;
                        if (neto->fatorB == -1){
                            pai->fatorB =  0;
                            filho->fatorB = 1; 
                        } else if (neto->fatorB == 0){
                            pai->fatorB =  0;
                            filho->fatorB = 0; 
                        } else if (neto->fatorB == 1){
                            pai->fatorB =  -1;
                            filho->fatorB = 0; 
                        }
                        neto->fatorB = 0;
                        rotacaodireitaesquerda(pai);
                    }
        }
    }                  