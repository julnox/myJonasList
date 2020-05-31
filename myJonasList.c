#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "myJonasList.h"

int main()
{
    int acaoPrincipal;

    #ifdef _WIN32
    char limparTela [4] = "cls";
    #endif // _WIN32

    #ifdef linux
    char limparTela [6] = "clear";
    #endif // linux

    setlocale(LC_ALL, "Portuguese");

    checarLocal ();

    while (acaoPrincipal != 10)
    {
        do
        {
            system (limparTela);
            printf ("\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("| Digite (1) para listar obras em progresso                               |\n");
            printf ("| Digite (2) para listar obras completados                                |\n");
            printf ("| Digite (3) para listar obras pausadas                                   |\n");
            printf ("| Digite (4) para listar obras abandonadas                                |\n");
            printf ("| Digite (5) para listar obras que se planeja assistir                    |\n");
            printf ("| Digite (6) para listar todas as obras                                   |\n");
            printf ("| Digite (7) para adicionar uma obra                                      |\n");
            printf ("| Digite (8) para remover uma obra                                        |\n");
            printf ("| Digite (9) para buscar uma obra                                         |\n");
            printf ("| Digite (10) para sair                                                   |\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("Digite o número que corresponde à ação: ");
            scanf ("%i", &acaoPrincipal);

        }
        while (acaoPrincipal < 1 || acaoPrincipal > 10);

        switch (acaoPrincipal)
        {
        case 1:
            listarObras(limparTela, 1);
            break;
        case 2:
            listarObras(limparTela, 2);
            break;
        case 3:
            listarObras(limparTela, 3);
            break;
        case 4:
            listarObras(limparTela, 4);
            break;
        case 5:
            listarObras(limparTela, 5);
            break;
        case 6:
            listarTodasAsObras(limparTela);
            break;
        case 7:
            adicionarObra(limparTela);
            break;
        case 8:
            removerObra(limparTela);
            break;
        case 9:
            buscarObra(limparTela);
            break;
        default:
            exit(0);
        }
    }
}
