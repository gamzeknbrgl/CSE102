#include <stdio.h>
typedef enum{white_man='w', black_man='b', white_king='W', black_king='B', empty='-'}piece;
typedef enum{white=10, black=20} player;
void init_board(piece board[][8]);
void display_board(piece board[][8]);
int check_end_of_game(piece board[][8]);
void sample_game_1();
void sample_game_2();
void main()
{
    piece board[8][8];
    init_board(board);
    sample_game_1();
    sample_game_2();
}
/* initialize the board */
void init_board(piece board[][8])
{
    int i;
    for(i=0; i<8; i++)
    {
        board[0][i]=empty;
    }
    for(i=0; i<8; i++)
    {
        board[1][i]=black_man;
    }
    for(i=0; i<8; i++)
    {
        board[2][i]=black_man;
    }
    for(i=0; i<8; i++)
    {
        board[3][i]=empty;
    }
    for(i=0; i<8; i++)
    {
        board[4][i]=empty;
    }
    for(i=0; i<8; i++)
    {
        board[5][i]=white_man;
    }
    for(i=0; i<8; i++)
    {
        board[6][i]=white_man;
    }
    for(i=0; i<8; i++)
    {
        board[7][i]=empty;
    }
    display_board(board);
}
/*In move function if a piece is black or white man, maximum capture compulsory works with recursion
 * but if a black or white man becomes a king, then it doesn't work with recursion
 * it only works with manuel directions */
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p) {
    int i, white_capture = 0, black_capture = 0, j=0;
    if (p == white ) {
        if (board[to_x][to_y] == empty && board[from_x][from_y]==white_man ) {
        		/*If white man tries to go backwards */
                if(to_x>from_x){
                return -2;
                }
                if (to_x == from_x - 1 && to_y == from_y || to_x == from_x && to_y == from_y + 1 ||
                    to_x == from_x & to_y == from_y - 1) {
                    if(to_x==0) {
                        board[to_x][to_y]=white_king;
                    }
                    else {
                        board[to_x][to_y] = white_man;
                    }
                    board[from_x][from_y] = empty;
                    return 0;
                }
                if ((board[from_x - 1][from_y] == black_man || board[from_x - 1][from_y] == black_king) &&
                    board[from_x - 2][from_y] == empty) {
                    board[from_x - 1][from_y] = empty;
                    black_capture++;
                    to_x = from_x - 2;
                    to_y = from_y;
                    if(to_x==0) {
                        board[to_x][to_y]=white_king;
                    }
                    else {
                        board[to_x][to_y] = white_man;
                    }
                    board[from_x][from_y] = empty;
                    from_x= to_x;
                 
                } else if ((board[from_x][from_y - 1] == black_man || board[from_x][from_y - 1] == black_king) &&
                           board[from_x][from_y - 2] == empty) {
                    board[from_x][from_y - 1] = empty;
                    black_capture++;
                    to_x = from_x;
                    to_y = from_y - 2;
                    if(to_x==0)
                    {
                        board[to_x][to_y]=white_king;
                    }
                    else {
                        board[to_x][to_y] = white_man;
                    }
                    board[from_x][from_y] = empty;
                    from_y=to_y;
             
                } else if ((board[from_x][from_y + 1] == black_man || board[from_x][from_y + 1] == black_king) &&
                           board[from_x][from_y + 2] == empty) {
                    board[from_x][from_y + 1] = empty;
                    to_x = from_x;
                    to_y = from_y + 2;
                    if(to_x==0)
                    {
                        board[to_x][to_y]=white_king;
                    }
                    else {
                        board[to_x][to_y] = white_man;
                    }
                    board[from_x][from_y] = empty;
                    from_y=to_y;
                 
                }
                move(board,to_x,to_y,to_x-2,to_y,white);
                move(board,to_x,to_y,to_x,to_y-2,white);
                move(board,to_x,to_y,to_x,to_y+2,white);
                return black_capture;
                
            
        }
      /*if (board[to_x][to_y] == empty && board[from_x][from_y]==white_king ){
            while (check_end_of_game(board)==-1) {
                        if((board[to_x+1][to_y]==black_man || board[to_x+1][to_y]== black_king) && board[to_x][to_y]==empty)
                        {
                            black_capture++;
                            board[to_x][to_y]=white_king;
                            board[from_x][from_y]=empty;
                            board[to_x+1][to_y]=empty;
                            from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==black_man || board[to_x][i]==black_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[to_x][i]==black_man || board[to_x][i]==black_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_y=to_y;
                                    from_x=to_x;
                                    black_capture++;
                                }
                            }
                            
                        }
                        else if((board[to_x-1][to_y]==black_man || board[to_x-1][to_y]== black_king) && board[to_x][to_y]==empty){
                            black_capture++;
                            board[to_x-1][to_y]=empty;
                            board[to_x][to_y]=white_king;
                            board[from_x][from_y]=empty;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==black_man || board[to_x][i]==black_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[to_x][i]==black_man || board[to_x][i]==black_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                     from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                     from_y=to_y;
                                    black_capture++;
                                }
                            }
                        }
                        else if((board[to_x][to_y+1]==black_man || board[to_x][to_y+1]== black_king) && board[to_x][to_y]==empty){
                            black_capture++;
                            board[to_x][to_y+1]=empty;
                            board[to_x][to_y]=white_king;
                            board[from_x][from_y]=empty;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==black_man || board[to_x][i]==black_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[to_x][i]==black_man || board[to_x][i]==black_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                     from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man|| board[i][to_y]==black_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                     from_y=to_y;
                                    black_capture++;
                                }
                            }

                        }
                        else if((board[to_x][to_y-1]==black_man || board[to_x][to_y-1]== black_king) && board[to_x][to_y]==empty)
                        {
                            black_capture++;
                            board[to_x][to_y-1]=empty;
                            board[to_x][to_y]=white_king;
                            board[from_x][from_y]=empty;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==black_man || board[to_x][i]==black_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[to_x][i]==black_man || board[to_x][i]==black_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=white_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                                else if((board[i][to_y]==black_man || board[i][to_y]==black_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=white_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    black_capture++;
                                }
                            }
                        }
                         else{
                           board[to_x][to_y]=white_king;
                           board[from_x][from_y]=empty;
                            break;
                        }
                        
                    }
               

            }*/
        if(board[from_x][from_y]==black_man || board[from_x][from_y]==black_king)
            return -1;
        if(to_x<0 || to_y<0 || from_x<0 || from_y<0 || to_x>7 || to_y>7 || from_x>7 || from_y>7)
            return -2;

    }
    if (p == black ) {
        if (board[to_x][to_y] == empty  && board[from_x][from_y]==black_man ) {
        		/*If black man tries to go backwards */
                 if(to_x<from_x){
                     return -2;
                }

                if (to_x == from_x + 1 && to_y == from_y || to_x == from_x && to_y == from_y + 1 ||
                    to_x == from_x & to_y == from_y - 1 )  {
                    if(to_x==7) {
                        board[to_x][to_y]=black_king;
                    }
                    else {
                        board[to_x][to_y] = black_man;
                    }
                    board[from_x][from_y] = empty;
                   return 0;
                }
                if ((board[from_x + 1][from_y] == white_man || board[from_x + 1][from_y] == white_king) &&
                    board[from_x + 2][from_y] == empty) {
                    white_capture++;
                    board[from_x + 1][from_y] = empty;
                    to_x = from_x + 2;
                    to_y = from_y;
                    if(to_x==7) {
                        board[to_x][to_y]=black_king;
                    }
                    else{
                        board[to_x][to_y] = black_man;
                    }
                    board[from_x][from_y] = empty;
            
                } else if ((board[from_x][from_y - 1] == white_man || board[from_x][from_y - 1] == white_king) &&
                           board[from_x][from_y - 2] == empty) {
                    white_capture++;
                    board[from_x][from_y - 1] = empty;
                    to_x = from_x;
                    to_y = from_y - 2;
                    if(to_x==7) {
                        board[to_x][to_y]=black_king;
                    }
                    else{
                        board[to_x][to_y] = black_man;
                    }
                    board[from_x][from_y] = empty;
                    
                } else if ((board[from_x][from_y + 1] == white_man || board[from_x][from_y + 1] == white_king) &&
                           board[from_x][from_y + 2] == empty) {
                    white_capture++;
                    board[from_x][from_y + 1] = empty;
                    to_x = from_x;
                    to_y = from_y + 2;
                    if(to_x==7) {
                        board[to_x][to_y]=black_king;
                    }
                    else{
                        board[to_x][to_y] = black_man;
                    }
                    board[from_x][from_y] = empty;
                }
              		/*Maximum capture compulsory part with recursion */
                    move(board,to_x,to_y,to_x+2,to_y,black);
                    move(board,to_x,to_y,to_x,to_y-2,black);
                    move(board,to_x,to_y,to_x,to_y+2,black);
                    return white_capture;
            
        }
       /* if (board[to_x][to_y] == empty && board[from_x][from_y]==black_king ){
            while (check_end_of_game(board)==-1) {
                        if((board[to_x+1][to_y]==white_man || board[to_x+1][to_y]== white_king) && board[to_x][to_y]==empty )
                        {
                         
                            white_capture++;
                            board[to_x][to_y]=black_king;
                            board[from_x][from_y]=empty;
                            board[to_x+1][to_y]=empty;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==white_man || board[to_x][i]==white_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[to_x][i]==white_man || board[to_x][i]==white_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king)  && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                            }
                            
                        }
                        else if((board[to_x-1][to_y]==white_man || board[to_x-1][to_y]== white_king) && board[to_x][to_y]==empty){
                            white_capture++;
                            board[to_x-1][to_y]=empty;
                            board[from_x][from_y]=empty;
                            board[to_x][to_y]=black_king;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==white_man || board[to_x][i]==white_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_y=to_y;
                                    from_x=to_x;
                                    white_capture++;
                                }
                                else if((board[to_x][i]==white_man || board[to_x][i]==white_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                    from_y=to_y;
                                    from_x=to_x;
                                    white_capture++;
                                
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                        }
                        }
                        else if((board[to_x][to_y+1]==white_man || board[to_x][to_y+1]== white_king) && board[to_x][to_y]==empty){
                            white_capture++;
                            board[to_x][to_y+1]=empty;
                            board[to_x][to_y+1]=black_king;
                            board[from_x][from_y]=empty;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==white_man || board[to_x][i]==white_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                     from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[to_x][i]==white_man || board[to_x][i]==white_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                     from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                            }

                        }
                        else if((board[to_x][to_y-1]==white_man || board[to_x][to_y-1]== white_king) && board[to_x][to_y]==empty)
                        {
                             white_capture++;
                            board[to_x][to_y-1]=empty;
                            board[to_x][to_y-1]=black_king;
                            board[from_x][from_y]=empty;
                            //from_x=to_x;
                            for(i=1; i<6; i++){
                                if((board[to_x][i]==white_man || board[to_x][i]==white_king) && board[to_x][i+1]==empty )
                                {
                                    board[to_x][i+1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                     from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[to_x][i]==white_man || board[to_x][i]==white_king) &&  board[to_x][i-1]==empty){
                                    board[to_x][i-1]=black_king;
                                    board[to_x][i]=empty;
                                    board[from_x][from_y]=empty;
                                     from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i+1][to_y]==empty){
                                    board[i+1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                                else if((board[i][to_y]==white_man || board[i][to_y]==white_king) && board[i-1][to_y]==empty){
                                    board[i-1][to_y]=black_king;
                                    board[i][to_y]=empty;
                                    board[from_x][from_y]=empty;
                                    from_x=to_x;
                                    from_y=to_y;
                                    white_capture++;
                                }
                            }
                        }
                         else{
                           board[to_x][to_y]=black_king;
                           board[from_x][from_y]=empty;
                            break;
                        }
                        
                    }

            }*/
             if(board[from_x][from_y]==white_man || board[from_x][from_y]==white_king)
            return -1;
        if(to_x<0 || to_y<0 || from_x<0 || from_y<0 || to_x>7 || to_y>7 || from_x>7 || from_y>7)
            return -2;
    }
}
        
       

