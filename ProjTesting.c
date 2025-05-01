/*Jacob Valenti 5/3/2024
Project 3 Testing Grounds*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEXT_BUFFER_SIZE 10000
#define Max_File_Name 25

//Definitions
int encryptText();
int decryptText();
int readPlainText(char*, char*);
void writeCipherText(char*, char*, int, int);
char* readCipherText(char*, int*, int*);
void displayMenu();
int menuChoice();
void encode(char*, char*, int);
char encodeLower(char, int);
char encodeUpper(char, int);

int main(void)
{
    int choice;

    displayMenu();
    scanf(" %i", &choice);
    menuChoice(choice);

    return 0;
}

void displayMenu()
{
    puts("Welcome to the NECC File Encryption and Decryption Program!");
    puts("Please select an option:");
    puts("1 --> Encrypt a File");
    puts("2 --> Decrypt a File");
    puts("3 --> Exit Program");
    printf("Enter an Option:\n");
}

int menuChoice(int choice)
{
    //int choice = scanf("%i", &choice);

    if (choice == 1)
    {
        puts("Encryption Chosen");
        encryptText();
    }
    else if (choice == 2)
    {
        puts("Decryption Chosen");
        decryptText();
    }
    else if (choice == 3)
    {
        puts("--EXITING PROGRAM--\nThank you for using the NECC File\nEncryption and Decryption Program!");
        return EXIT_SUCCESS;
    }
    else
    {
        puts("ERROR: WRONG ENTRY");
    }
    return choice;
}

int encryptText()
{
    int offset;
    char filename[Max_File_Name];
    char NECCfile[Max_File_Name];
    char txt[] = ".txt";
    char NECC[] = ".NECC";
    int newStringIndex = 0;

    //char* storage;
    char* storage = (char*)malloc((TEXT_BUFFER_SIZE+1) * sizeof(char));
    //char* encryptARRAY[] = (char*)malloc(TEXT_BUFFER_SIZE * sizeof(char));

        puts("Please enter the name of the plaintext file you wish to encrypt:");
        scanf("%s", filename);
        int p = strlen(filename+1); ////STRING LENGTH ==== 6 when stevie is typed
        strcat(filename, txt);
        int totalLetters = readPlainText(storage, filename);
        printf("TOTAL %i\n", totalLetters); ////WHY IS THIS 25 #%@#!!!!!

        if (totalLetters == -1)
        {
            return -1;
        }
        else if(p >= Max_File_Name)// || strlen(NECCfile) >= Max_File_Name)
        {
            puts("Error: File Name Too Long");
            return -1;
        }
        else
        {
            puts("Please enter the name of the outputted file:");
            scanf("%s", NECCfile);
            puts("What offset would you like to choose?");
            scanf("%i", &offset);
            strcat(NECCfile, NECC);
            //writeCipherText(NECCfile, storage, offset, totalLetters);
            printf("'%s' has been selected\n'%s' has been created\nOffset:%i\n", filename, NECCfile, offset);
        }

    return 0;
}

///STILL WORKING ON
int decryptText()
{
    char fileName[Max_File_Name];
    char NECC[] = ".NECC";
    puts("Type in the name of the Encrypted file that you would like to decrypt:");
    scanf("%s", fileName);
    if (strlen(fileName) >= Max_File_Name)
        {
            puts("Error: File Name Too Long");
            return -1;
        }
        else
        {
            strcat(fileName, NECC);
            puts(fileName);
            return 0;
        }
}
//RANDOM NOTE: THE DATA FOR THE ENCRYPT in order->(SIGNATURE, OFFSET, DATALENGTH) SHOULD BE
//STORED INTO THE WRITEFILE FUNCTION


//This Function will go inside of encryption because encryption does not return any values
int readPlainText(char* buffMe, char* fileName)
{
    int lineMax = 0;
    FILE* openFile = fopen(fileName, "r");
    char* new = fgets(buffMe, TEXT_BUFFER_SIZE, openFile);
    int letter;
    if (openFile == NULL)
    {
        printf("--ERROR: File doesn't exist--\n");
        return -1;
    }

    while((letter = fgetc(openFile)) != EOF)
    {
        fprintf(openFile, "%s", &buffMe[letter]);
        lineMax++;
    }

    buffMe[lineMax] = '\0';
    fclose(openFile);
    return lineMax;

}

//PRETTY MUCH ALL FROM OLD EXERCISE///////
void writeCipherText(char* fileName, char* letters, int offset, int count)
{
    FILE* openf= fopen(fileName, "w");
    fprintf(openf, "NECC %i %i\n", offset, count);

    int size = strlen(letters);
    for(int i = 0; i < count; i++)
    {
        printf("%c", letters[i]);
        fprintf(openf, "%c\n", letters[i]);

    }

    for(int i = 0; i < size; i++)
    {
        char current = letters[i];
        if(current == ' ')
        {
            letters[i] = current;
        }
        else if(current >= 'A' && current <= 'Z')
        {
            letters[i] = encodeUpper(current, offset);
        }
        else if(current >= 'a' && current <= 'z')
        {
            letters[i] = encodeLower(current, offset);
        }
    }
    letters[size] = '\0';
    fclose(openf);
}

/*Array for lowercase letters that shifts letter whatever the paremeter is*/
char encodeLower(char c, int shift)
{

    int AlphaSize = 26;
    int result = c + shift;
    if(result > 'z')
    {
        result -= AlphaSize;
    }
    return result;
}

/*Array for uppercase letters that shifts letter whatever the paremeter is*/
char encodeUpper(char b, int shift)
{
    int AlphaSize = 26;
    int result = b + shift;
    if(result > 'Z')
    {
        result -= AlphaSize;
    }
    return result;
}




//CODE THAT DID NOT WORK :::::((((((((((((((((
    /*
    for(int i = 0; i < nullTerm; i++)
    {
        buffMe[lineMax] = buffMe[i];
        //fprintf(openFile, "%s", buffMe);
        //fscanf(openFile, "%s", buffMe);
        printf("%c", buffMe[i]);
        lineMax++;
    }
    buffMe[lineMax] = '\0';
    */


//WHILE LOOP DOESNT WORK
    /*
    while (lineMax < TEXT_BUFFER_SIZE && lineMax != '\n')
    {
        fprintf(openFile, "%c\n", buffMe[lineMax]);
        fscanf(openFile, "%s", &buffMe[lineMax]);
        lineMax++;
        printf("%s", buffMe);

        if (lineMax == '\0')
        {
            break;
        }

    }
    */






















