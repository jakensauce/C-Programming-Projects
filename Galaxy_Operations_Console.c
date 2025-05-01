/* Jacob Valenti 2/28/24 00312239  PROJECT 1
I used some variable names that dont really relate to inside the function but everything
outside each function should be alright. */

#include <stdio.h>
#include <stdlib.h>

void Terminal_Overview();
void Terminal_Input(int);
void Translator(char);
void Signal_ID(char);
void Pulse_Analyzer(int);
void Astro_Navigation_Averager(int, int, int, int, int);
void Gravity_Wave_Synchronizer(double, double);
void Nano_Refractor_Predictor(double);


int main(void)
{
int choice;


printf("\nChoose an option to have a task completed.\n");

Terminal_Overview();

scanf(" %i", &choice);

Terminal_Input(choice);


}


void Terminal_Overview()
{
    printf("\n");
    printf("1 -> Quantum Code Translator\n\n");

    printf("2 -> Intergalactic Signal Identifier\n\n");

    printf("3 -> Energy Pulse Analyzer\n\n");

    printf("4 -> Nano-Refractor Predictor\n\n");

    printf("5 -> Astro-Navigation Averager\n\n");

    printf("6 -> Gravity Wave Synchronizer\n\n");

    printf("7 -> Terminal Shutdown\n\n");

}

void Terminal_Input(int Option)
{

    if (Option == 1)
    {
        int straw;
        char Guts;
        puts("-- Quantom Code Translator --");
        puts("Type in a character you want to translate");
        scanf(" %c", &Guts);
        Translator(Guts);
        puts("Completed... Exiting");
        Terminal_Overview();
        scanf(" %i", &straw);
        Terminal_Input(straw);


    }
    else if (Option == 2)
    {
        int stew;
        puts("-- Intergalactic Signal Identifier --");
        puts("INCOMING SIGNALS:");
        Signal_ID('L');
        Signal_ID('3');
        Signal_ID('t');
        Signal_ID('h');
        Signal_ID('Z');
        Signal_ID('5');
        puts("Completed... Exiting");
        Terminal_Overview();
        scanf(" %i", &stew);
        Terminal_Input(stew);
    }
    else if (Option == 3)
    {
        int glass;
        int Griffith;
        puts("-- Energy Pulse Analyzer --");
        puts("Input Pulse Data to be Analyzed:");
        scanf(" %i", &Griffith);
        Pulse_Analyzer(Griffith);
        puts("Completed... Exiting");
        Terminal_Overview();
        scanf(" %i", &glass);
        Terminal_Input(glass);
    }
    else if (Option == 4)
    {
        int cup;
        double ele;
        puts("-- Nano Refractor Predictor --");
        puts("Type in an Element Value:");
        scanf(" %lf", &ele);
        Nano_Refractor_Predictor(ele);
        puts("Completed... Exiting");
        Terminal_Overview();
        scanf(" %i", &cup);
        Terminal_Input(cup);
    }
    else if (Option == 5)
    {
        int hat;
        int Cord1;
        int Cord2;
        int Cord3;
        int Cord4;
        int Cord5;
        puts("-- Astro Navigation Averager --");
        puts("Type in 5 Coordinates:");
        scanf("%i %i %i %i %i", &Cord1, &Cord2, &Cord3, &Cord4, &Cord5);
        Astro_Navigation_Averager(Cord1, Cord2, Cord3, Cord4, Cord5);
        puts("Completed... Exiting");
        Terminal_Overview();
        scanf(" %i", &hat);
        Terminal_Input(hat);
    }
    else if (Option == 6)
    {
        int Milk;
        double Casca;
        double Judeau;
        puts("-- Gravity Wave Synchronizer --");
        puts("Type in 2 Wave Lengths:");
        scanf(" %lf %lf", &Casca, &Judeau);
        Gravity_Wave_Synchronizer(Casca, Judeau);
        puts("Completed... Exiting");
        Terminal_Overview();
        scanf(" %i", &Milk);
        Terminal_Input(Milk);
    }
    else if (Option == 7)
    {
        puts("Thank you for using the Console!... Exiting");
    }
    else
    {
        printf("Incorrect Input.\n");

    }

}

void Translator(char signal)
{
    printf(" %i\n", signal);
}

void Signal_ID(char signal)
{

    if (signal >= 65 && signal <= 90)
    {
    puts("From UPF");
    }
    else if(signal >= 'a' && signal <= 'z')
    {
    puts("From UPF");
    }
    else
    {
    puts("Not from UPF");
    }

}

void Pulse_Analyzer(int wave)
{
    if ( wave % 2 == 1 )
    {
    puts("The Pulse is Weak.");
    }
    else
    {
    puts("The Pulse is Strong");
    }
}

void Astro_Navigation_Averager(int cord, int dist, int far, int close, int somewhere)
{

double cord1 = (double)cord;
double dist1 = (double)dist;
double far1 = (double)far;
double close1 = (double)close;
double somewhere1 = (double)somewhere;

printf("Destination Coordinates: %.3lf\n", (cord1 + dist1 + far1 + close1 + somewhere1)/5);

}

void Gravity_Wave_Synchronizer(double Flux, double Load)
{

float Check = (Flux - Load);
float Sequence = 0.001;

    if (Check == Sequence)
    {
    puts("These waves work together.");
    printf(" %lf\n", Check);
    }
    else
    {
    puts("These waves do not work.");
    printf(" %lf\n", Check);
    }

}

void Nano_Refractor_Predictor(double Element)
{

        printf(" %1.0f\n", Element);

}























