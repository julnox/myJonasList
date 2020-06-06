#include <stdlib.h>
#include <locale.h>
#include "myjonaslist.h"

int main(void)
{
    unsigned int acaoPrincipal;

    setlocale(LC_ALL, "Portuguese");
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
