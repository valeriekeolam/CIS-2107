#include <stdlib.h>
#include <stdio.h>

/*
 * Programmer: Valerie Lam
 * Course: Computer Systems & Low Level Programming - CIS 2107
 * Assignment: Lab 2 - Paycheck and Revenue - Paycheck component
 * Due Date: February 2nd, 2020
 * Description: Write a program called "Paycheck" to calculate the paycheck for a Temple Employee based on the hourlySalary, weeklyTime, and overtime.
 */

#define PROGRAMMER_NAME "Valerie Lam"

void display_startup_banner();
double get_price();
double get_quantity();
double calc_discount(double);
void display_receipt(double, double, double);

int main(){

        display_startup_banner();
        double price = get_price();
        double quantity = get_quantity();
	double discount = calc_discount(quantity);
	display_receipt(price, quantity, discount);
}

void display_startup_banner(){
        puts("\nWelcome to \"Temple\" store\n");
}

double get_price(){

	double price;

        printf("\tEnter item price: ");
        scanf("%lf", &price);

        if (price <= 0){
		puts("\n\tThis is not a valid item price.\n\tPlease run the program again\n");
		puts("Thank You for using \"Temple\" store\n");
                exit(0);
        }else
       		 return price;
}

double get_quantity(){

	double quantity;

	printf("\tEnter quantity: ");
	scanf("%lf", &quantity);

	if (quantity <= 0){
                puts("\n\tThis is not a valid item price.\n\tPlease run the program again\n");
		puts("Thank You for using \"Temple\" store\n");
                exit(0);
        }else
		return quantity;

}

double calc_discount(double quantity){

	double discount;

	if ((quantity >= 1) && (quantity <= 49))
		discount = 0;
	else if((quantity >= 50) && (quantity <= 99))
		discount = 0.10;
	else if((quantity >= 100) && (quantity <= 149))
		discount = 0.15;
	else if (quantity >= 150)
		discount = 0.25;

	return discount;
}

void display_receipt(double price, double quantity, double discount){

	double total = price * quantity;
	double discountValue = discount * total;
	double discountedTotal = total - discountValue;

	printf("\n\tThe item price is: $%.1lf\n", price);
	printf("\tThe order is: %.0lf item(s)\n", quantity);
	printf("\tThe cost is: $%.1lf\n", total);
	printf("\tThe discount is: %.1lf%%\n", discount * 100);
	printf("\tThe discount amount is: $%.1lf\n", discountValue);
	printf("\tThe total is: $%.1lf\n", discountedTotal);
	puts("\nThank you for using \"Temple\" store\n");
}
