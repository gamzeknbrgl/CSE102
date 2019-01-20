#include <stdio.h>
#include <stdlib.h>
/*getInt function checks if entry within the operands [mini,maxi] */
int getInt (int mini,int maxi)
{
    int number =0;
    scanf("%d",&number);
    /*checks number for menu part */
    while(number<mini || number>maxi){
        if(mini == 0 && maxi == 3){
            return -1;
        }
        else {
            printf("Wrong input try again.\n");
            scanf("%d", &number);
        }
    }
    return number;
}
/*Number generator function generates a number between min and max values */
int numberGeneratorBetweenRange(int min, int max)
{
    int random_number;
    random_number=(rand() % (max + 1 - min)) + min;
    return random_number;
}
/* Horse Racing Game:
* number of horses between 3 and 5
* each horse runs the course between 10 and 20 units
* fastest horse always win the game */
void horseRacingGame()
{
    int number_of_horses=0, horse_number,i,j,k, horse_speed=1, winner_horse=21, winner_horse_number;
    int mySpeed = 0;
    number_of_horses=numberGeneratorBetweenRange(3,5);
    printf("Number of Horse:%d \n", number_of_horses);
    printf("Horse Number:");
    horse_number = getInt(1,number_of_horses);
    printf("Racing Starts...");
    for(i=1; i<=number_of_horses; i++)
    {

        printf("\nHorse %d: ",i);
        horse_speed=numberGeneratorBetweenRange(10,20);
        if(i==horse_number)
            mySpeed=horse_speed;
        for(j=1; j<=horse_speed; j++)
        {
            printf("-");
        }
        if(horse_speed<=winner_horse) /*compare race completion times for find the winner horse*/
        {
            winner_horse=horse_speed;
            winner_horse_number=i;
        }
    }
    if (horse_number==winner_horse_number )/* if user's horse is the only fastest horse */
    {
        printf("\nYou win! Winner horse is : %d\n",horse_number);
    }
    else if(winner_horse==mySpeed) /*if user's horse is one of the fastest horses */
    {
        printf("\nYou win! Winner horse is : %d\n",horse_number);
    }
    else
    {
        printf("\nYou lose! Winner horse is : %d\n", winner_horse_number);
    }
}
/*Pow function for occurrence part */
int int_pow(int base, int exponent)
{
    int result = 1;
    while (exponent != 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}
/* Compute number length for occurrence part */
int length_of_number(int temp){
    int number_length = 0;
    while(temp>0)
    {
        temp=temp/10;
        number_length++;
    }
    return number_length;
}
/* Compute number of occurrences of search number in big number */
void countOccurrence()
{
    int big_number, search_number,lengthbig=0,lengthsearch=0, occurrence=0, temp;
    int i=0, temp_length, divided;
    printf("Big Number:\n");
    scanf("%d",&big_number);
    printf("Search Number:\n");
    scanf("%d",&search_number);
    lengthbig = length_of_number(big_number);
    lengthsearch = length_of_number(search_number);
    temp = big_number;
    /* check big number part part through search number's length
    * to find the search number in big number */
    for(i=0; i<lengthbig-lengthsearch+1; i++)
    {
            temp_length=length_of_number(temp);
            if(temp_length < lengthsearch)
            {
                break;
            }
            divided = int_pow(10,lengthsearch);
            if(temp%divided==search_number)
            {
                occurrence++;
            }
            temp=temp/10;
    }
    printf("Occurrence: %d\n",occurrence);
}
/* Generate a random value between[2,10]
* then generate a triangle of sequences */
void triangleOfSequences()
{
    int number,i,j;
    number=numberGeneratorBetweenRange(2,10);
    for(i=1; i<=number; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%d ",j*i);
        }
        printf("\n");
    }
}
/* Menu part won't stop until user enter 0 */
void menu()
{
    int choice, exit=0;
    while(choice!=exit)
    {
        /*If user enter a wrong number menu will display again */
        do{
            printf("1. Horse Racing Game\n");
            printf("2. Occurrence Counter \n");
            printf("3. Triangle of Sequences \n");
            printf("0. Exit \n");
            choice = getInt(0,3);
        }while(choice==-1);
        if(choice>0)
        {
            switch(choice)
            {
                case 1:
                    horseRacingGame();
                    break;
                case 2:
                    countOccurrence();
                    break;
                case 3:
                    triangleOfSequences();
                    break;
                default:
                    break;
            }
        }
        else if(choice!=exit)
        {
            printf("1. Horse Racing Game\n");
            printf("2. Occurrence Counter \n");
            printf("3. Triangle of Sequences \n");
            printf("0. Exit \n");
            scanf("%d",&choice);
        }
    }
}
int main()
{
    menu();
    return 0;
}
