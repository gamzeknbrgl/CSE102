#include <stdio.h>
#include <time.h>
#include<stdlib.h>
typedef enum {M='M',T='T',P='P',B='B',S='S',N='N'}block_type; /*N represents normal blocks */
typedef struct{
    int data;
    char *text;
    int pos_x;
    int pos_y;
    int jump_x;
    int jump_y;
    block_type type;
}block;
void init_board(block board[10][10]);
void display_board(block board[10][10]);
int single_pgame(block board[10][10],int pos_x,int pos_y,int move);
void two_pgame();
int main()
{
    int result, move=0;
    srand(time(NULL));
    block board[10][10];
    init_board(board);
    display_board(board);
    //two_pgame();
    result=single_pgame(board,9,9,move);
}
/*Board initialization with block struct */
void init_board(block board[10][10])
{
    int i;
    int data1=91, data2=90, data3=71, data4=70, data5=51, data6=50, data7=31, data8=30, data9=11, data10=10;
    for(i=0; i<10; i++){
        board[0][i].data=data1;
        board[0][i].text=NULL;
        board[0][i].pos_x=0;
        board[0][i].pos_y=i;
        board[0][i].type=N;
        if(i==2){
            board[0][i].type=T;
            board[0][i].text="T";
            board[0][i].jump_x=1;
            board[0][i].jump_y=2;
        }
        if(i==7){
            board[0][i].type=S;
            board[0][i].text="S{72}";
            board[0][i].jump_x=2;
            board[0][i].jump_y=1;
        }
        if(i==8){
            board[0][i].text="S{56}";
            board[0][i].jump_x=4;
            board[0][i].jump_y=5;
            board[0][i].type=S;
        }
        if(i==9){
            board[0][i].text="100(Finish)";
        }
        data1++;
    }
    for(i=0; i<10;i++){
        board[1][i].data=data2;
        board[1][i].text=NULL;
        board[1][i].pos_x=1;
        board[1][i].pos_y=i;
        board[0][i].type=N;
        if(i==1){
            board[1][i].text="M{94}";
            board[1][i].jump_x=0;
            board[1][i].jump_y=3;
            board[1][i].type=M;
        }
        if(i==5){
            board[1][i].text="P";
            board[1][i].jump_x=1;
            board[1][i].jump_y=5;
            board[1][i].type=P;
        }
        if(i==8){
            board[1][i].text="B";;
            board[1][i].jump_x=2;
            board[1][i].jump_y=0;
            board[1][i].type=B;
        }
        data2--;
    }
    for(i=0; i<10; i++){
        board[2][i].data=data3;
        board[2][i].text=NULL;
        board[2][i].pos_x=2;
        board[2][i].pos_y=i;
        board[0][i].type=N;
        if(i==2){
            board[2][i].text="S{68}";
            board[2][i].jump_x=3;
            board[2][i].jump_y=2;
            board[2][i].type=S;
        }
        if(i==5){
            board[2][i].text="M{83}";
            board[2][i].jump_x=1;
            board[2][i].jump_y=7;
            board[2][i].type=M;
        }
        if(i==8){
            board[2][i].text="T";
            board[2][i].jump_x=2;
            board[2][i].jump_y=3;
            board[2][i].type=T;
        }

        data3++;
    }
    for(i=0; i<10; i++){
        board[3][i].data=data4;
        board[3][i].text=NULL;
        board[3][i].pos_x=3;
        board[3][i].pos_y=i;
        board[3][i].type=N;
        if(i==1){
            board[3][i].text="M{77}";
            board[3][i].jump_x=2;
            board[3][i].jump_y=6;
            board[3][i].type=M;
        }
        if(i==4){
            board[3][i].text="B";
            board[3][i].jump_x=2;
            board[3][i].jump_y=0;
            board[3][i].type=B;
        }
        if(i==7){
            board[3][i].text="S{52}";
            board[3][i].jump_x=4;
            board[3][i].jump_y=1;
            board[3][i].type=S;
        }
        data4--;
    }
    for(i=0; i<10; i++){
        board[4][i].data=data5;
        board[4][i].text=NULL;
        board[4][i].pos_x=4;
        board[4][i].pos_y=i;
        board[0][i].type=N;
        if(i==3){
            board[4][i].text="T";
            board[4][i].jump_x=5;
            board[4][i].jump_y=1;
            board[4][i].type=T;
        }
        if(i==6){
            board[4][i].text="M{77}";
            board[4][i].jump_x=2;
            board[4][i].jump_y=6;
            board[4][i].type=M;
        }
        if(i==9){
            board[4][i].text="S{44}";
            board[4][i].jump_x=5;
            board[4][i].jump_y=6;
            board[4][i].type=S;

        }
        data5++;
    }
    for(i=0; i<10; i++){
        board[5][i].data=data6;
        board[5][i].text=NULL;
        board[5][i].pos_x=5;
        board[5][i].pos_y=i;
        board[0][i].type=N;
        if(i==0){
            board[5][i].text="B";
            board[5][i].jump_x=4;
            board[5][i].jump_y=4;
            board[5][i].type=B;
        }
        if(i==2){
            board[5][i].text="P";
            board[5][i].jump_x=5;
            board[5][i].jump_y=2;
            board[5][i].type=P;
        }
        if(i==5){
            board[5][i].text="S{22}";
            board[5][i].jump_x=7;
            board[5][i].jump_y=8;
            board[5][i].type=S;
        }
        data6--;
    }
    for(i=0; i<10; i++){
        board[6][i].data=data7;
        board[6][i].text=NULL;
        board[6][i].pos_x=6;
        board[6][i].pos_y=i;
        board[6][i].type=N;
        if(i==1){
            board[6][i].text="M{52}";
            board[6][i].jump_x=4;
            board[6][i].jump_y=1;
            board[6][i].type=M;
        }
        if(i==5){
            board[6][i].text="B";
            board[6][i].jump_x=5;
            board[6][i].jump_y=9;
            board[6][i].type=B;
        }
        if(i==9){
            board[6][i].text="T";
            board[6][i].jump_x=6;
            board[6][i].jump_y=4;
            board[6][i].type=T;

        }
        data7++;
    }
    for(i=0; i<10; i++){
        board[7][i].data=data8;
        board[7][i].text=NULL;
        board[7][i].pos_x=7;
        board[7][i].pos_y=i;
        board[7][i].type=N;
        if(i==1){
            board[7][i].text="B";
            board[7][i].jump_x=6;
            board[7][i].jump_y=3;
            board[7][i].type=B;
        }
        if(i==5){
            board[7][i].text="S{12}";
            board[7][i].jump_x=8;
            board[7][i].jump_y=1;
            board[7][i].type=S;
        }
        data8--;
    }
    for(i=0; i<10; i++){
        board[8][i].data=data9;
        board[8][i].text=NULL;
        board[8][i].pos_x=8;
        board[8][i].pos_y=i;
        board[8][i].type=N;
        if(i==2){
            board[8][i].text="P";
            board[8][i].jump_x=8;
            board[8][i].jump_y=2;
            board[8][i].type=P;
        }
        if(i==6){
            board[8][i].text="M{28}";
            board[8][i].jump_x=7;
            board[8][i].jump_y=2;
            board[8][i].type=M;
        }
        data9++;
    }
    for(i=0; i<10; i++){
        board[9][i].data=data10;
        board[9][i].text=NULL;
        board[9][i].pos_x=9;
        board[9][i].pos_y=i;
        board[9][i].type=N;
        if(i==3){
            board[9][i].text="M{11}";
            board[9][i].jump_x=8;
            board[9][i].jump_y=0;
            board[9][i].type=M;
        }
        if(i==4){
            board[9][i].text="S{1}";
            board[9][i].jump_x=9;
            board[9][i].jump_y=9;
            board[9][i].type=S;
        }
        if(i==9){
            board[9][i].text="1(Start)";
        }
        data10--;
    }

}
/*Display the board*/
void display_board(block board[10][10]){
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(board[i][j].text==NULL){
                printf("%d ", board[i][j].data);
            }
            else
                printf("%s ", board[i][j].text);
        }
        printf("\n");
    }
}
/*Single game function. Game will end if player reaches the block 100.
 * Function returns the move counts */
