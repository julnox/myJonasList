/*
    MyJonasList:
    Programa que lista características de obras audiovisuais,
    armazena em arquivos txt
*/

//Biblioteca que implementa a localização de programas e uso de acentuação de caracteres.
#include <locale.h>
//Biblioteca especifica do programa que importa funções incluidas no header.
#include "myjonaslist.h"

int main(void)
{
    //Um modificador para tipos numericos inteiros não negativos.
    unsigned int acaoPrincipal;
    //Função usada para adaptar o programa ao idioma que deseja.
    setlocale(LC_ALL, "Portuguese");
    //Verificar se os arquivos usados pelo programa já estão criados,
    //caso não exista será criado.
    checarLocal ();
    //Essa e uma estrutura de repetição onde as intruções seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoPrincipal != 6)
    {
        //Atribui o valor retornado da função menur principal a variavel acãoPrincipal.
        acaoPrincipal = menuPrincipal();
        //Comando usado para fazer uma estrutura de menu, normalmente usadas para substituir varios ifs e else.
        switch (acaoPrincipal)
        {
        //Esses são os casos que acompanham o comando switch, os "blocos" que fazem parte do menu.
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
            //Comando padrão usado no fim de cada case, onde e finalizado a execução do switch.
            break;
            //Comando usado para quando nenhuma das alternativas anteriores seja verdadeira.
        default:
            return 0;
        }
    }
}
