/*
    As principais funções do programa estão neste arquivo
*/

//Biblioteca padrão para entrada e saida.
#include <stdio.h>
//Biblioteca que possui funções associadas à alocação de memoria, controle de processos e etc.
#include <stdlib.h>
//Biblioteca que possui funções para comparação, atribuição e uso de strings.
#include <string.h>
//Uso da biblioteca para dar uma pausa temporária.
#include <unistd.h>
//Biblioteca especifica do programa que importa funções incluidas no header.
#include "myjonaslist.h"

//Comando usado para criar um tipo de variável.
typedef struct TV
{
    //O termo utilizado para identificar um sequência de caractér.
    char titulo [50];
    char sinopse [1200];
    char dataDeLancamento [12];
    char categoria [150];
} TV;

//Inicializações que podem ser usadas por várias funções.
char localDoArquivo [35];
char localTodosArq [5][35] =
{
    "./arquivos/obrasEmProgresso.txt", // Posição 0
    "./arquivos/obrasCompletadas.txt", // Posição 1
    "./arquivos/obrasPausadas.txt", // Posição 2
    "./arquivos/obrasAbandonadas.txt", // Posição 3
    "./arquivos/obrasPlanejamento.txt", // Posição 4
};

//Ponteiro para FILE usado para criação e manipulação de arquivos.
FILE *arquivo;

//Função para limpar tela Linux e Windows.
void limparTela ()
{
    //Condição para o pre-processamento do programa,
    //Verifica se o sistema utilizado pelo usuário é Windows
    #ifdef _WIN32
    char comandoLimparTela [4] = "cls";
    #endif // Fim da condição

    //Verifica se o sistema utilizado pelo usuário é Linux
    #ifdef linux
    char comandoLimparTela [6] = "clear";
    #endif // linux

    //Manda um comando para o terminal do sistema
    system(comandoLimparTela);
}

//Verificar se os arquivos já existem, se não, será criado novos arquivos
void checarLocal ()
{
    //Laço de repetição que percorre todos os 5 locais de arquivos usados no programa
    for (int i = 0; i < 5; i++)
    {
        //Abre o arquivo no modo de apenas leitura
        arquivo = fopen (localTodosArq[i], "r");

        //Condição para caso o local do arquivo não exista
        if (arquivo == NULL)
        {
            //Abre o arquivo no modo de escrita, criando o arquivo
            arquivo = fopen (localTodosArq[i], "w");
            fclose(arquivo);
        }
        //Condição para caso a anterior seja falsa
        else
        {
            fclose(arquivo);
        }
    }
}

//Função switch case que seleciona o arquivo correspondente
//a ação selecionado pelo usuário nos menus
void escolherLocalArq (unsigned int acao)
{
    switch (acao)
    {
    case 1:
        strcpy(localDoArquivo, "./arquivos/obrasEmProgresso.txt");
        break;
    case 2:
        strcpy(localDoArquivo, "./arquivos/obrasCompletadas.txt");
        break;
    case 3:
        strcpy(localDoArquivo, "./arquivos/obrasPausadas.txt");
        break;
    case 4:
        strcpy(localDoArquivo, "./arquivos/obrasAbandonadas.txt");
        break;
    default:
        strcpy(localDoArquivo, "./arquivos/obrasPlanejamento.txt");
        break;
    }
}

//De acordo com o retorno da função menuListar, a função lista
//o que está presente no arquivo correspondente selecionado pelo usuário
void listarObras (unsigned int acaoListar)
{
    //Caso a escolha do usuário seja 6, a função retornará nada
    //e voltará para o menu principal
    if (acaoListar == 6)
    {
        return;
    }

    char caracter;

    escolherLocalArq(acaoListar);

    arquivo = fopen (localDoArquivo, "r");
    caracter = getc(arquivo);

    limparTela();
    printf ("----------------------------------Listar-------------------------------------\n");

    //Checa se o caractere for igual a End of File (EOF) que é um tipo de caractere
    //utilizado para indicar o final de um arquivo
    while (caracter != EOF)
    {
        if (caracter == ';')
        {
            caracter = '\b';
        }
        else
        {
            printf ("%c", caracter);
            caracter = getc(arquivo);
        }
    }

    printf ("----------------------------------Listar-------------------------------------\n");

    fclose(arquivo);

    printf ("Pressione Enter para continuar. . .\n");
    getchar();
    getchar();

}

