#include <stdlib.h>
#include <locale.h>
#include "myJonasList.h"

int main()
{
    unsigned int acaoPrincipal;

    setlocale(LC_ALL, "Portuguese");

    checarLocal ();

    while (acaoPrincipal != 10)
    {
        acaoPrincipal = menuPrincipal();

        switch (acaoPrincipal)
        {
        case 1:
            listarObras(1);
            break;
        case 2:
            listarObras(2);
            break;
        case 3:
            listarObras(3);
            break;
        case 4:
            listarObras(4);
            break;
        case 5:
            listarObras(5);
            break;
        case 6:
            listarTodasAsObras();
            break;
        case 7:
            adicionarObra();
            break;
        case 8:
            removerObra();
            break;
        case 9:
            buscarObra();
            break;
        default:
            exit(0);
        }
    }
}
