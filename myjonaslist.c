#include <stdlib.h>
#include <locale.h>
#include "myjonaslist.h"

int main()
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
            adicionarObra();
            break;
        case 4:
            removerObra();
            break;
        case 5:
            pesquisarObra();
            break;
        default:
            exit(0);
        }
    }
}
