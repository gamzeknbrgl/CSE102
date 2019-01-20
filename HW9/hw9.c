#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int width;
    int height;
    char **map;
    int flower_x;
    int flower_y;
}Forest;

typedef struct{
    int coord_x;
    int coord_y;
    int water_bootle_size;
}Botanist;

/*Init the forest& botanist objects from "init.csv" file
 *after the second line parse the lines and fill the map array */
void init_game(Forest *forest, Botanist *botanist){
    FILE *inp;
    char s[5];
    char temp;
    int i,j;
    char buffer[1024];
    inp=fopen("init.csv","r");
    fscanf(inp,"%d", &botanist->water_bootle_size);
    fscanf(inp,"%s",s);
    sscanf(s,"%d , %d", &forest->width, &forest->height);
    int *p;
    p =(int*)malloc((forest->width) * (forest->height )* sizeof(int));
    forest->map = (char **)malloc(forest->height*sizeof(char*));
    for(i = 0; i < forest->height; i++){
        forest->map[i] = (char *)malloc(forest->width*sizeof(char));
    }
    /*From third line to end line parse the lines */
    fgets(buffer, sizeof(buffer),inp);
    char * token;
    for(i = 0; i < forest->height && !feof(inp); i++) {
        fgets(buffer, sizeof(buffer),inp);
        for (j = 0; j < forest->width; ++j) {
            if (j == 0) token = strtok(buffer, ",");
            else token = strtok(NULL, ",");
            forest->map[i][j] = *token;
            if(forest->map[i][j]=='B'){
                botanist->coord_x=i;
                botanist->coord_y=j;
            }
            if(forest->map[i][j]=='F'){
                forest->flower_x=i;
                forest->flower_y=j;
            }
        }
    }
    fclose(inp);
}
/*Print the map */
void print_map (Forest *forest){
    int i,j;
    for(i=0; i<forest->width; i++){
        for(j=0; j<forest->height; j++){
            printf("%c ", forest->map[i][j]);

        }
        printf("\n");
    }
}
/*Search the flower in map, decrease the water if move allowed 
 *water won't change if botanist's move not allowed
 *search the flower until the water runs out recursively.  */
void search (Forest *forest, Botanist *botanist, int pos_x, int pos_y, int water){
    /*Determine the botanist's move randomly */
    int direction=rand()%4+1;
    int temp=water;
    int temp_posx=pos_x;
    int temp_posy=pos_y;
    /*If you want to see botanist's moves, water and direction */
    //printf("pos_x: %d pos_y: %d \n", pos_x, pos_y);
    //printf("direction= %d\n",direction);
    //printf("bootle size: %d\n", water);
    if(forest->map[pos_x][pos_y]=='F'){
        forest->map[botanist->coord_x][botanist->coord_y]=' ';
        forest->map[pos_x][pos_y]='F';
        print_map(forest);
        printf("I have found it on (%d,%d)!\n" ,forest->flower_x, forest->flower_y);
        return;
    }

    if(pos_x>=0 && pos_x<forest->width && pos_y>=0 && pos_y<forest->height){
    if(direction==1 && forest->map[pos_x][pos_y]!='#')
    {
        if(pos_x-1>=0 && forest->map[pos_x-1][pos_y]!='#'){
                pos_x=pos_x-1;              /*up*/
                water--;
        }
    }
    else if(direction==2 && forest->map[pos_x][pos_y]!='#')
    {
        if(pos_x+1<forest->width && forest->map[pos_x+1][pos_y]!='#'){
            pos_x=pos_x+1;                 /*down*/
            water--;
        }
        
    }
    else if(direction==3 && forest->map[pos_x][pos_y]!='#'){

        if(pos_y-1>=0 && forest->map[pos_x][pos_y-1]!='#'){
            pos_y=pos_y-1;                 /*left*/
            water--;
        }

    }
    else if(direction==4 && forest->map[pos_x][pos_y]!='#'){

        if(pos_y+1<forest->height && forest->map[pos_x][pos_y+1]!='#'){
            pos_y=pos_y+1;                /*right*/
            water--;
        }
    
    }
    /*Searching flower until the water runs out */
    if(!(water==0 && forest->map[pos_x][pos_y]!='F' ))
    {
        search(forest,botanist,pos_x,pos_y,water);
    }
    /*If water runs out & flower not found */
    if(water==0 && forest->map[pos_x][pos_y]!='F' ){
        forest->map[botanist->coord_x][botanist->coord_y]=' ';
        forest->map[temp_posx][temp_posy]='B';
        print_map(forest);
        printf("Help! I am on (%d,%d) \n",temp_posx, temp_posy);
        return;
    }
    /*If botanist find the flower */
  
    }

}

int main(){
    srand(time(NULL));
    Forest *f;
    Botanist *b;
    int i, j;
    /*Allocate memory with malloc */
    f = (Forest*)malloc(sizeof(Forest));
    b = (Botanist*)malloc(sizeof(Botanist));
    init_game(f, b);
    print_map(f);
    printf("Searching... \n");
    search(f,b,b->coord_x, b->coord_y,b->water_bootle_size);
    free(f);
    free(b);
    return 0;
}
