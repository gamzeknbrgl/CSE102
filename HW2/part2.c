#include <stdio.h>
/* number_digits function takes any number 
* as a parameter to find its last digit  */
int number_digits(int number)
{
    int digit;
    /*Using mod to find digits */
    digit=number%10;
    return digit;
}
int main()
{
    int number, number_length=0, temp;
    printf("Enter the number \n");
    scanf("%d", &number);
    temp=number;
    /* Program will work if user 
    * entered a number between 23 and 98760 */
    if(number>=23 && number<=98760)
    {
	/* find the lenght of number
        which is entered from keyboard */
        while(temp>0)
            {
                temp=temp/10;
                number_length++;
            }
     	/* Finding and displaying the digits
	* until the number_length=0 or number<0 */
       while(number>0 && number_length>0)
       {
           if(number_length==5)
           {
                printf("The fifth digit is : %d \n",number_digits(number/10000) );
           }
           else if(number_length==4)
           {
               printf("The fourth digit is : %d \n",number_digits(number/1000));
           }
           else if(number_length==3)
           {
               printf("The third digit is : %d \n",number_digits(number/100));
           }
           else if(number_length==2)
           {
               printf("The second digit is : %d \n",number_digits(number/10));
           }
           else
           {
               printf("The first digit is : %d \n",number_digits(number));
           }
           number_length--;
    	}
    }
    return 0;
}


