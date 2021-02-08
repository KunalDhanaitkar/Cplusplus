/* Assignment 3 - A menu driven program to calculate properties of Sphere.
   Created by - Kunal Dhanaitkar 00722835
                Department of Computer Science
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1416        //This declares a constant value for PI for use throughout the code.

//Function Prototypes, also known as Function Declaration.
int printMenuSelection(void);
double sphere_diameter(void);
double sphere_radius(double diameter);
double sphere_area(double diameter);
double sphere_circum(double diameter);
double sphere_vol(double diameter);

/*Main Function*/
int main()
{
    //Declaring Variables
    int selection;
    double diameter, radius, surfacearea, circumference, volume;

    do{                                                     //Puts the program on a loop until the user exits the program.

        //Calling MenuSelection Function to display menu and prompt user to enter a selection.
        selection = printMenuSelection();

        //Conditional Statements to perform after the selection from the menu above.
        switch(selection)
        {
            /*This calculates the radius using diameter.*/
            case 1:
                diameter = sphere_diameter();               //Calling diameter function to prompt the user to enter diameter.
                radius = sphere_radius(diameter);           //Calling radius function to calculate radius of sphere using diameter.
                printf("\nRadius of Sphere with diameter %.2lf is %.2lf.\n", diameter, radius);         //Displays the Radius of Sphere.
                break;
            /*This calculates the Surface Area using diameter.*/
            case 2:
                diameter = sphere_diameter();
                surfacearea = sphere_area(diameter);
                printf("\nSurface Area of Sphere with diameter %.2lf is %.2lf.\n", diameter, surfacearea);          //Displays the Surface Area of Sphere.
                break;
            /*This calculates the Circumference using diameter.*/
            case 3:
                diameter = sphere_diameter();
                circumference = sphere_circum(diameter);
                printf("\nCircumference of Sphere with diameter %.2lf is %.2lf.\n", diameter, circumference);           //Displays the Circumference of Sphere.
                break;
            /*This calculates the Volume using diameter.*/
            case 4:
                diameter = sphere_diameter();
                volume = sphere_vol(diameter);
                printf("\nVolume of Sphere with diameter %.2lf is %.2lf.\n", diameter, volume);           //Displays the Volume of Sphere.
                break;
            /*This exits the program.*/
            case 5:
                printf("\nGoodbye!\n");
                break;
            /*If user enters any number that is not in the selection menu.*/
            default:
                puts("\nInvalid Menu Selection.");
        }

      }while(selection != 5);

      return 0;
}


//Function Definition that displays the Menu screen and prompts user to enter their choice.
int printMenuSelection(void){
        int selection;
        printf("\nWelcome, This program can calculate the following properties of sphere.\n\n");
        printf("1) Radius.\n");
        printf("2) Surface Area.\n");
        printf("3) Circumference.\n");
        printf("4) Volume.\n");
        printf("5) Exit.\n");

        printf("\nEnter your choice to continue: ");            //Prompts user to enter a selection.
        scanf("%d", &selection);                                //Reads and store that selection.
        return selection;
}

//Function Definition to prompt user to enter the diameter entry and check for invalid input.
double sphere_diameter(void){
    double diameter;
    do{
            printf("\nEnter the diameter = ");           //Prompts user to enter a diameter entry.
            scanf("%lf", &diameter);                            //Reads and store that entry.
            if(diameter <= 0.0){                                //Condition for invalid diameter entry.
                printf("Invalid diameter entry.\n");
            }
      }while(diameter <= 0.0);
            return diameter;
}

//Function to Calculate the Radius of Sphere using diameter.
double sphere_radius(double diameter){
    return diameter / 2;
}

//Function to Calculate the Surface Area of Sphere using diameter.
double sphere_area(double diameter){
    double r = diameter / 2;
    return 4 * PI * pow(r , 2);
}

//Function to Calculate the Circumference of Sphere using diameter.
double sphere_circum(double diameter){
    return PI * diameter;
}

//Function to Calculate the Volume of Sphere using diameter.
double sphere_vol(double diameter){
    double r = diameter / 2;
    return 4 * PI / 3 * pow(r , 3);
}
