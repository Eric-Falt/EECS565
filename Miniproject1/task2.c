#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void bruteForce(char message[130], int keyLength, int firstWordLength);
int main()
{
    // gets the message from the user and removes the newline
    char message[130];
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    // gets the key length from the user
    int keyLength;
    printf("Enter the key length: ");
    scanf("%d", &keyLength);

    // gets the first word length from the user
    int firstWordLength;
    printf("Enter the first word length: ");
    scanf("%d", &firstWordLength);

    // creates a clock to check how long the bruteForce function takes
    clock_t start = clock();

    bruteForce(message, keyLength, firstWordLength);

    // stops the clock
    clock_t end = clock();

    // prints the time the attack took
    printf("Time: %.3f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

void bruteForce(char message[130], int keyLength, int firstWordLength)
{
    // creates dynamiclly allocated strings for the key and a the word thats being tested
    char *key = malloc(keyLength + 1);
    char *testWord = malloc(firstWordLength + 1);

    // opens the text file
    FILE *file = fopen("MP1_dict.txt", "r");

    // stors the current word and the dictionary of possible words 
    char word[16];
    static char words[167964][16];
    int matchingWords = 0;

    // records the possible words from the text file 
    while (fgets(word, 16, file) != NULL)
    {
        word[strcspn(word, "\n")] = '\0';

        if (strlen(word) == firstWordLength)
        {
            strcpy(words[matchingWords], word);
            matchingWords++;
        }
    }

    // initilizes the key to all A's
    for (int i = 0; i < keyLength; ++i)
    {
        key[i] = 'A';
    }

    // adds null terminators to key and testWord
    key[keyLength] = '\0';
    testWord[firstWordLength] = '\0';

    // where the bulk of the cracking happens 
    while (1)
    {
        int done = 1;

        // decrypts first word
        for (int i = 0; i < firstWordLength; ++i)
        {
            testWord[i] = (message[i] - 'A' - (key[i % keyLength] - 'A') + 26) % 26 + 'A';
        }

        // searches dictionary
        for (int j = 0; j < matchingWords; j++)
        {
            if (strcmp(testWord, words[j]) == 0)
            {
                // prints the decrypted message
                for (int k = 0; message[k] != '\0'; ++k)
                {
                    printf("%c", (message[k] - 'A' - (key[k % keyLength] - 'A') + 26) % 26 + 'A');
                }
                printf("\n");
            }
        }

        // checks if this is the final key to break out of the loop 
        for (int i = 0; i < keyLength; ++i)
        {
            if (key[i] != 'Z')
            {
                done = 0;
                break;
            }
        }

        // if its the final key then the program is over 
        if (done == 1)
        {
            break;
        }

        // increments key 
        int i = keyLength - 1;

        // when the last char gets to Z it moves it back one 
        while (i >= 0 && key[i] == 'Z')
        {
            key[i] = 'A';
            i--;
        }

        if (i >= 0)
        {
            key[i]++;
        }
    }

    // frees back memory to avoid leeks 
    free(key);
    free(testWord);
    fclose(file);
}