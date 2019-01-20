#include <stdio.h>
void encrypt_open_msg();
void decrypt_secret_msg();
void reverse_line(char line[], int line_lenght);
/*Menu function will display until user enters 0 */
void menu()
{
	int choice;
	do
	{
		printf("1.Encrypt \n2.Decrypt \n0.Exit\nChoice: \n");
		scanf("%d",&choice);
		if (!(choice == 0 || choice == 1 || choice == 2))
		{
			printf("1.Encrypt \n2.Decrypt \n0.Exit\nChoice: \n");
			scanf("%d",&choice);
		}
		switch(choice){
			case 1:
				encrypt_open_msg();
				break;
			case 2:
				decrypt_secret_msg();
				break;
			case 0:
				break;
		}
	} while(choice!=0);
}
/*Find the size of a line */
int find_size_of_line(char line[])
{
	int i, size=0;
	for(i=0; line[i]!='\0'; i++)
	{
		size++;
	}
	return size;
}
/*That function reads content of open_msg.txt file
*encrypts it with key and reverse_line function
*then writes encrypted message to secret_msg.txt file */
void encrypt_open_msg()
{
	int  line_lenght=0, key=0, j=0, k=0;
	FILE *inp;
	FILE *outp;
	inp=fopen("open_msg.txt","r");
	outp=fopen("secret_msg.txt","w");
	char line[1024];
	printf("Enter a key value between 1-26 for encryption: \n");
	scanf("%d", &key);
	if(key<=0||key>26){
		printf("Key must be between 1 & 26\n");
		return;
	}
	/*Reading from open_msg.txt line by line */
	while(feof(inp) == 0){
		int i, flag = 1;
		for(i = 0; i < 1024; i++) line[i] = '\0'; //Initialization
		for(i = 0; flag == 1 && feof(inp) == 0; i++) {
            fscanf(inp, "%c", &(line[i]));
            /*Message contains only lowercase characters */
        	if( line[i]>=97 && line[i]<=122)
            {
            	if(line[i]-key<97)
            	{
            		line[i]=line[i]-key;
            		line[i]=line[i]+26;
            	}
            	else
            		line[i]=line[i]-key;
            }
            if(line[i]=='.')
            	line[i]='*';
            if(line[i]==' ')
            	line[i]='_';
            if (line[i] == '\n')
             	flag = 0;
        }
        line[i-1] = '\0';
        if(line[i-2]=='\r')
       	{
        	line[i-2]='\0';
        }
        line_lenght=find_size_of_line(line);
        /*After change the line with key then reverse it */
        reverse_line(line,line_lenght);
		printf("%s\n",line);
		/*Write the encrypted message to secret_msg.txt file */
		if(flag==0)
		  fprintf(outp, "%s\n", line);
		else
			fprintf(outp, "%s", line);
	}
	fclose(outp);
}
/*Same algorithm with encrypt_msg function
 *reads content of secret_msg.txt file
 *decrypts it with key and reverse_line function
 then writes decrypted message to open_msg.txt file*/
void decrypt_secret_msg()
{
	int line_lenght=0, key=0, j=0, k=0;
	FILE *inp;
	FILE *outp;
	inp=fopen("secret_msg.txt","r");
	outp=fopen("open_msg.txt","w");
	char line[1024];
	printf("Enter a key value between 1-26 for decryption: \n");
	scanf("%d", &key);
	if(key<=0||key>26){
		printf("Key must be between 1 & 26\n");
		return;
	}
	while(feof(inp) == 0){
		int i, flag = 1;
		for(i = 0; i < 1024; i++) line[i] = '\0'; //Initialization
		for(i = 0; flag == 1 && feof(inp) == 0; i++) {
            fscanf(inp, "%c", &(line[i])); 
        	if(line[i]>=97 && line[i]<=122)
            {
            	if(line[i]+key>122)
            	{
            		line[i]=line[i]+key;
            		line[i]=line[i]-26;
            	}
            	else
            		line[i]=line[i]+key;
            }
            if(line[i]=='*')
            	line[i]='.';
            if(line[i]=='_')
            	line[i]=' ';
            if (line[i] == '\n')
             	flag = 0;
        }
        line[i-1] = '\0';
        if(line[i-2]=='\r')
       	{
       		line[i-2]='\0';
        }
        line_lenght=find_size_of_line(line);
        reverse_line(line,line_lenght);
		printf("%s\n",line);
		if(flag==0)
		fprintf(outp, "%s\n", line);
		else
			fprintf(outp, "%s", line);
	}
	fclose(outp);
}
/*Find the reverse of a line */
void reverse_line(char line[], int line_lenght)
{
	int i=0, mid=0;
	char temp;
			mid=line_lenght/2;
			for (i= 0; i < mid; i++) {
        	temp = line[i];
        	line[i] = line[(line_lenght - 1) - i];
        	line[(line_lenght - 1) - i] = temp;
	}
}
void main()
{
	menu();
}