int single_pgame(block board[10][10],int pos_x,int pos_y,int move){
    /*Dice rolling*/
    int direction=rand()%6+1;
    int temp_x, temp_y;
        if (pos_x % 2 != 0) {
            /*If row changes after the move*/
            if (pos_y - direction < 0) {
                pos_y = (direction - pos_y) - 1;
                pos_x = pos_x - 1;
            }
            else { /*Row isn't change after the move */
                pos_y = pos_y - direction;
            }
            /*If block type isn't normal block */
           if (board[pos_x][pos_y].type == B || board[pos_x][pos_y].type == M ||
               board[pos_x][pos_y].type == P || board[pos_x][pos_y].type == S ||
               board[pos_x][pos_y].type == T) {
               temp_x = board[pos_x][pos_y].jump_x;
               temp_y = board[pos_x][pos_y].jump_y;
               pos_x = temp_x;
               pos_y = temp_y;
           }
        }
       else if (pos_x % 2 == 0) {
            if (direction + pos_y > 9) {
                if(pos_x!=0) {
                   pos_y = 9 - ((pos_y + direction) % 10);
                   pos_x = pos_x - 1;
               }
                /*If move overshoots the block 100, pos_x pos_y won't change and dice will roll again*/
                if(pos_x==0 && board[pos_x][pos_y].data+direction>100 ){
                    pos_y=pos_y+direction-direction;
                }
             }
            else {
                pos_y = pos_y + direction;
            }
            if (board[pos_x][pos_y].type == B || board[pos_x][pos_y].type == M ||
                board[pos_x][pos_y].type == P || board[pos_x][pos_y].type == S ||
                board[pos_x][pos_y].type == T) {
                temp_x = board[pos_x][pos_y].jump_x;
                temp_y = board[pos_x][pos_y].jump_y;
                pos_y = temp_y;
                pos_x = temp_x;
            }
        }
        /*Function call itself if data isn't 100 and increase the move counts */
         if (board[pos_x][pos_y].data != 100) {
            move=single_pgame(board, pos_x, pos_y,move+1);
        }
        printf("dice was:%d, pos_x :%d, pos_y:%d, data: %d\n", direction, pos_x, pos_y,board[pos_x][pos_y].data);
    return move;
}
/* Two players play the game
 * that function compares move counts
 * and prints which player won the game*/
void two_pgame(){
    block board2[10][10];
    init_board(board2);
    int player1=0, player2=0, move1=0, move2=0;
    printf("\nPLAYER 1: \n");
    player1=single_pgame(board2,9,9,move1);
    printf("\nPLAYER 2: \n");
    player2=single_pgame(board2,9,9,move2);
    printf("Player 1 complete game in :%d moves  \n", player1);
    printf("Player 2 complete game in :%d moves  \n", player2);
    if(player1>player2){
        printf("Winner is player 2 \n");
    }
    else if(player1<player2){
        printf("Winner is player 1 \n");
    }
    else
        printf("No winner \n");

}
