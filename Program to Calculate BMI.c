/* This Program Calculates the Body Mass Index (BMI) using height (in inches) and weight (in pounds). It also displays the Weight Status using the BMI.
   Created by - Kunal Dhanaitkar 00722835
                Department of Computer Science
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaring Variables
    double height, weight, BMI;
    char ch;

    while(1){                           //Puts the program in a loop until the condition becomes false.

        //This welcomes the user and ask them to input Height in inches.
        printf("\nWelcome, This Program calculates your Body Mass Index (BMI) and Displays your Weight Status.\n");
        printf("\nEnter your Height(in inches) = ");
        scanf("%lf", &height);

        //If the Height is out of range, the program displays an error and asks the user to input Height again.
        while(height <= 0.0 || height > 120.0){
            printf("\nERROR: Invalid Input. Enter Height(in inches) Again = ");
            scanf("%lf", &height);
        }

        //Asks the user to input Weight in pounds.
        printf("\nEnter your Weight(in lbs) = ");
        scanf("%lf", &weight);

        //If the input Weight is out of range, the program displays an error and asks the user to input Weight again.
        while(weight <= 0.0 || weight > 1000.0){
            printf("\nERROR: Invalid Input. Enter Weight(in lbs) Again = ");
            scanf("%lf", &weight);
        }

        //Body Mass Index is calculated here and displayed as an output.
        BMI = weight / (height * height) * 703;
        printf("\nYour Body Mass Index with height %.2lf inches and weight %.2lf lbs is %.2lf.\n", height, weight, BMI);

        //Conditional Statements to display Weight Status using the BMI calculated.
        if (BMI<18.5){
            printf("Your BMI is less than 18.5, it falls within the Underweight range.\n");
        }
            else if (BMI>=18.5 && BMI<=24.9){
                printf("Your BMI falls within the Normal weight range.\n");
            }
                else if (BMI>=25.0 && BMI<=29.9){
                    printf("Your BMI falls within the Overweight range.\n");
                }
                    else{
                        printf("Your BMI is greater than 30.0, it falls within the Obese range.\n");
                    }

        //Asks the user if they want to calculate BMI again.
        printf("\nDo you want to calculate Body Mass Index for another person?\n");
        printf("Press Y to continue = ");
        scanf(" %c", &ch);
        if (ch=='y' || ch=='Y'){
            continue;                   //Repeats the loop if either of Y or y is typed in by the user.
        }
            else{
                break;                  //Breaks the loop if anything other than Y or y is typed in.
            }
    }
    return 0;
}
