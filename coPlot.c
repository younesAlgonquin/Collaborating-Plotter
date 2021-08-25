/**************************************************************************
Student name: Younes Boutaleb
Student number: 041019068
Assignment number (and name if any): Lab 04: Collaborating plotter
                                                      
Course name and number: CST8234 C Language
Lab section number: 013
Professor’s name: Natalie Gluzman
Due date of assignment: July 23rd, 2021
Submission date of assignment: July 14, 2021
List of source and header files in the project: coPlot.c , coPlot.h
***************************************************************************/

/**************************************************************************
Declare include files
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "coPlot.h"

/**************************************************************************
 * Main function
 *The main function implements a program that asks for a command to executes 
 * the program parses the name of the command and it's arguments then outputs
 * the results
 * It loops until the user exits
 * Version: 1.0
 * Author/Student Name: Younes Boutaleb
 **************************************************************************/
int main()
{

  /**************************************************************************
   Declare local vriables
  **************************************************************************/
    /*This is the user input including the command name and it's arguments*/
    char *input;
    /*This is the command name in the user's input up to the 1nd space*/
    char *command;
    /*This is the first argument in the user's input up to the 2nd space*/
    char *argument1;
    /*This is the first argument in the user's input up to the 3rd space*/
    /*used to ensure that the user enters only the required number of args*/
    char *argument2;
    /*/*This is the first argument in the user's input up to newline*/
    char *argument3;
    /*this is the return code of the user input*/
    int rc;
    /*This method will generate random integers */
    srand(time(NULL));

  /**************************************************************************
   Dynamic memory allocation
  **************************************************************************/
    input = (char *)malloc(100 * sizeof(char));
    command = (char *)malloc(100 * sizeof(char));
    argument1 = (char *)malloc(100 * sizeof(char));
    argument2 = (char *)malloc(100 * sizeof(char));
    argument3 = (char *)malloc(100 * sizeof(char));

    /*Loops until the user exits the program*/
    while ((strcmp(command, "exit") != 0))
    {
        /*Initialize the allocated menory to null charachter in each iteration*/
        memset(input, 0, 100);
        memset(command, 0, 100);
        memset(argument1, 0, 100);
        memset(argument2, 0, 100);
        memset(argument3, 0, 100);

        /*Prompts for user's input*/
        puts("> Please enter a command to run.");
        rc = scanf(" %[^\n]s", input);

        /*Parse the command name and its arguments */
        sscanf(input, " %s %s %s %[^\n]s", command, argument1, argument2, argument3);

        /*Shutdown the program if the user enters the EOF charachter*/
        if (rc == -1)
        {
            puts("Program terminated.");
            return EXIT_FAILURE;
        }/*end if*/

        /*Execute the betwise operations*/
        if ((strcmp(command, "reverse") != 0) && (strcmp(command, "random") != 0) && (strcmp(command, "exit") != 0))
        {
            /*Display an error message in case of invalid input*/
            /*if the arguments aren't integers or if there's more charachters after the command arguments*/
            if ((isNumber(argument1) == 0) || (isNumber(argument2) == 0) || (strcmp(argument3, "") != 0))
            {
                puts("Invalid command.");
            }/*end if*/
            else
            {
                /*call the bitwise function which executes the user's command and display results*/
                bitwise(command, argument1, argument2);
            }/*end else*/

        } /*end else if*/

        /*Execute the reverse command*/
        else if (strcmp(command, "reverse") == 0)
        {
            /*Parse the name of the command and the text to reverse including spaces*/
            sscanf(input, " %s %[^\n]s", command, argument1);
            /*Call strrev which reverse the text input*/
            printf("%s\n", strrev(argument1));
        } /*end else if*/

        /*Execute the random command*/
        else if (strcmp(command, "random") == 0)
        {
            /*Display and error message if the user adds arguments to the command name*/
            if (strcmp(argument1, "") != 0)
            {
                puts("Invalid command.");
            }/*end if*/
            else
            {
                /*Call the random which generates and displays 20 random sentences*/
                randomSentence();
            }/*end else*/
        }/*end else if*/

        /*Shutdown the program if the user enters "exit"*/
        else if (strcmp(command, "exit") == 0)
        {
            puts("Good Bye!");
        }/*end else if*/

    } /*end while*/

  /**************************************************************************
   Free the allocated memory
  **************************************************************************/
    free(input);
    free(command);
    free(argument1);
    free(argument2);
    free(argument3);

    return EXIT_SUCCESS;
} /*end main*/

