#include <stdlib.h>
#include <stdio.h>

/*
 * Programmer: Valerie Lam
 * Course: Computer Systems & Low Level Programming - CIS 2107
 * Assignment: Lab 2 - Paycheck and Revenue - Paycheck component
 * Due Date: February 2nd, 2020
 * Description: Write a program called "Paycheck" to calculate the paycheck for a Temple Employee based on the hourlySalary, weeklyTime, and overtime.
 */

void display_startup_banner();
int get_employee_number();
double get_hourly_salary();
double get_hours_worked();
double calc_pay(double, double);
void display_receipt(int, double, double, double);

int main(){

	display_startup_banner();
	int number = get_employee_number();
	double salary = get_hourly_salary();
	double hours = get_hours_worked();
	double netPay = calc_pay(salary, hours);
	display_receipt(number, salary, hours, netPay);

	return EXIT_SUCCESS;
}

void display_startup_banner(){
	puts("\nWelcome to \"TEMPLE HUMAN RESOURCES\"");
}

int get_employee_number(){

	int number;

	printf("\n\tEnter Employee Number: ");
	scanf("%d", &number);

	if(number <= 0){
		puts("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n");
		puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
		exit(0);
	}else
		return number;
}

double get_hourly_salary(){

        double salary;

        printf("\tEnter Hourly Salary: ");
        scanf("%lf", &salary);

        if(salary <= 0){
                puts("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n");
                puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
		exit(0);
	}else
        	return salary;
}

double get_hours_worked(){

        double hours;

        printf("\tEnter Weekly Time: ");
        scanf("%lf", &hours);

        if(hours <= 0){
                puts("\n\tThis is not a valid weekly time.\n\tPlease run the program again\n");
                puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
		exit(0);
        }else

        return hours;
}

double calc_pay(double salary, double hours){

	double netPay;
	double overTime;
	double overTimePay;

	if (hours <= 40)
		netPay = hours * salary;
	else if (hours > 40)
		overTime = hours - 40;
		overTimePay = salary * 1.5;
		netPay = (hours - 40) * salary + (overTimePay * overTime);

	return netPay;
}

void display_receipt(int number, double salary, double hours, double netPay){
	printf("\t=============================");
	printf("\n\tEmployee #: %d\n", number);
	printf("\tHourly Salary: $%.1lf\n", salary);
	printf("\tWeekly Time: %.1lf\n", hours);
	printf("\tRegular Pay: $%.1lf\n", salary * hours);
	printf("\tOvertime Pay: $%.1lf\n", (hours - 40) * (salary * 1.5));
	printf("\tNet Pay: $%.1lf\n", netPay);
	printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n\n");
}
