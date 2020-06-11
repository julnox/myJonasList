/*
    Um arquivo separado para menus do usuário (output),
    e retorno de ações.
*/

//Biblioteca padrão para entrada e saida.
#include <stdio.h>
//Biblioteca especifica do programa que importa funções incluidas no header.
#include "myjonaslist.h"

//Retorna um tipo de varíavel inteira não negativa.
unsigned int menuPrincipal ()
{
    unsigned int acaoPrincipal;
    //Faz primeiro o que está dentro das chaves e depois faz o while.

    do
    {
        limparTela();
        printf ("----------------------------------MyJonasList--------------------------------\n");
        printf ("| Digite (1) para listar obras                                              |\n");
        printf ("| Digite (2) para listar todas as obras                                     |\n");
        printf ("| Digite (3) para adicionar uma obra                                        |\n");
        printf ("| Digite (4) para remover uma obra                                          |\n");
        printf ("| Digite (5) para pesquisar uma obra na internet                            |\n");
        printf ("| Digite (6) para sair                                                      |\n");
        printf ("----------------------------------MyJonasList--------------------------------\n");
        printf ("Digite o número que corresponde à ação: ");
        scanf ("%i", &acaoPrincipal);

    }
    //Essa e uma estrutura de repetição onde as intruções seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoPrincipal < 1 || acaoPrincipal > 6);
    //Retorna a função acaoPrincipal.
    return acaoPrincipal;
}

//Retorna um tipo de varíavel inteira não negativa.
unsigned int menuListar ()
{

    unsigned int acaoListar;
    //Faz primeiro o que está dentro das chaves e depois faz o while.

    do
    {
        limparTela();
        printf ("------------------------------------Listar-----------------------------------\n");
        printf ("| Digite (1) para listar obras em progresso                                 |\n");
        printf ("| Digite (2) para listar obras completadas                                  |\n");
        printf ("| Digite (3) para listar obras pausadas                                     |\n");
        printf ("| Digite (4) para listar obras abandonadas                                  |\n");
        printf ("| Digite (5) para listar obras que se planeja assistir                      |\n");
        printf ("| Digite (6) para voltar                                                    |\n");
        printf ("------------------------------------Listar-----------------------------------\n");
        printf ("Digite o número que corresponde à ação: ");
        scanf ("%i", &acaoListar);

    }
    //Essa e uma estrutura de repetição onde as intruções seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoListar < 1 || acaoListar > 6);
    //Retorna a função acaoListar.
    return acaoListar;
}

//Retorna um tipo de varíavel inteira não negativa.
unsigned int menuAdicionar ()
{
    unsigned int acaoAdicionar;
    //Faz primeiro o que está dentro das chaves e depois faz o while.

    do
    {
        limparTela();
        printf ("---------------------------------Adicionar-----------------------------------\n");
        printf ("| Digite (1) para adicionar à lista de obras em progresso                   |\n");
        printf ("| Digite (2) para adicionar à lista de obras completadas                    |\n");
        printf ("| Digite (3) para adicionar à lista de obras pausadas                       |\n");
        printf ("| Digite (4) para adicionar à lista de obras abandonadas                    |\n");
        printf ("| Digite (5) para adicionar à lista de obras em planejamento                |\n");
        printf ("| Digite (6) para voltar                                                    |\n");
        printf ("---------------------------------Adicionar-----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &acaoAdicionar);
    }
    //Essa e uma estrutura de repetição onde as intruções seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoAdicionar < 1 || acaoAdicionar > 6);
    //Retorna a função acaoAdicionar.
    return acaoAdicionar;
}

//Retorna um tipo de varíavel inteira não negativa.
unsigned int menuRemover ()
{
    unsigned int acaoRemover;
    //Faz primeiro o que está dentro das chaves e depois faz o while.

    do
    {
        limparTela();
        printf ("----------------------------------Remover------------------------------------\n");
        printf ("| Digite (1) para remover item da lista de obras em progresso               |\n");
        printf ("| Digite (2) para remover item da lista de obras completadas                |\n");
        printf ("| Digite (3) para remover item da lista de obras pausadas                   |\n");
        printf ("| Digite (4) para remover item da lista de obras abandonadas                |\n");
        printf ("| Digite (5) para remover item da lista de obras em planejamento            |\n");
        printf ("| Digite (6) para voltar                                                    |\n");
        printf ("----------------------------------Remover------------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &acaoRemover);
    }
    //Essa e uma estrutura de repetição onde as intruções seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoRemover < 1 || acaoRemover > 6);
    //Retorna a função acaoRemover.
    return acaoRemover;
}

//Retorna um tipo de varíavel inteira não negativa.
unsigned int menuPesquisar ()
{
    unsigned int acaoPesquisar;
    //Faz primeiro o que está dentro das chaves e depois faz o while.
    do
    {
        limparTela();
        printf ("---------------------------------Pesquisar-----------------------------------\n");
        printf ("| Digite (1) para pesquisar um anime                                        |\n");
        printf ("| Digite (2) para pesquisar um filme ou série de TV                         |\n");
        printf ("| Digite (3) para pesquisar outros                                          |\n");
        printf ("| Digite (4) para voltar                                                    |\n");
        printf ("---------------------------------Pesquisar-----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &acaoPesquisar);
    }
    //Essa e uma estrutura de repetição onde as intruções seram execultadas pelo menos uma vez enquanto a resposta for (V).
    while (acaoPesquisar < 1 || acaoPesquisar > 4);
    //Retorna a função acaoPesquisar.
    return acaoPesquisar;
}