//Função que lista todos os arquivos
void listarTodasAsObras ()
{
    char caracter;

    limparTela();
    printf ("---------------------------Lista de Todas as Obras---------------------------\n");

    //Laço de repetição que percorre todos os 5 arquivos
    for (int i = 0; i < 5; i++)
    {
        arquivo = fopen(localTodosArq[i], "r");
        caracter = getc(arquivo);

        //Checa se o caractere for igual a End of File (EOF) que é um tipo de caractere
        //utilizado para indicar o final de um arquivo
        while (caracter != EOF)
        {
            if (caracter == ';')
            {
                caracter = '\b';
            }
            else
            {
                printf ("%c", caracter);
                caracter = getc(arquivo);
            }
        }
        fclose(arquivo);
    }

    printf ("---------------------------Lista de Todas as Obras---------------------------\n");

    printf ("Pressione Enter para continuar. . .\n");
    getchar();
    getchar();
}

//De acordo com o retorno da função menuAdicionar, a função escolhe
//um local do arquivo para o usuário adicionar uma obra audiovisual
void adicionarObra (unsigned int acaoAdicionar)
{
    //Caso a escolha do usuário seja 6, a função retornará nada
    //e voltará para o menu principal
    if (acaoAdicionar == 6)
    {
        return;
    }

    //Cria uma variável matriz do tipo TV
    TV show;

    escolherLocalArq(acaoAdicionar);

    printf ("Digite o título (50 caracteres): ");
    getchar();
    fgets (show.titulo, 50, stdin);

    printf ("Digite a sinopse (1200 caracteres): ");
    fgets (show.sinopse, 1200, stdin);

    printf ("Digite a data de lançamento (12 caracteres): ");
    fgets (show.dataDeLancamento, 12, stdin);

    printf ("Digite as categorias separadas por vírgula (150 caracteres): ");
    fgets (show.categoria, 150, stdin);

    //Tratamento de dados, pois, a função fgets atribui um enter (\n) nos itens digitados pelo usuário,
    //a função strcspn percorre o array e retorna a primeira posição em que o caractere
    //especificado é encontrado, este caractere será substituido por um null terminator (\0)
    show.titulo[strcspn(show.titulo, "\n")] = '\0';
    show.sinopse[strcspn(show.sinopse, "\n")] = '\0';
    show.dataDeLancamento[strcspn(show.dataDeLancamento, "\n")] = '\0';
    show.categoria[strcspn(show.categoria, "\n")] = '\0';


    //Série de loops for para cada item, para identificar se o usuário digitou ';'
    //pois, este caractere poderia quebrar o programa, já que outras funções dependem
    //dele para identificar a separação dos itens de cada campo
    for (int i = 0; show.titulo[i] != '\0'; i++)
    {
        if (show.titulo[i] == ';')
        {
            show.titulo[i] = ' ';
        }
    }

    for (int i = 0; show.sinopse[i] != '\0'; i++)
    {
        if (show.sinopse[i] == ';')
        {
            show.sinopse[i] = ' ';
        }
    }

    for (int i = 0; show.dataDeLancamento[i] != '\0'; i++)
    {
        if (show.dataDeLancamento[i] == ';')
        {
            show.dataDeLancamento[i] = ' ';
        }
    }

    for (int i = 0; show.categoria[i] != '\0'; i++)
    {
        if (show.categoria[i] == ';')
        {
            show.categoria[i] = ' ';
        }
    }

    //Adiciona no arquivo os itens digitados pelo usuário
    arquivo = fopen (localDoArquivo, "a");
    fprintf (arquivo, "Título: %s;\nSinopse: %s;\nData de Lançamento: %s;\nCategoria: %s;\n\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    printf ("Obra Adicionada com Sucesso!\n");

    //Pausa o programa por 1 segundo
    sleep (1);
}

//De acordo com o retorno da função menuRemover, a função escolhe
//um local do arquivo para o usuário remover uma obra audiovisual
void removerObra (unsigned int acaoRemover)
{
    //Caso a escolha do usuário seja 6, a função retornará nada
    //e voltará para o menu principal
    if (acaoRemover == 6)
    {
        return;
    }

    char localArqTemp [34] = {"./arquivos/arquivoTemporario.txt"};
    char caracter;
    int obraParaDeletar, cont1 = 1, cont2 = 1, contPontoVirgula = 0;

    FILE *arquivoOriginal, *arquivoTemp;

    escolherLocalArq(acaoRemover);

    arquivoOriginal = fopen(localDoArquivo, "r");
    caracter = getc(arquivoOriginal);

    //Um menu para o usuário escolher o que será deletado
    limparTela();
    printf ("---------------------------------Remover-------------------------------------\n");

    //Checa se o caractere for igual a End of File (EOF) que é um tipo de caractere
    //utilizado para indicar o final de um arquivo
    if (caracter != EOF)
    {
        printf ("Obra número 1:\n");
    }

    //Checa se o caractere for igual a End of File (EOF) que é um tipo de caractere
    //utilizado para indicar o final de um arquivo
    while (caracter != EOF)
    {
        //Checa se o caracter é um ';', atribui no lugar dele um backspace '\b',
        //o cursor retorna uma posição e deixa de imprimir o ponto vírgula,
        //Se a condição for verdadeira adiciona um ao contador de ';'
        if (caracter == ';')
        {
            caracter = '\b';
            contPontoVirgula++;
        }
        //Se a condição anterior seja falsa e o caracter não for End of File (EOF)
        else if (caracter != EOF)
        {
            printf("%c", caracter);
            caracter = getc(arquivoOriginal);
        }
        //Se o contador de ponto e virgula for igual a 4, ou seja, se o caracter tiver
        //percorrido todos os itens de uma obra
        if (contPontoVirgula == 4)
        {
            //Percorre três caracteres com a finalidade de identificar
            //uma nova obra audiovisual ou o final do arquivo
            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = EOF ou 'T'

            //O 'T' (Título) é o primeiro caractere da matriz que representa
            //uma nova obra com seus respectivos campos
            if (caracter == 'T')
            {
                //Contador de obras
                cont1++;
                printf ("\n");
                printf ("\nObra número %i:\n", cont1);
                printf ("%c", caracter);
                caracter = getc(arquivoOriginal);
            }

            //Se a condição anterior não for verdadeira,
            //Logicamente, o caracter é igual a End of File (EOF)
            else
            {
                printf ("\n");
            }
            //Reseta o contador de pontos e vírgulas
            contPontoVirgula = 0;
        }
    }

    printf ("---------------------------------Remover-------------------------------------\n");

    //Rebobina a posição do caractere no arquivo
    rewind(arquivoOriginal);

    //Input do usuário com o número respectivo a obra que ele deseja deletar
    do
    {
        printf("\nDigite o número da obra que deseja deletar: ");
        scanf("%d", &obraParaDeletar);
    }
    while (obraParaDeletar < 1 || obraParaDeletar > cont1);

    //Substitue o arquivo temporario se ele existir por um arquivo em branco,
    //caso contrario irá criar um novo arquivo
    arquivoTemp = fopen(localArqTemp, "w");

    caracter = getc(arquivoOriginal);
    //Reseta o contador ponto e vírgula
    contPontoVirgula = 0;

    //Checa se o caractere for igual a End of File (EOF) que é um tipo de caractere
    //utilizado para indicar o final de um arquivo
    while (caracter != EOF)
    {
        //Se se o caracter for igual ';'
        //é adicionado 1 no contador de ponto e vírgula
        if (caracter == ';')
        {
            //Se o cont2 (contador da obra em que o caracter se encontra)
            //não for igual ao int da obraParaDeletar digitada pelo usuário,
            //caracter é colocado dentro do arquivo tempórario
            if (cont2 != obraParaDeletar)
            {
                putc(caracter, arquivoTemp);
            }
            contPontoVirgula++;
        }
        //Se a condição anterior for falsa, o cont2 não for igual a obraParaDeletar
        //e não for igual a End of File (EOF), caracter será colocado no arquivo tempórario
        else if (cont2 != obraParaDeletar && caracter != EOF)
        {
            putc(caracter, arquivoTemp);
        }
        //Se o contador de ponto e virgula for igual a 4, ou seja, se o caracter tiver
        //percorrido todos os itens de uma obra
        if (contPontoVirgula == 4)
        {
            //Percorre três caracteres com a finalidade de identificar
            //uma nova obra audiovisual ou o final do arquivo
            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = EOF ou 'T'

            //O 'T' (Título) é o primeiro caractere da matriz que representa
            //uma nova obra com seus respectivos campos
            if (caracter == 'T')
            {
                //Contador de obras
                cont2++;

                //Se o cont2 não for igual a obraParaDeletar,
                //é colocado os dois \n anteriores do caracter atual
                //e o caracter atual que é 'T'
                if (cont2 != obraParaDeletar)
                {
                    putc ('\n', arquivoTemp);
                    putc ('\n', arquivoTemp);
                    putc(caracter, arquivoTemp);
                }
            }
            //Se a condição anterior não for verdadeira,
            //Logicamente, o caracter é igual a End of File (EOF)
            else
            {
                putc ('\n', arquivoTemp);
                putc ('\n', arquivoTemp);
            }
            contPontoVirgula = 0;
        }
        caracter = getc(arquivoOriginal);
    }

    //Remove o arquivo original
    remove(localDoArquivo);
    //Renomeia o arquivo temporário pelo nome do arquivo original
    rename(localArqTemp, localDoArquivo);

    fclose(arquivoOriginal);
    fclose(arquivoTemp);
}

//De acordo com o retorno da função menuPesquisar, a função
//abre uma janela do navegador (Chrome) com uma url "Estou com sorte" do Google,
//específico para o tipo de obra escolhida pelo usuário
void pesquisarObra (unsigned int acaoPesquisar)
{
    //Caso a escolha do usuário seja 4, a função retornará nada
    //e voltará para o menu principal
    if (acaoPesquisar == 4)
    {
        return;
    }

    char titulo [50];
    char google [110];

    //Condição para o pre-processamento do programa,
    //o comando será diferente caso o SO seja Windows ou Linux
    #ifdef _WIN32
    char comando[15] = {"start \"\" "};
    #endif // _WIN32

    #ifdef linux
    char comando[10] = {"xdg-open "};
    #endif // linux

    //URL Estou com sorte:
    //Substituir "term" por titulo da obra separado por hífen
    //"https://www.google.com/search?q=term&btnI"

    //A URL mudará conforme o tipo de obra que o usuário deseja pesquisar
    switch (acaoPesquisar)
    {
    case 1:
        strcpy(google, "\"https://www.google.com/search?q=myanimelist-");
        break;
    case 2:
        strcpy(google, "\"https://www.google.com/search?q=imdb-");
        break;
    case 3:
        strcpy(google, "\"https://www.google.com/search?q=");
        break;
    default:
        return;
    }

    limparTela();
    printf ("--------------------------------Pesquisar------------------------------------\n");

    printf ("Digite o nome de uma obra: ");
    getchar();
    fgets (titulo, 50, stdin);

    printf ("--------------------------------Pesquisar------------------------------------\n");

    //Tratamento de dados, pois, a função fgets atribui um enter (\n) nos itens digitados pelo usuário,
    //a função strcspn percorre o array e retorna a primeira posição em que o caractere
    //especificado é encontrado, este caractere será substituido por um null terminator (\0)
    titulo[strcspn(titulo, "\n")] = '\0';

    //Tratamento que substitui espaço por hífen para ser utilizado na URL
    //Loop for enquanto titulo na posição i for diferente de null terminator '\0'
    for (int i = 0; titulo[i] != '\0'; i++)
    {
        if (titulo[i] == ' ')
        {
            titulo[i] = '-';
        }
    }

    //Funções para concatenar a URL com o titulo especificado pelo usuário
    strcat(google, titulo);
    strcat(google, "&btnI\"");
    strcat(comando, google);

    //Para Debug:
    //printf ("Comando : %s\n", comando);

    printf ("Você será redirecionado para uma página\n");
    // Pausa o programa por um segundo
    sleep (1);

    //Manda o comando para o terminal do sistema abrir o navegador na URL já concatenada
    system (comando);
}
