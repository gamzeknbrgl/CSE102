#include <stdio.h>
void write_date(FILE *f, int start_day,int start_month, int start_year, int end_day, int end_month, int end_year);
void new_format();
int main()
{
	char start_date[15];
	char end_date[15];
	int start_day, start_month, start_year, end_day, end_month,end_year;
	int temp_day,temp_month, temp_year;
	FILE *f;
	printf("This program generates all dates (day by day) between two dates.\n" );
	printf("Enter the start date in dd/MM/yyyy format \n");
	scanf("%s",start_date);
	/* Parsing the date */
	sscanf(start_date,"%d/%d/%d",&start_day,&start_month,&start_year);
	/*Check the date */
	if(start_day>31 || start_day<0 || start_month<0 || start_month>12 || start_year<0){
		printf("Invalid date\n");
		return 0;
	}
	printf("Enter the end date in dd/MM/yyyy format \n");
	scanf("%s",end_date);
	sscanf(end_date,"%d/%d/%d",&end_day,&end_month,&end_year);
	if(end_day>31 || end_day<0 || end_month<0 || end_month>12 || end_year<0){
		printf("Invalid date\n");
		return 0;
	}
	/*If the month hasn't 31 days and user enters wrong date */
	if(start_day==31 && !(start_month==1 ||start_month==3  || start_month==5 ||start_month==7 || start_month==8 || start_month==10 || start_month==12) || 
		end_day==31 && !(end_month==1 ||end_month==3  || end_month==5 || end_month==7 || end_month==8 || end_month==10 || end_month==12)){
		printf("Invalid date \n");
		return 0;
	}
	/*If the month is February and user enters a wrong date */
	if((start_month==2 && start_day>29) || (end_month==2 && end_day>29)){
		printf("Invalid date \n");
		return 0;
	}
	if((!(start_year%400 ==0 || (start_year%100 != 0 && start_year%4 == 0)) && start_month==2 && start_day>28 ) || 
		(!(end_year%400 ==0 || (end_year%100 != 0 && end_year%4 == 0)) && end_month==2 && end_day>28 )){
		printf("Invalid date \n");
		return 0;
	}
	/*If the end date is earlier than the start date */
	if(start_year==end_year && start_month>end_month){
		temp_month=start_month;
		start_month=end_month;
		end_month=temp_month;
	}
	if(start_year>end_year){
		temp_year=start_year;
		start_year=end_year;
		end_year=temp_year;
	}
	if(start_year==end_year && start_month==end_month && start_day>end_day){
		temp_day=start_day;
		start_day=end_day;
		end_day=temp_day;
	}
	/*If user enters same dates */
	if(start_day==end_day && start_month==end_month && start_year==end_year){
		printf("Start date and end date are the same. \n");
		return 0;
	}
	f=fopen("input_date.txt","w");
	/*Write the start date to input_date.txt file */
	fprintf(f,"%02d/%02d/%d",start_day,start_month,start_year);
	write_date(f, start_day,start_month,start_year,end_day,end_month,end_year);
	fclose(f);
	new_format();
	return 0;
}
/*write_date function generates all dates (day by day)between start date & end date. Then write them to input_date.txt file */
void write_date(FILE *f, int start_day,int start_month, int start_year, int end_day, int end_month, int end_year){
		int a,b,c;
		/*If start month has 31 days */
		if(start_day==30 && (start_month==1 ||start_month==3  || start_month==5 ||start_month==7 || start_month==8 || start_month==10 || start_month==12) ){
			start_day++;
		}
		else if(start_day==31&& (start_month==1 ||start_month==3  || start_month==5 ||start_month==7 || start_month==8 || start_month==10 || start_month==12)){

			if(start_month!=12){
			start_month=start_month+1;
			start_day=1;
			}
			/*If the day is last day of December, year changes*/
			if(start_month==12){
				start_month=1;
				start_day=1;
				start_year++;
			}
		}
		/*If start month has 30 days */
		else if(start_day==30 && (start_month==4 || start_month==6 || start_month==9 ||start_month==11 )){
			start_day=1;
			start_month=start_month+1;
		}
		/*If month is February */
		else if(start_day==28 && (start_month==2))
		{
			/*Check for leap year*/
			if(start_year%400 ==0 || (start_year%100 != 0 && start_year%4 == 0)){
				start_day++;
			}
			else{
				start_month=start_month+1;
				start_day=1;
			}
		}
		else if(start_day==29 && start_month==2){
			start_month=start_month+1;
			start_day=1;
		}
		else {
			start_day++;
		}
		/*Write the dates to input_date.txt file */
		fprintf(f, "\n%02d/%02d/%d",start_day,start_month,start_year);
		/*Check the start date and end date if they're not equal call the function again. */
		if(!(start_day==end_day && start_month==end_month && start_year==end_year)){
		write_date(f, start_day,start_month,start_year,end_day,end_month,end_year);
		}	
}
/*new_format function reads each line from “input_date.txt file, convert
*date format and write them to new_date.txt line by line */
void new_format()
{
	char date[15];
	char day1[]="Saturday", day2[]="Sunday", day3[]="Monday", day4[]="Tuesday", day5[]="Wednesday", day6[]="Thursday", day7[]="Friday";
	char month1[]="January" , month2[]="February", month3[]="March", month4[]="April", month5[]="May", month6[]="June";
	char month7[]="July", month8[]="August", month9[]="September", month10[]="October", month11[]="November", month12[]="December";
	int date_day, date_month, date_year, leap_year, temp ,day_of_week, yy,century;
	FILE *inp;
	FILE *outp;
	inp=fopen("input_date.txt","r");
	outp=fopen("new_date.txt","w");
	while(feof(inp) == 0){
		int i, flag = 1;
		for(i = 0; i < 15; i++) date[i] = '\0'; //Initialization
		/*Read the input_date.txt line by line */
		for(i = 0; flag == 1 && feof(inp) == 0; i++) {
            fscanf(inp, "%c", &(date[i])); 
            /*Check the newline for read the next line*/
              if (date[i] == '\n')
            {
             	flag = 0;
    		}
        }
         date[i-1]='\0';
         sscanf(date,"%d/%d/%d",&date_day, &date_month, &date_year);
        /*Zellers formula is find the day of week for given date*/
         if(date_year%400 ==0 || (date_year%100 != 0 && date_year%4 == 0)){
         	leap_year=1;
         }
         else
         	leap_year=0;
         temp=3+ (2-leap_year)*((date_month+2)/(2*date_month))+(5 * date_month + date_month / 9) / 2;
         temp=temp%7;
         yy=date_year%100;
         century=date_year/100;
         day_of_week=1.25 * yy + temp + date_day - 2 * (century % 4);
         day_of_week=day_of_week%7;
         /*Write the day of given date to new_date.txt file */
         switch (day_of_week) {
      	case 0:
      	fprintf(outp, "%s,",day1);
         break;
      	case 1:
      	fprintf(outp, "%s,",day2);
         break;
      	case 2:
      	fprintf(outp, "%s,",day3);
         break;
     	 case 3:
     	 fprintf(outp, "%s,",day4);
         break;
      	case 4:
      	fprintf(outp, "%s,",day5);
         break;
      	case 5:
      	fprintf(outp, "%s,",day6);
         break;
      	case 6:
      	fprintf(outp, "%s,",day7);
         break;
  		 }
  		 /*Write the month of given date to new_date.txt file */
  		switch (date_month) {
      	case 1:
      	fprintf(outp, "%s",month1);
         break;
      	case 2:
      	fprintf(outp, "%s",month2);
         break;
      	case 3:
      	fprintf(outp, "%s",month3);
         break;
     	 case 4:
     	 fprintf(outp, "%s",month4);
         break;
      	case 5:
      	fprintf(outp, "%s",month5);
         break;
      	case 6:
      	fprintf(outp, "%s",month6);
         break;
      	case 7:
      	fprintf(outp, "%s",month7);
         break;
         case 8:
         fprintf(outp, "%s",month8);
         break;
         case 9:
         fprintf(outp, "%s",month9);
         break;
  		 case 10:
  		 fprintf(outp, "%s",month10);
         break;
         case 11:
         fprintf(outp, "%s",month11);
         break;
         case 12:
         fprintf(outp, "%s",month12);
         break;
     	}
      /*Write the dates to new_date.txt file */
        if(flag==0)
		  	fprintf(outp, ",%d,%d\n",date_day,date_year);
		else
			fprintf(outp, ",%d,%d",date_day,date_year);
	}
	fclose(outp);
}
