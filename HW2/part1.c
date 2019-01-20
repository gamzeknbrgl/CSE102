#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void score_calculator_menu (int student_count);
void student_counter(void);
void main()
{
    student_counter();
}
/* student_counter function takes the number
* of students from keyboard */
void student_counter(void)
{
    int student_count;
    printf("Enter student count:");
    scanf("%d", &student_count);
    /* Student count must be between 3 and 50
    * if user entered a number out of range
    * program will ask for another number */
    while(student_count<=3 || student_count>=50)
    {
            printf("Not in Range!!! \n");
            printf("Enter student count: \n");
            scanf("%d", &student_count);

    }
    /* If user entered a student count between 3 and 50
    * score_calculator_menu takes student_count
    * as a parameter */
    score_calculator_menu(student_count);
}
/* score_calculator_menu function takes the
* student count as a parameter &
* it generate a random grade for each student &
* calculate the average, find the best and worst student&
* displays a menu for user */
void score_calculator_menu (int student_count)
{
    srand(40);
    int student_grade=0, student_index=0, i, sum_of_grades=0, selection=0;
    int best_student=-1, worst_student=101, best_student_index=0, worst_student_index=0;
    int a_grades=0, b_grades=0, c_grades=0, d_grades=0, f_grades=0;
    double grade_average;
    for (i=1; i<=student_count; i++)
    {
        student_grade=rand()%100; /* generate random grades between 0-100 */
        printf(" %d", student_grade);
        student_index=i;
        if(student_grade>best_student) /* comparing student grades for best student */
        {
            best_student=student_grade;
            best_student_index=student_index;
        }
        if(student_grade<worst_student) /* comparing student grades for worst student */
        {
            worst_student=student_grade;
            worst_student_index=student_index;
        }
        sum_of_grades+=student_grade;
        /* Number of students for each letter grade */
        if(student_grade>=90 && student_grade<=100)
        {
            a_grades++;
        }
        else if(student_grade>=80 && student_grade<=89)
        {
            b_grades++;
        }
        else if(student_grade>=70 && student_grade<=79)
        {
            c_grades++;
        }
        else if(student_grade>=60 && student_grade<=69)
        {
            d_grades++;
        }
        else
        {
            f_grades++;
        }
    }
	 /*Calculate the average of student grades*/
    grade_average=(double)sum_of_grades/student_count;
    /* A menu that won't stop until user entered -1 */
    while (selection!=-1)
    {
        printf("\nStudent Score Calculator Menu for %d Student \n", student_count);
        printf("1) Most Successful Student \n");
        printf("2) Most Unsuccesful Student \n");
        printf("3) Letter Grade Statistics \n");
        printf("4) Calculate Average \n");
        printf("5) Show all data \n");
        printf("                        Make selection: ");
        scanf("%d", &selection);
        /* switch statement for menu */
        switch(selection)
        {
            case 1: 
                printf("Most successfully student: \n");
                printf("Index: %d \n", best_student_index);
                printf("Score: %d\n", best_student);
                break;
            case 2: 
                printf("Most Unsuccessfully student: \n");
                printf("Index: %d \n", worst_student_index);
                printf("Score: %d \n", worst_student);
                break;
            case 3: 
                printf("%d student got letter grade 'A' \n" , a_grades);
                printf("%d student got letter grade 'B' \n",b_grades);
                printf("%d student got letter grade 'C' \n" ,c_grades);
                printf("%d student got letter grade 'D' \n", d_grades);
                printf("%d student got letter grade 'F' \n",f_grades);
                break;
            case 4: 
                printf("The average score of %d Student is :%.2f\n" ,student_count,grade_average);
                break;
            case 5:  
                printf("Most successfully student: \n");
                printf("Index: %d \n", best_student_index);
                printf("Score: %d\n", best_student);
                printf("Most Unsuccessfully student: \n");
                printf("Index: %d \n", worst_student_index);
                printf("Score: %d \n", worst_student);
                printf("%d student got letter grade 'A' \n" , a_grades);
                printf("%d student got letter grade 'B' \n",b_grades);
                printf("%d student got letter grade 'C' \n" ,c_grades);
                printf("%d student got letter grade 'D' \n", d_grades);
                printf("%d student got letter grade 'F' \n",f_grades);
                printf("The average score of %d Student is :%.2f\n" ,student_count,grade_average);
                break;
            case -1: /* If user entered -1 program will exit */
                break;
            default: /* If user entered a invalid value */
                printf("False selection!!!\n");
                break;
        }
    }
}

