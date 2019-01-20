#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node1 {
    int x;
    struct node1 *next;
}node;

void find_times_list(node *r, int a,int b, FILE *outp);
void find_times_array(int arr[], int a, int b, FILE *outp);

//part 1
/*data.txt dosyasindan sayilarin satir satir okunmasi */
int get_lines(FILE *f){
    char line[1024];
        int i, flag = 1, j=0;
        int number;
        for (i = 0; i < 1024; i++) line[i] = '\0'; 
        for (i = 0; flag == 1 && feof(f) == 0; i++) {
            fscanf(f, "%c", &(line[i]));
            sscanf (line, "%d", &number);
            if (line[i] == '\n')
              flag = 0;
      }
            return number;

    fclose(f);
}

/*Asal sayilarin bulunmasi */
int prime(int num){
  int j, counter=0;
  if(num==1 ){
    return 0;
  }
  for(j=2;j<num;j++)
     {
       if(num%j==0  )
       {
          return 0;
        }
      }
   return 1;

}
//part 2.a
/*Dosyadaki tüm sayilarin linked list'in icine atilip
* linked listin elemanlarini tek tek dolasip
* asal sayilarin bulunmasi ve output_prime_linkedlist.txt
*dosyasinin icine yazdirilmasi.*/
void find_primes_with_linkedlist(FILE *f, node *r, FILE *outp2){

    int i=0, j, counter;
    node *iter;
    clock_t start,end;
    double time;
    node *current;
    iter=r;
    while(!feof(f)){
        iter->next=(node*)malloc(sizeof(node));
        iter=iter->next;
        iter->x=get_lines(f);  
        i++;
    }
    iter->next=NULL;
    current=r;
    while(current->next!=NULL){

       if(prime(current->x)==1)
        {
        	/*Asal sayilarin dosyaya yazdirma ve yazdirma suresini hesaplama*/
        	// part 4
        	start=clock();
        	fprintf(outp2, "%d \n",current->x);
        	end=clock();
    
       }
       	 time=(double)(end-start)*1000.0/CLOCKS_PER_SEC;
         current=current->next;
    }
    current->next=NULL;
    fprintf(outp2, "%lf \n",time);

}

//part 2.b
/*Dinamik array'in icine dosyanin icindeki tum satirlarin
* eleman olarak atilip, iclerinden asal sayilarin 
* output_prime_dynamic_array.txt dosyasina yazdirilmasi */
void find_primes_with_array(FILE *f, int arr[], FILE *outp){

    int add;
    clock_t start, end;
    double time;
    int i=0,j, counter;
    while(!feof(f)){
      add=get_lines(f);
      arr[i]=add;
      i++;
    }
    for(i=0; i<1000000; i++){

            if(prime(arr[i])==1)
            {
            	/*Asal sayilarin dosyaya yazdirma ve yazdirma suresini hesaplama*/
            	start=clock();
            	fprintf(outp, "%d \n",arr[i]);
            	end=clock();
         
            }
            time=(double)(end-start)*1000.0/CLOCKS_PER_SEC;
    }
    fprintf(outp, "%lf \n",time);
}

//part 3.1, 3.2 3.3 linked list icin 
/* Linked list icin girilen belli bir a-b araliginda
* asal sayilarin ne kadar sürede bulundugunu hesaplayan
* ve sonucu output_prime_LinkedList.txt'ye yazdiran fonksiyon*/
void find_times_list(node *r, int a, int b, FILE *outp){

  node *curr;
  curr=r;
  double list_time;
  clock_t start,end;
  int i;
  start=clock();
  	for(i=a; i<=b; i++){
  		if(curr->x == b){
			break;
		}
		else{
		    prime(curr->x);
    		curr=curr->next;	
		}
  }
  end=clock();
  list_time=(double)(end-start)*1000.0/CLOCKS_PER_SEC;
  //printf("time: %lf \n", list_time);
  fprintf(outp, "%lf \n",list_time);
}

//part 3.1, 3.2 3.3 dinamik array icin
/* Dinamik array icin girilen belli bir a-b araliginda
* asal sayilarin ne kadar sürede bulundugunu hesaplayan
* ve sonucu output_prime_dynamic_array.txt'ye yazdiran fonksiyon*/
void find_times_array(int arr[], int a, int b, FILE *outp){

  int i;
  clock_t start,end;
  double array_time;
  start=clock();
  for(i=a; i<b; i++){
    prime(arr[i]);
  }
  end=clock();
  array_time=(double)(end-start)*1000.0/CLOCKS_PER_SEC;
  fprintf(outp, "%lf \n",array_time);

}

int main() {

    node *root;
    node *temp;
    root=(node*)malloc(sizeof(node));
    FILE *inp;
    FILE *outp;
    FILE *outp2;
    inp=fopen("data.txt","r");
    root->x=get_lines(inp);
    outp2=fopen("output_prime_LinkedList.txt","w");
    find_primes_with_linkedlist(inp,root,outp2);
    find_times_list(root, 1,500000,outp2);
    find_times_list(root, 1,750000,outp2);
    find_times_list(root, 1,1000000,outp2);
    fclose(outp2);
    root->next=NULL;
    fclose(inp);


    inp=fopen("data.txt","r");
    outp=fopen("output_prime_dynamic_array.txt","w");
    int *arr;
    arr=(int*)calloc(1000000, sizeof(int));
    find_primes_with_array(inp,arr,outp);
    find_times_array(arr,1,500000,outp);
    find_times_array(arr,1,750000,outp);
    find_times_array(arr,1,1000000,outp);
    fclose(inp);
    fclose(outp);
    free(arr);

    while(root!=NULL){
    	temp=root;
    	root=root->next;
    	free(temp);
    }

    return 0;

}
