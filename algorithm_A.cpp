#include <iostream>
#include <time.h>
#include "../include/rules.h"
#include "../include/algorithm.h"
using namespace std;
/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions
 * 1. ~ 4. are listed in next block)
 *
 * The STL library functions is not allowed to use.
******************************************************/
/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 *
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/
int score(Board board, char color)
{
    int Score = 0, sameorb = 0, enemyorb = 0, contiguous = 0;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(board.get_cell_color(i, j) == color)
            {
                sameorb += board.get_orbs_num(i, j);
                bool noadjacent = true;
                for(int k = 0, r = 0, c = 1, temp = 0; k < 4; k++, temp = r, r = c, c = -temp)
                {
                    if(i + r < 0 || i + r >= ROW || j + c < 0 || j + c >= COL) continue;
                    if(board.get_cell_color(i + r, j + c) != color && board.get_cell_color(i + r, j + c) != 'w')
                    {
                        Score -= 5 - board.get_capacity(i + r, j + c);
                        noadjacent = false;
                    }else if(board.get_cell_color(i + r, j + c) == color) contiguous++;
                }
                if(noadjacent)
                {
                    if(board.get_capacity(i, j) == 3) Score += 2;
                    else if(board.get_capacity(i, j) == 2) Score += 3;
                    if(board.get_orbs_num(i, j) == board.get_capacity(i, j) - 1) Score += 2;
                }
            }else if(board.get_cell_color(i, j) != 'w') enemyorb += board.get_orbs_num(i, j);
        }
    }
    Score += sameorb;
    if(enemyorb == 0 && sameorb > 1) return 10000;
    else if(sameorb == 0 && enemyorb > 1) return -10000;
    if(contiguous != 0) Score += contiguous + 2;
    return Score;
}
int minimax(Board board, int depth, bool isMaximizing, int alpha, int beta, char color, Player *player)
{
    char enemycolor;
    (color == 'b') ? enemycolor = 'r' : enemycolor = 'b';
    Player newplayer(enemycolor);
    if(depth == 5  || board.win_the_game(*player) || board.win_the_game(newplayer))
    {
        return score(board, color);
    }
    if(isMaximizing)
    {
        int bestscore = -100000;
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                if(board.get_cell_color(i, j) == 'w' || board.get_cell_color(i, j) == color)
                {
                    Board newboard = board;
                    newboard.place_orb(i, j, player);
                    int Score = minimax(newboard, depth + 1, !isMaximizing, alpha, beta, color, player);
                    (Score > bestscore) ? bestscore = Score : bestscore = bestscore;
                    (Score > alpha) ? alpha = Score : alpha = alpha;
                    if(beta <= alpha) break;
                }
            }
        }
        return bestscore;
    }else
    {
        int bestscore = 100000;
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                if(board.get_cell_color(i, j) != color)
                {
                    Board newboard = board;
                    newboard.place_orb(i, j, &newplayer);
                    int Score = minimax(newboard, depth + 1, !isMaximizing, alpha, beta, color, player);
                    (Score < bestscore) ? bestscore = Score : bestscore = bestscore;
                    (Score < beta) ? beta = Score : beta = beta;
                    if(beta <= alpha) break;
                }
            }
        }
        return bestscore;
    }
}
void algorithm_A(Board board, Player player, int index[]){
    int bestscore = -10001, besti = 0, bestj = 0;
    char color = player.get_color();
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(board.get_cell_color(i, j) == 'w' || board.get_cell_color(i, j) == player.get_color())
            {
                Board newboard = board;
                newboard.place_orb(i, j, &player);
                int score = minimax(newboard, 1, false, -10001, 100001, color, &player);
                if( score > bestscore)
                {
                    bestscore = score;
                    besti = i;
                    bestj = j;
                }
            }
        }
    }
    index[0] = besti;
    index[1] = bestj;
}
