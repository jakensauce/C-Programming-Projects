//Jacob Valenti 00312239
// Project 2


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ClearScreen();
int RandomDecider();
int GenRandomBurger(int[]);
int BuildBurger(int[], int);
void PrintBurger(int[], int);
int CompareBurger(int[], int[], int, int);
int CalculateTotals(int[], int, int);
int PlayRound();

int main(void)
{
    
srand(time(0));
int ingredientsList[] = {0,1,2,3,4,5,6,7,8,9,10};
int BuiltBurg[] = {0,0,0,0,0,0,0,0,0,0,0};
int ingreCount = GenRandomBurger(ingredientsList);
ClearScreen();
puts("");
printf("# of Ingredients -> %i\n", ingreCount);
int newIngre = BuildBurger(BuiltBurg, ingreCount);
printf("# of New Ingredients %i\n", newIngre);
int Equality = CompareBurger(ingredientsList, BuiltBurg, ingreCount, newIngre);
printf("Burger: 1 if right, 0 if wrong -->%i\n", Equality);

}

//Function that takes user input to *guess what the burger does
int BuildBurger(int Burger[], int numIngredients)
{
    int i = 0;
    //printf("%i", numIngredients);
    puts("Can you remember the order?");
    //scanf("%i\n", &Burger[i]);
    while(i < numIngredients)
    {
        //printf("\n");
        scanf("%i", &Burger[i]);
        puts("");
        //numIngredients++;
        i++;
        //scanf(" %i\n", &Burger[i]);

    }
    for (int index = 0; index < numIngredients; index++ )
    {
        printf("New ->%i\n", Burger[index]);
    }

return numIngredients;
}
//Randomly chooses a 1 or a 0
int RandomDecider()
{
    //srand(time(0));
    int Rando = rand() % 2;
    //printf("%i\n", Rando);
    return Rando;
}
//Loop Generates a random burger from the list of ingredients
int GenRandomBurger(int randBurger[])
{
    int i = 0;
    int numberOfIngre = 0; //keeps track of number of ingredients
    puts("This is your Burger:");
    while(i < 11)
    {
        if (RandomDecider() == 1)
        {
            randBurger[numberOfIngre] = i;
            printf("|%i|", randBurger[i]); //print for Debugging
            numberOfIngre++;
        }
        i++;
    }
    puts("");
return numberOfIngre;

}

//Takes both arrays of burgers and checks to see if they hold the same values
int CompareBurger(int Burg1[], int Burg2[], int burg1size, int burg2size)
{
    int Burg1frequency[11] = {0};
    int Burg2frequency[11] = {0};
    int index = 0;
    int Equality = 1;

    printf("Burger 1 Array\n");
    for(int i = 0; i < burg1size; i++)
    {
        Burg1frequency[Burg1[i]] += 1;
    }
    for(int i = 0; i < burg1size; i++)
    {
        printf("|%i|", Burg1frequency[i]);
    }
    puts("");
    printf("Burger 2 Array\n");
    for(int i = 0; i < burg2size; i++)
    {
        Burg2frequency[Burg2[i]] += 1;
    }
    for(int i = 0; i < burg2size; i++)
    {
        printf("|%i|", Burg2frequency[i]);
    }
    puts("");
        while(index < burg1size && Equality)
    {
        if(Burg1[index] != Burg2[index])
        {
            Equality = 0;
        }
        index++;
    }

    if(Equality)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

//Clears screen going through a loop adding 50 new lines

void ClearScreen()
{
    int Start;
    puts("Enter 1 if you are ready to guess the order\nEnter anything else to Quit\n");
    scanf("%i", &Start);
    if (Start == 1)
    {
        int Max = 50;
        int Min = 0;
        while(Min < Max)
        {
            printf("\n");
            Min++;
        }
    }
    else
    {
        puts("Game Quit");
        exit(0);
    }
}

void PrintBurger(int pBurger[], int amount)
{
puts("\nHere is your Burger:");
for(int i = 0; i < amount; i++)
{
    printf("|%i|", pBurger[i]);
}
puts("");

}
