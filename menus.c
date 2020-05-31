#include <stdio.h>
#include "myJonasList.h"

unsigned int menuPrincipal ()
{
        unsigned int acaoPrincipal;

        do
        {
            limparTela();
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

        return acaoPrincipal;
}

unsigned int menuAdicionar ()
{
    unsigned int operacao;

    do
    {
        limparTela();
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("| Digite (1) para adicionar à lista de obras em progresso                 |\n");
        printf ("| Digite (2) para adicionar à lista de obras completadas                  |\n");
        printf ("| Digite (3) para adicionar à lista de obras pausadas                     |\n");
        printf ("| Digite (4) para adicionar à lista de obras abandonadas                  |\n");
        printf ("| Digite (5) para adicionar à lista de obras em planejamento              |\n");
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &operacao);
    }
    while (operacao < 1 || operacao > 5);

    return operacao;
}
