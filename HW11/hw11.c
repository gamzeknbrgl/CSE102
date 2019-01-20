#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customers {
	char *name;
	char *surname;
	int age;
	char *gender;
	struct customers *next;
}customer;

typedef struct rooms {
    int number;
    int capacity;
    int floor;
    customer *c; // head for a partial customer list
    struct rooms *next;
}room;

void make_list_rooms(FILE *f, room *r);
void add_room_to_end(room *r, int room_number, int capacity, int floor);
void print_list (room *r);
void add_room_after_room_number (room *r, int room_no, int capacity, int floor, int add_room_no);
void get_by_floor(room *r, int floor_no);
void remove_room (room **r, int room_number);
void link_customers_to_room(room *r, FILE *fp);
void add_customer_to_end(room *r, int room_no, char *name, char *surname, char *gender, int age);
void show_vacancy(room *r);

int main(){

	FILE *inp_rooms;
	char s[100];
	char line[1000];
	int i=0;
	char *pch;
	inp_rooms=fopen("rooms.txt","r");
	room *root;
	root=(room*)malloc(sizeof(room));
    fscanf(inp_rooms,"%s",s);
    sscanf(s,"%d , %d, %d", &root->number, &root->capacity, &root->floor);
	root->next=NULL;
	FILE *inp_customers;
	inp_customers=fopen("customers.txt","r");
	make_list_rooms(inp_rooms,root);
	link_customers_to_room(root,inp_customers);
	fclose(inp_rooms);
	fclose(inp_customers);
	/*Test part */

	//remove_room (&root, 408);
	//add_room_to_end(root,115,5,6);
	//add_room_after_room_number (root, 101, 5, 6, 112);
	//get_by_floor(root, 4);
	//print_list(root);
	//add_customer_to_end(root, 101, "Gamze", "Kanburoglu", "Female", 20);
	//show_vacancy(root);


	return 0;
}

/*Reading from read.txt file line by line and 
* make a linked list for rooms */

void make_list_rooms(FILE *f, room *r){

	char s[100];
	char line[100];
	char name[100];
	char *pch;
	int i=0, number;
	room *iter;
	room *current;
   	iter=r;
    while(!feof(f)){

        iter->next=(room*)malloc(sizeof(room));
        iter=iter->next;
        fscanf(f,"%s",s);
        sscanf(s,"%d , %d, %d", &iter->number, &iter->capacity, &iter->floor);
         
    }
    iter->next=NULL;

}

/* add_room_to_end function insert a room to 
* the end of list if room number is available*/

void add_room_to_end(room *r, int room_number, int capacity, int floor){

	room *new;
	new=(room*)malloc(sizeof(room));
	room *current = r;
	new->number=room_number;
	new->capacity=capacity;
	new->floor=floor;
	new->next=NULL;
    while(current->next != NULL)
    {
    		if(new->number==current->number){
    			printf("Invalid room number\n");
    			return;
    		}
           current=current->next;
    }
        current->next=new;

}

/* print_list function: prints the room list with customers */

void print_list (room *r){

	room *current;
	current=r;
	while(current->next!=NULL){

       	printf("Room %d (Floor %d - capacity %dx): \n", current->number, current->floor, current->capacity); 
        current=current->next;
    }
    current->next=NULL;
	if(current->next==NULL){

		printf("Room %d (Floor %d - capacity %dx): \n", current->number, current->floor, current->capacity); 

	}
}

/* add_room_after_room_number function:
* room_no: given room number, add_room_no: new room's number 
* if given room does not exists, new room will be add end of the list */

void add_room_after_room_number (room *r, int room_no, int capacity, int floor, int add_room_no ){

	room *insert_room;
	int flag=0;
	insert_room=(room*)malloc(sizeof(room));
	insert_room->capacity=capacity;
	insert_room->floor=floor;
	insert_room->next=NULL;
	insert_room->number=add_room_no;
	room *temp=r;
	while(temp->next!=NULL){

		if(temp->number==room_no){
			insert_room->next=temp->next;
			temp->next=insert_room;
			break;
		}
		else{

			temp=temp->next;
		}

	}
	if(temp->next==NULL){
		if(temp->number==room_no){
			insert_room->next=temp->next;
			temp->next=insert_room;
			flag=1;
		}
	if(temp->next==NULL && flag==0){
		add_room_to_end(r,insert_room->number,insert_room->capacity,insert_room->floor);
	}
	}

}

