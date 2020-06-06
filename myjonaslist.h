#ifndef MYJONASLIST_H
#define MYJONASLIST_H

unsigned int menuPrincipal ();
unsigned int menuListar();
unsigned int menuAdicionar ();
unsigned int menuRemover();
unsigned int menuPesquisar ();
void limparTela();
void checarLocal();
void listarObras (unsigned int acaoListar);
void listarTodasAsObras ();
void adicionarObra (unsigned int acaoAdicionar);
void removerObra(unsigned int acaoRemover);
void pesquisarObra(unsigned int acaoPesquisar);

#endif
