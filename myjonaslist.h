/*
    Disponibiliza funções para todos os arquivos onde a bliblioteca é importada
*/

//Condição para o pré-compilador
//para evitar que a biblioteca seja importada várias vezes
#ifndef MYJONASLIST_H
#define MYJONASLIST_H

unsigned int menuPrincipal ();
unsigned int menuListar();
unsigned int menuAdicionar ();
unsigned int menuRemover();
unsigned int menuPesquisar ();
void limparTela();
void checarLocal();
void listarTodasAsObras ();
void listarObras (unsigned int acaoListar);
void adicionarObra (unsigned int acaoAdicionar);
void removerObra(unsigned int acaoRemover);
void pesquisarObra(unsigned int acaoPesquisar);

#endif
