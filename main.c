#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TVShow
{
    int id;
    char title [50];
    char synopsis [150];
    unsigned int airedDate;
    char category [15];
} TVShow;

int main()
{
    int mainAction = 0;

    while (mainAction != 8)
    {
        do
        {
            system("clear");
            printf ("                                       dd         bb              \n");
            printf ("              mm mm mmmm    aa aa      dd   eee   bb      yy   yy \n");
            printf ("              mmm  mm  mm  aa aaa  dddddd ee   e  bbbbbb  yy   yy \n");
            printf ("              mmm  mm  mm aa  aaa dd   dd eeeee   bb   bb  yyyyyy \n");
            printf ("              mmm  mm  mm  aaa aa  dddddd  eeeee  bbbbbb       yy \n");
            printf ("                                                           yyyyy  \n");
            printf ("                        jjj                              \n");
            printf ("                             oooo  nn nnn    aa aa  sss  \n");
            printf ("                        jjj oo  oo nnn  nn  aa aaa s     \n");
            printf ("                        jjj oo  oo nn   nn aa  aaa  sss  \n");
            printf ("                        jjj  oooo  nn   nn  aaa aa     s \n");
            printf ("                      jjjj                          sss  \n");
            printf ("\n");
            printf ("--------------------------------Name--------------------------------\n");
            printf ("|Type (1) to list watched shows                                    |\n");
            printf ("|Type (2) to list paused shows                                     |\n");
            printf ("|Type (3) to list dropped shows                                    |\n");
            printf ("|Type (4) to list planning to watch shows                          |\n");
            printf ("|Type (5) to list all shows                                        |\n");
            printf ("|Type (6) to add a show                                            |\n");
            printf ("|Type (7) to remove a show                                         |\n");
            printf ("|Type (8) to exit                                                  |\n");
            printf ("--------------------------------Name--------------------------------\n");
            printf ("Type the number corresponding to the action: ");
            scanf ("%i", &mainAction);
        }
        while (mainAction < 1 || mainAction > 7);

        if (mainAction == 1)
        {

        }
        else if (mainAction == 2)
        {

        }
        else if (mainAction == 3)
        {

        }
        else if (mainAction == 4)
        {

        }
        else if (mainAction == 5)
        {

        }
        else if (mainAction == 6)
        {

        }
        else if (mainAction == 7)
        {

        }
        else
        {
            exit(0);
        }
    }
}

void listShows (int operation)
{

    char fileLocation [30];

    if (operation == 1)
    {
        fileLocation == "watchedshows.txt";
    }
    else if (operation == 2)
    {
        fileLocation == "pausedshows.txt"
    }
    else if (operation == 3)
    {
        fileLocation == "droppedshows.txt"
    }
    else
    {
        fileLocation == "planningshows.txt"
    }

    FILE *file = fopen (fileLocation, "r");

    if (file == NULL)
    {
        file = fopen (fileLocation, "w");
        return 3;
    }

    char list [10000];

    while (fgets(list, 10000, file) != NULL)
    {
        printf ("%s", list);
    }
    fclose(file);

}

void addShow ()
{
    TVShow show;

    printf ("--------------------------------Name----------------------------------\n");
    printf ("|Type (1) to add to watched shows                                    |\n");
    printf ("|Type (2) to add to paused shows                                     |\n");
    printf ("|Type (3) to add to dropped shows                                    |\n");
    printf ("|Type (4) to add to planning to watch shows                          |\n");
    printf ("--------------------------------Name----------------------------------\n");

    if (operation == 1)
    {
        fileLocation == "watchedshows.txt";
    }
    else if (operation == 2)
    {
        fileLocation == "pausedshows.txt"
    }
    else if (operation == 3)
    {
        fileLocation == "droppedshows.txt"
    }
    else
    {
        fileLocation == "planningshows.txt"
    }

    show.id = ;

    printf ("Type the title: \n")
    scanf ("%[\n]s", show.title);

    printf ("Type the synopsis: \n");
    scanf ("%[\n]s", show.synopsis);

    printf ("Type the aired date: \n");
    scanf ("%[\n]s", show.airedDate);

    printf ("Type the category: \n");
    printf ("%[\n]s", show.category);

}
void listAllShows ()
{

}
