//Biblioteca que possui fun��es associadas a aloca��o de memoria, controle de processos e etc.
#include <stdlib.h>
//Biblioteca que implementa a localiza��o de programas e uso de acentua��o de caracteres.
#include <locale.h>
//Biblioteca especifica do programa que importa fun��es incluidas no header.
#include "myjonaslist.h"

int main(void)
{
    //Um modificador para tipos numericos inteiros n�o negativos.
    unsigned int acaoPrincipal;
    //Fun��o usada para adaptar o programa ao idioma que deseja.
    setlocale(LC_ALL, "Portuguese");
    //Verificar se os arquivos usados pelo programa j� est�o criados,
    //caso n�o exita ser� criado.
    checarLocal ();
    //Essa e uma estrutura de repeti��o onde as intru��es seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoPrincipal != 6)
    {
        //Atribui o valor retornado da fun��o menur principal a variavel ac�oPrincipal.
        acaoPrincipal = menuPrincipal();
        //Comando usado para fazer uma estrutura de menu, normalmente usadas para substituir varios ifs e else.
        switch (acaoPrincipal)
        {
        //Esses s�o os casos que acompanham o comando switch, os "blocos" que fazem parte do menu.
        case 1:
            listarObras(menuListar());
            break;
        case 2:
            listarTodasAsObras();
            break;
        case 3:
            adicionarObra(menuAdicionar());
            break;
        case 4:
            removerObra(menuRemover());
            break;
        case 5:
            pesquisarObra(menuPesquisar());
            //Comando padr�o usado no fim de cada case, onde e finalizado a execu��o do switch.
            break;
            //Comando usado para quando nenhuma das alternativas anteriores seja verdadeira.
        default:
            return 0;
        }
    }
}