/* get_by_floor function: lists the rooms with the given floor number */

void get_by_floor(room *r, int floor_no){

	room *temp=r;
	printf("Rooms in the floor - %d -:\n", floor_no);
	while(temp->next!=NULL){

		if(temp->floor==floor_no){
			
			printf("%d \n", temp->number);
		}
		temp=temp->next;

	}
	if(temp->next==NULL & temp->floor==floor_no){

		printf("%d\n",temp->number);
	}

}

/* remove_room function: removes the room indicated by the room_number */

void remove_room(room **r, int room_number){

	room *current=*r;
	room *temp=NULL;

	while(current->number!=room_number && current->next!=NULL){

		temp=current;
		current=current->next;
	}
	if(current->number==room_number){

		if(temp){
			
			temp->next=current->next;
		}

		else{

			*r=current->next;
		}
	}


}

/*link_customers_to_room function: That function
*reads customers.txt file line by line, after reading a line and
*get the customer's room number, check the entirely linked list for rooms
*if room number's are the same, make a customer linked list for that room.
*But it doesn't work completely, it only works for first( 101. )room */

void link_customers_to_room(room *r, FILE *fp){

	room *current;
	customer *temp;
	current=r;
	char *pch, *pch2;
	char name[100];
	int number, i=0;
	char line[100];

	while(!feof(fp)){

			fgets(line, sizeof(line),fp);
			sscanf(line,"%d, %199c",&number,name);
			while(current->next!=NULL){
		
			if(current->number==number){
			if(current->c==NULL){

				current->c=(customer*)malloc(sizeof(customer));
				pch=strtok(name," ,");
				while(pch!=NULL){
				if(i==0){

					current->c->name=pch;
				}
				if(i==1){

					current->c->surname=pch;
	
				}
				if(i==2){

					current->c->age=atoi(pch);
					
				}
				if(i==3){

				current->c->gender=pch;
				}
				pch=strtok(NULL, " ,");
				i++;
				}
				current->c->next=NULL;
				temp=current->c;	
			}

			else{

			pch2=strtok(name," ,");
			temp->next=(customer*)malloc(sizeof(customer));
			temp=temp->next;
			while(pch2!=NULL){
	
			if(i==0){

				temp->name=pch2;
			}
			if(i==1){

				temp->surname=pch2;
	
			}
			if(i==2){

				temp->age=atoi(pch2);
				
			}
			if(i==3){

				temp->gender=pch2;
			}
			pch2=strtok(NULL, " ,");
			i++;
			}
			
		}
		temp->next=NULL;
	}	
	current=current->next;
	}
}
}

/* add_customer_to_end function: adds a customer to 
*the end of the partial customer list.*/

void add_customer_to_end(room *r, int room_no, char *name, char *surname, char *gender, int age){

	customer *new;
	new=(customer*)malloc(sizeof(customer));
	room *current = r;
	customer *temp;
	
    while(current->next != NULL)
    {
    		if(current->number==room_no){
    			
    			if(current->c==NULL){

    				current->c=(customer*)malloc(sizeof(customer));
    				current->c->name=name;
    				current->c->surname=surname;
    				current->c->gender=gender;
    				current->c->age=age;
    				current->c->next=NULL;

    			}
    			else{

    				temp=current->c;
    				while(temp->next!=NULL){
    				new=current->c;
    				new->name=name;
    				new->surname=surname;
    				new->gender=gender;
    				new->age=age;
    				new->next=NULL;
    			}
    			temp->next=new;
    			}

    		}

           current=current->next;
    }

}

/*show_vacancy function: list all available rooms that don’t have any customer.
*In this function only 101. room isn't show because customers linked list is only 
*works with 101. room*/
void show_vacancy(room *r){

	room *current;
	current=r;
	printf("Available rooms that don’t have any customer: \n");
	while(current->next!=NULL){

		if(current->c==NULL){

			printf("%d \n", current->number );
		}

		current=current->next;
	}
	if(current->next==NULL){

			if(current->c==NULL){

			printf("%d \n", current->number );
		}
	}

}