/**************************************************************************
 Function to execute betwise operations
 takes command neme and two string integers 
**************************************************************************/
void bitwise(char *command, char *argument1, char *argument2)
{   
    /*Parse the string arguments to integers*/
    int firstInteger = atoi(argument1);
    int secondInteger = atoi(argument2);

    /*Execute bit_or operation*/
    if (strcmp(command, "bit_or") == 0)
    {
        printf("%d\n", firstInteger | secondInteger);
    }/*end if*/

    /*Execute bit_and operation*/
    else if (strcmp(command, "bit_and") == 0)
    {
        printf("%d\n", firstInteger & secondInteger);
    }/*end else if*/

    /*Execute bit_xor operation*/
    else if (strcmp(command, "bit_xor") == 0)
    {
        printf("%d\n", firstInteger ^ secondInteger);
    }/*end else if*/

    /*Execute bit_shift_left operation*/
    else if (strcmp(command, "bit_shift_left") == 0)
    {
        printf("%d\n", firstInteger << secondInteger);
    }/*end else if*/

    /*Execute bit_shift_right operation*/
    else if (strcmp(command, "bit_shift_right") == 0)
    {
        printf("%d\n", firstInteger >> secondInteger);
    }/*end else if*/

    /*Display error message if the user's command is not valid*/
    else
    {
        puts("Invalid command.");

    } /*end else*/

} /*end bitwise*/

/**************************************************************************
 Function to reverse a text
**************************************************************************/
char *strrev(char *str)
{
    /*This is the index of a charachter on the left*/
    int i = 0;
    /*This is the index of a charachter on the right*/
    int j = strlen(str) - 1;
    /*Takes the charachter on the left when swaping charachters*/
    char temp;

    /*Iterates until all charachters are swapped*/
    while (i < j)
    {   
        /*Swapping the left charachter with its corresponding on the right*/
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        /*increment the left index*/
        i++;
        /*Decrement the right index*/
        j--;
    }/*end while*/

    /*return the reversed string*/
    return str;
}/*end strrev*/

/**************************************************************************
 Function that identifies weather string chars are all digits or not
**************************************************************************/
int isNumber(char *str)
{
    /*The for loop variable*/
    int i;
    /*checks all string chars till the null charachter*/
    for (i = 0; str[i] != '\0'; i++)
    {   
        /*Returns 0 and breaks if it finds the first non digit char*/
        if (isdigit(str[i]) == 0)
        {
            return 0;
        }/*end if*/
    }/*end for*/

    /*Returns 1 if all chars are digits*/
    return 1;
}/*end isNumber*/

/**************************************************************************
 Function that generates random sentences
**************************************************************************/
void randomSentence()

{
    /*For loop variable*/
    int i;
    /*arrays index*/
    int index;
    /*array of articles to be used in the sentences*/
    char *article[] = {"the", "a", "one", "about", "some", "any"};
    /*array of nouns to be used in the sentences*/
    char *noun[] = {"men", "women", "dog", "town", "pen", "mouse", "car"};
    /*array of verbs to be used in the sentences*/
    char *verb[] = {"wrote", "barked", "ran", "walked", "clicked"};
    /*array of preposition to be used in the sentences*/
    char *preposition[] = {"to", "from", "at", "over", "under", "on"};
    /*The generated sentence*/
    char sentence[26];

    /*genrate 20 sentences*/
    for (i = 0; i < 20; i++)
    {

        /*initialize the sentence array to null in each iteration*/
        memset(sentence, 0, 26);

        /*Generate a valid random index*/
        index = (int)(rand() % 6);

        /*Concatenate the article at index with sentence content and adds a space*/
        strcat(sentence, article[index]);
        strcat(sentence, " ");

        /*Generate a valid random index*/
        index = (int)(rand() % 7);

        /*Concatenate the noun at index with sentence content and adds a space*/
        strcat(sentence, noun[index]);
        strcat(sentence, " ");

        /*Generate a valid random index*/
        index = (int)(rand() % 5);

        /*Concatenate the verb at index with sentence content and adds a space*/
        strcat(sentence, verb[index]);
        strcat(sentence, " ");

        /*Generate a valid random index*/
        index = (int)(rand() % 6);

        /*Concatenate the preposition at index with sentence content and adds a space*/
        strcat(sentence, preposition[index]);
        strcat(sentence, ".");

        /*Put the first char to upper case*/
        sentence[0] = toupper(sentence[0]);

        /*Print the generated sentence*/
        printf("\n%s\n", sentence);

    } /*end for*/
}/*end random*/