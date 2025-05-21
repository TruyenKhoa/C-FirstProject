#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100];
    char IC[7];
    int hours_worked;
    char category[2];
    float gross_pay;
    float overtime_pay;
    float net_pay;
} 
Employee;

void calculate_pay(Employee *employee, float rate) 
{
    if (strcmp(employee->category, "M1") == 0 || strcmp(employee->category, "M2") == 0 ) 
	{
    	if	( employee->hours_worked == 40)
		{
        employee->overtime_pay = 0;
        employee->gross_pay = employee->hours_worked *rate;
        employee->net_pay = employee->gross_pay;
    	}
    else {
    	employee->overtime_pay = 0;
    	employee->gross_pay = 40 * rate;
    	employee->net_pay = employee->gross_pay ;
	}
    }
    else 
    {
        if (employee->hours_worked <= 40) 
        {
        employee->gross_pay = employee->hours_worked * rate;
        employee->overtime_pay = 0;
        }
         else 
        {
        employee->gross_pay = 40 * rate;
        employee->overtime_pay = (employee->hours_worked - 40) * 1.5 * rate;
        }
    employee->net_pay = employee->gross_pay + employee->overtime_pay;
    }
}

int main() 
{
	float rate;
    char category[2];
    char choice;
	Employee employee;
	int a= 1;
	FILE *filePointer;

	filePointer = fopen("employees.dat", "w");
	fprintf( filePointer, "\t\tZEN ICT SOLUTIONS SDN BHD\n");
	fprintf( filePointer, "============================================================\n");
	
	
	 
	while (1) 
	{
		fflush(stdin);
        printf("Enter the employee's name: ");
		scanf("%[^\n]s", &employee.name);
		employee.name[strcspn(employee.name, "\n")] = '\0';

        printf("Enter the employee's IC number: ");
		scanf("%s", &employee.IC);
		employee.IC[strcspn(employee.IC, "\n")] = '\0';

        printf("Enter the number of hours worked: ");
        scanf("%d", &employee.hours_worked);
         if (employee.hours_worked > 60)
        {
         	printf("Error: Invalid hours work. Please try again\n");
			
			printf("\nAdd condition do while Continue (Y/N)?: ");
        	scanf(" %c", &choice);
        	if (choice != 'Y' && choice != 'y') 
			{
            break;
        	}
			continue;				 
		}

        printf("Enter the employee's category (E1, E2, E3, M1, M2): ");
		scanf("%s", &employee.category);
        employee.category[strcspn(employee.category, "\n")] = '\0';

        if (strcmp(employee.category, "E1") == 0)   
		{
            rate = 10;
		}     
        
		else if(strcmp(employee.category, "E2") == 0)
		{
			rate = 12;
		}
		else if(strcmp(employee.category, "E3") == 0) 
		{
			rate = 15;
		}
 		else if (strcmp(employee.category, "M1") == 0) 
		{
            rate = 20;
        } 
        else if (strcmp(employee.category, "M2") == 0) 
        {
        	rate = 25;
		}
		else 
		{
            printf("Error: Invalid category. Please try again.\n");
			
			printf("\nAdd condition do while Continue (Y/N)?: ");
        	scanf(" %c", &choice);
        	if (choice != 'Y' && choice != 'y') 
			{
            break;
        	}
			continue;				            
        }
		calculate_pay(&employee, rate);
 	
	    fprintf( filePointer, "Employee Name: %s\n", employee.name);
		fprintf( filePointer, "Employee IC: %s\n", employee.IC);
		fprintf( filePointer, "Employee Category: %s\n", employee.category);
		fprintf( filePointer, "Number of Hours Worked: %d\n", employee.hours_worked);
		fprintf( filePointer, "Gross Pay: $%.2f\n", employee.gross_pay);
		fprintf( filePointer, "Overtime Pay: $%.2f\n", employee.overtime_pay);
		fprintf( filePointer, "Net Pay: $%.2f\n\n", employee.net_pay);	   

    for(int i= 0; i < a; i++)
	{
    	printf("\t\tZEN ICT SOLUTIONS\n");
    	printf("============================================================\n");
	}
        printf("\nEmployee Name: %s\n", employee.name);
        printf("Employee IC: %s\n", employee.IC);
    	printf("Employee Category: %s\n", employee.category);
        printf("Number of Hours Worked: %d\n", employee.hours_worked);    
        printf("Gross Pay: $%.2f\n", employee.gross_pay);
        printf("Overtime Pay: $%.2f\n", employee.overtime_pay);
        printf("Net Pay: $%.2f\n\n", employee.net_pay);
        printf("\nAdd condition do while Continue (Y/N)?: ");
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') 
		{
            break;
        }
        getchar();
        a=0;
    } 
fclose(filePointer);
return 0;
}