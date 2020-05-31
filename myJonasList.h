#ifndef _MYJONASLIST_H_
#define _MYJONASLIST_H_

void checarLocal();
void listarObras (char limparTela [6], int operacao);
void listarTodasAsObras (char limparTela [6]);
void adicionarObra (char limparTela [6]);
void removerObra(char limparTela [6]);
void buscarObra(char limparTela [6]);

typedef struct TV
{
    char titulo [50];
    char sinopse [150];
    char dataDeLancamento [10];
    char categoria [15];
} TV;

#endif
