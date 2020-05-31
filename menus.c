#include <stdio.h>
#include "myjonaslist.h"

unsigned int menuPrincipal ()
{
        unsigned int acaoPrincipal;

        do
        {
            limparTela();
            printf ("\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("| Digite (1) para listar obras                                            |\n");
            printf ("| Digite (2) para listar todas as obras                                   |\n");
            printf ("| Digite (3) para adicionar uma obra                                      |\n");
            printf ("| Digite (4) para remover uma obra                                        |\n");
            printf ("| Digite (5) para pesquisar uma obra na internet                          |\n");
            printf ("| Digite (6) para sair                                                    |\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("Digite o número que corresponde à ação: ");
            scanf ("%i", &acaoPrincipal);

        }
        while (acaoPrincipal < 1 || acaoPrincipal > 6);

        return acaoPrincipal;
}

unsigned int menuListar ()
{
    unsigned int acaoListar;

    do
        {
            limparTela();
            printf ("\n");
            printf ("--------------------------------Listar--------------------------------\n");
            printf ("| Digite (1) para listar obras em progresso                          |\n");
            printf ("| Digite (2) para listar obras completadas                           |\n");
            printf ("| Digite (3) para listar obras pausadas                              |\n");
            printf ("| Digite (4) para listar obras abandonadas                           |\n");
            printf ("| Digite (5) para listar obras que se planeja assistir               |\n");
            printf ("| Digite (6) para voltar                                             |\n");
            printf ("--------------------------------Listar--------------------------------\n");
            printf ("Digite o número que corresponde à ação: ");
            scanf ("%i", &acaoListar);

        }
        while (acaoListar < 1 || acaoListar > 6);

        return acaoListar;
}

unsigned int menuAdicionar ()
{
    unsigned int acaoAdicionar;

    do
    {
        limparTela();
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("| Digite (1) para adicionar à lista de obras em progresso                 |\n");
        printf ("| Digite (2) para adicionar à lista de obras completadas                  |\n");
        printf ("| Digite (3) para adicionar à lista de obras pausadas                     |\n");
        printf ("| Digite (4) para adicionar à lista de obras abandonadas                  |\n");
        printf ("| Digite (5) para adicionar à lista de obras em planejamento              |\n");
        printf ("| Digite (6) para voltar                                                  |\n");
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &acaoAdicionar);
    }
    while (acaoAdicionar < 1 || acaoAdicionar > 6);

    return acaoAdicionar;
}

unsigned int menuRemover ()
{
    unsigned int acaoRemover;

    do
    {
        limparTela();
        printf ("--------------------------------Remover----------------------------------\n");
        printf ("| Digite (1) para remover item da lista de obras em progresso             |\n");
        printf ("| Digite (2) para remover item da lista de obras completadas              |\n");
        printf ("| Digite (3) para remover item da lista de obras pausadas                 |\n");
        printf ("| Digite (4) para remover item da lista de obras abandonadas              |\n");
        printf ("| Digite (5) para remover item da lista de obras em planejamento          |\n");
        printf ("| Digite (6) para voltar                                                  |\n");
        printf ("--------------------------------Remover----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &acaoRemover);
    }
    while (acaoRemover < 1 || acaoRemover > 6);

    return acaoRemover;
}

unsigned int menuPesquisar ()
{
    unsigned int acaoPesquisar;

    do
    {
        limparTela();
        printf ("--------------------------------Pesquisar----------------------------------\n");
        printf ("| Digite (1) para pesquisar um anime                                      |\n");
        printf ("| Digite (2) para pesquisar um filme ou série de TV                       |\n");
        printf ("| Digite (3) para pesquisar outros                                        |\n");
        printf ("| Digite (4) para voltar                                                  |\n");
        printf ("--------------------------------Pesquisar----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &acaoPesquisar);
    }
    while (acaoPesquisar < 1 || acaoPesquisar > 4);

    return acaoPesquisar;
}