/*Checks the board. If there's no black pieces white will win, no white pieces black will win
 * else game will continue */
int check_end_of_game(piece board[][8])
{
    int i,j, found_white=0, found_black=0;
    for(i=0; i<8;i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == white_man || board[i][j] == white_king)
                found_white++;
            if (board[i][j] == black_man || board[i][j] == black_king)
                found_black++;
        }
    }
    if(!found_white)
        return black;
    else if(!found_black)
        return white;
    else
        return -1;
}
/*Display the board */
void display_board(piece board[][8])
{
    int i,j;
    printf("\n");
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
/*A sample game, it won't finish because i can't do the king moves right */
void sample_game_1()
{
    piece game1[8][8];
    printf("SAMPLE GAME 1 \n");
    init_board(game1);
    move(game1, 5,5,4,5,white);
    move(game1,2,7,3,7,black);
    display_board(game1);
    move(game1,6,5,5,5,white);
    move(game1,2,6,3,6,black);
    display_board(game1);
    move(game1,6,6,6,5,white);
    move(game1,1,7,2,7,black);
    display_board(game1);
    move(game1,6,7,6,6,white);
    move(game1,2,0,3,0,black);
    display_board(game1);
    move(game1,5,1,4,1,white);
    display_board(game1);
    move(game1,3,0,3,1,black);
    display_board(game1);
    move(game1,6,1,5,1,white);
    move(game1,1,0,2,0,black);
    display_board(game1);
    move(game1,5,2,4,2,white);
    move(game1,2,0,3,0,black);
    display_board(game1);
    move(game1,6,2,5,2,white);
    move(game1,1,1,1,0,black);
    display_board(game1);
    move(game1,6,0,6,1,white);
    move(game1,1,0,2,0,black);
    display_board(game1);
    move(game1,4,5,4,4,white);
    move(game1,1,6,2,6,black);
    display_board(game1);
    move(game1,5,5,4,5,white);
    move(game1,1,5,1,6,black);
    display_board(game1);
    move(game1,4,5,4,6,white);
    move(game1,1,2,1,1,black);
    display_board(game1);
    move(game1,6,5,5,5,white);
    move(game1,2,3,3,3,black);
    display_board(game1);
    move(game1,4,4,4,5,white);
    move(game1,2,4,3,4,black);
    display_board(game1);
    move(game1,5,7,4,7,white);
    move(game1,3,7,5,7,black);
    display_board(game1);
    move(game1,5,0,4,0,white);
    move(game1,3,0,5,0,black);
    display_board(game1);
    move(game1, 4,2,3,2,white);
    move(game1, 2,2,4,2,black);
    display_board(game1);
    move(game1,4,5,4,4,white);
    move(game1,5,0,5,2,black);
    display_board(game1);
    move(game1,4,4,2,4,white);
    display_board(game1);
    move(game1,3,1,5,1,black);
    display_board(game1);
    move(game1,5,4,4,4,white);
    display_board(game1);
    move(game1,5,2,5,4,black);
    display_board(game1);
    move(game1,5,5,4,5,white);
    display_board(game1);
    move(game1,7,4,3,4,black);
    display_board(game1);
    move(game1,0,4,4,4,white);
    display_board(game1);
    move(game1,5,7,5,5,black);
    display_board(game1);
    move(game1,4,5,3,5,white);
    display_board(game1);
    move(game1,2,5,4,5,black);
    display_board(game1);
    move(game1,6,6,5,6,white);
    display_board(game1);
    move(game1,5,5,5,7,black);
    display_board(game1);
    move(game1,6,3,5,3,white);
    display_board(game1);
 

}
/*Sample game 2 isn't same as the gif animation because of that rule:
 * If there are two or more different chances to make capture, make any one of them. */
void sample_game_2()
{
    printf("SAMPLE GAME 2 \n");
    piece game2[8][8]={{empty,empty,empty,empty,empty,empty,empty,empty},
                       {empty,empty,black_man,black_man,black_man,black_man,empty,empty},
                       {empty, black_man,black_man,black_man,black_man,empty,black_man,black_man},
                       {black_man,black_man,black_man,empty,empty,black_man,empty,black_man},
                       {empty,empty,white_man,white_man,white_man,black_man,white_man,white_man},
                       {white_man,white_man,white_man,white_man,white_man,empty,white_man,white_man},
                       {empty,empty,white_man,white_man,white_man,white_man,empty,empty},
                       {empty,empty,empty,empty,empty,empty,empty,empty}};
    display_board(game2);
    move(game2,5,1,4,1,white);
    move(game2,3,1,5,1,black);
    display_board(game2);
    move(game2,4,3,3,3,white);
    move(game2,4,5,4,3,black);
    display_board(game2);
    move(game2,3,3,3,1,white);
    display_board(game2);
    move(game2,1,2,1,0,black);
    move(game2,5,3,4,3,white);
    display_board(game2);
    move(game2,5,1,5,3,black);
    display_board(game2);
    move(game2,4,3,3,3,white);
    move(game2,2,3,4,3,black);
    display_board(game2);
    move(game2,5,4,4,3,white);
    display_board(game2);
 

}
