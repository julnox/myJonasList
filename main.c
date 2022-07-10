/*
    MyJonasList:
    Programa que lista características de obras audiovisuais,
    armazena em arquivos txt
*/

#include <locale.h>
#include "menus.h"
#include "funcoes.h"

int main(void)
{
    unsigned int acaoPrincipal;
    setlocale(LC_ALL, "Portuguese_Brazilian");
    checarLocal ();

    while (acaoPrincipal != 6)
    {
        acaoPrincipal = menuPrincipal();
        switch (acaoPrincipal)
        {
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
            break;
        default:
            return 0;
        }
    }
}
