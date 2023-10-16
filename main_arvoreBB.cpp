#include<iostream>
#include "arvoreBinariaBusca.h"
#include <charconv>

using namespace std;

int main(){

        ArvoreBB arvoreAluno;
        int ra,imp,opicao;
        
        string nome;
        bool busca =false;


            do{
                        cout << "Digite 0 para parar o algoritimo!\n";
                        cout << "Digite 1 para inserir elemento!\n";
                        cout << "Digite 2 para remover elemento!\n";
                        cout << "Digite 3 para buscar um elemento!\n";
                        cout << "Digite 4 para imprimir a arvore!\n";

                    
                        cin >> opicao;
                        switch (opicao){
                            case 1:
                            {
                                cout << "digite o nome do aluno:\n";
                                cin >> nome;
                                cout << "diigiiite o  RA do aluno:\n";
                                cin >> ra;
                                Aluno aluno(ra, nome);
                                if(arvoreAluno.estaCheio() == true){
                                    cout << "a arvore esta cheia:\n";
                                    cout << "Nao foi possivel inserir o elemento!\n";
                                }else{
                                    arvoreAluno.inserir(aluno);
                                }
                            break;
                            }
                            case 2:
                            {
                                cout << "Digite o RA do aluno a ser removido!\n";
                                cin >> ra;
                                Aluno aluno(ra, " ");
                                arvoreAluno.remover(aluno);

                            break;
                            }

                            case 3:{
                                cout <<"Digite o RA do aluno a ser removido:\n";
                                cin >> ra;
                                Aluno aluno(ra," ");
                                arvoreAluno.buscar(aluno,busca);
                                if(busca == true){
                                cout << "elemento encontrado!\n";
                                cout << "Nome: " << aluno.obterNome() << endl;
                                cout << "Ra: "<<aluno.obterRa() << endl;
                                }else{
                                        cout << "Elemento nao encontrado!\n";
                                    }      
                               
                            break;
                            }

                            case 4:{
                                    cout << "Digite 1 para fazer a impressão em pre_ordem!\n";
                                    cout << "Digite 2 para fazer a impressão em ordem!\n";
                                    cout << "Digite 3 para fazer a impressão em pos_ordem!\n";

                                    cin >> imp;

                                    if(imp == 1){
                                    arvoreAluno.imprimirpreordem(arvoreAluno.obterRaiz());
                                    }else if(imp == 2){
                                        arvoreAluno.imprimirEmOrdem(arvoreAluno.obterRaiz());
                                    }else{
                                        arvoreAluno.imprimirPosOrdem(arvoreAluno.obterRaiz());
                                    }
                            break;
                            }
                
                            default:
                                        cout << "a opção escolhida não exite\n digite 0 para sair\n ou tente novamente \n";
                            
                        }
                
            
                
             

                
                }while(opicao !=0);
    return 0;
}