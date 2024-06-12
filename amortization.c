// Author: Vaibhav Bhargava
// Loan Calculator

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double getMonthlyPayment(double p, double r, int t);
double getInterestExpense(double balance, double rate);

int main() {
    FILE *out;
    out = fopen("schedule.txt", "w");

    // variable declarations for PRT
    double principle, rate;
    int time;

    // introductory banner statement
    printf("\nNeudesic Coding Interview Project - House Loan Amortization Schedule:\n");
    printf("House Loan Amortization Schedule Projection:\n");
    printf("Please enter the following information to build your schedule.\n");
    
    // gather user inputs prior to calculations
    printf("Enter the total loan amount: ");
    scanf("%lf", &principle);
    printf("Enter the length of the loan in months: ");
    scanf("%d", &time);
    printf("Enter the loan's interest rate: ");
    scanf("%lf", &rate);
    double ratepp = rate/12.0/100.0;

    // initialize variables for calculations
    double schedule[time];
    double intExp;
    double prinExp;
    double currentBalance = principle;

    // call method for finding the monthly payment
    double monthExp = getMonthlyPayment(principle, ratepp, time);

    // print header for output:
    fprintf(out, "Month\t\t\tRemaining Balance\t\t\tMonthly Payment\t\t\tInterest Expense\t\tPrinciple Expense\n");
    
    // loop over all the rows of the table
    for(int i=0; i<time; i++) {
        // call method to find interest expense within payment
        intExp = (currentBalance * ratepp);
        
        // calculate the principle expense
        prinExp = monthExp - intExp;

        // update current balance
        currentBalance -= prinExp;

        // print lines with format specifiers in separate file
        fprintf(out, "%2d%25.2f%25.2f%25.2f%25.2f\n", (i+1), currentBalance, monthExp, intExp, prinExp);
    }

    // close file
    fclose(out);
}

double getMonthlyPayment(double p, double r, int t) {
    double result;
    double temp = 1.0 + r;
    temp = pow(temp, t);
    result = p * r * temp / (temp - 1);
    return result;
}
