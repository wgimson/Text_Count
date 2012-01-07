/* This is a menu driven program that provides the user with the options of 
 * printing the number of characters, the number of words, or the number of
 * lines in a text file to standard out, the text file being provided as a
 * command line argument. The program repeatedly prompts the user with the 
 * above options until the user opts to quit. Could concievably be used as a 
 * a substitute for the traditional UNIX wc utility. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch, char_count = 0, word_count = 0, line_count = 0;
    char user_mode;

    if (argc != 2) {
        printf("\nUsage: word_count2 file.\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        if ((fp = fopen(argv[1], "rb")) == NULL) {
            printf("\nError: could not open %s.\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        printf("\n\n");
        printf("/*************************************************************\\\n");
        printf("/* Please select the mode you would like to run the file in. *\\\n");
        printf("/*-----------------------------------------------------------*\\\n");
        printf("/* c - Counts characters in file    w - Counts words in file *\\\n");
        printf("/* l - Counts lines in file        q - Quits the program:    *\\\n");
        printf("/*************************************************************\\\n");
        scanf(" %c", &user_mode);

        switch (user_mode) {

            case ('c'): 
                while ((ch = getc(fp)) != EOF) 
                    char_count++;

                if (char_count == 1)
                    printf("\nThere is 1 characters in %s.\n", 
                            argv[1]);
                else 
                    printf("\nThere are %d characters in %s.\n", 
                            char_count, argv[1]);

                printf("\n");
                fclose(fp);
                char_count = 0;
                break;

            case ('w'):
                while ((ch = getc(fp)) != EOF) {
                    if (ch != ' ' && ch != '\n')
                        continue;
                    while (ch == ' ') 
                        ch = getc(fp);
                    word_count++;
                }

                if (word_count == 1)
                    printf("\nThere is 1 word in %s.\n", argv[1]);
                else 
                    printf("\nThere are %d words in %s.\n", 
                            word_count, argv[1]);

                printf("\n");
                fclose(fp);
                word_count = 0;
                break;

            case ('l'):
                while ((ch = getc(fp)) != EOF) {
                    if (ch != '\n')
                        continue;
                    line_count++;
                }

                if (line_count == 1)
                    printf("\nThere is 1 line in %s.\n", argv[1]);
                else 
                    printf("\nThere are %d lines in %s.\n", 
                            line_count, argv[1]);

                printf("\n");
                fclose(fp);
                line_count = 0;
                break;

            case ('q'):
                printf("\nYou have decided to quite the program; goodbye.\n\n");
                fclose(fp);
                return 0;

            default: 
                printf("\nInvalid input: please try again.\n");
                fclose(fp);
                break;
        }
    }
}
