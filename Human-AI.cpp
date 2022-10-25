#include <iostream>
#include <string>
using namespace std;
//the global variable for the game matrix
string game_area[3][3] = {{" "," ", " "}, {" "," ", " "}, {" "," ", " "}};
//printing out the layout for the tic tac toe
void print_game_area(){
    cout<<game_area[0][0]<<" | "<<game_area[0][1]<<" | "<<game_area[0][2]<<endl;
    cout<<"---------"<<endl;
    cout<<game_area[1][0]<<" | "<<game_area[1][1]<<" | "<<game_area[1][2]<<endl;
    cout<<"---------"<<endl;
    cout<<game_area[2][0]<<" | "<<game_area[2][1]<<" | "<<game_area[2][2]<<endl;
}
//turn for each of the human player

void humanturn(){
    //ask human for input
    //x,y are for final values and tx, ty ate temproary x, y
    int x, y, tx, ty;
    cout<<"enter the position x: ";
    cin>>tx;
    //check for proper input
    while(tx<0 || tx>4){
        cout<<"enter the position x: ";
        cin>>tx;
    }
    cout<<"enter the position y: ";
    cin>>ty;
    //check for proper input
    while(ty<0 || ty>4){
        cout<<"enter the position y: ";
        cin>>ty;
    }

    x=tx-1;
    y=ty-1;

    //place the turn
    if(game_area[x][y]!="X" && game_area[x][y]!="O"){
        game_area[x][y]="X";
    }
    else{
        cout<<"enter correct values"<<endl;
        humanturn();
    }
}


bool isFinished(){
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (game_area[i][j]!=" "){
                return false;
            }
        }
    }
    return true;
}

int check_win(){
    //rows
    for(int i=0;i<3;i++){
        if(game_area[i][0]==game_area[i][1] && game_area[i][1]==game_area[i][2] && game_area[i][0]!=" "){
            if(game_area[i][0]=="X"){
                return -1;
            }
            else{
                return 1;
            }
        }
    }
    //columns
    for (int i=0;i<3;i++){
        if(game_area[0][i]==game_area[1][i] && game_area[1][i]==game_area[2][i] && game_area[0][i]!=" "){
            if(game_area[0][i]=="X"){
                return -1;
            }
            else{
                return 1;
            }
        }
    }
    //diagonals
    if(game_area[0][0]==game_area[1][1] && game_area[1][1]==game_area[2][2] && game_area[0][0]!=" "){
        if(game_area[0][0]=="X"){
                return -1;
            }
            else{
                return 1;
            }
    }
    else if(game_area[0][2]==game_area[1][1] && game_area[1][1]==game_area[2][0] && game_area[0][2]!=" "){
        if(game_area[0][2]=="X"){
                return -1;
            }
            else{
                return 1;
            }
    }
    else{
        return 0;
    }

}


// void AIturn(){
//     //call to MiniMax
//     //call AI

//     game_area[x][y] = "X";
// }

int minimax(int depth, bool isMax){

    int current_score = check_win();

    if (current_score == 1){
        return current_score;
    }
    if (current_score == -1){
        return current_score;
    }
    if (isFinished()){
        return 0;
    }

    if (isMax){

        int score = -1000;
        //cout<<"max"<<endl;
        
        for(int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (game_area[i][j]==" "){
                    game_area[i][j] = "X";
                    score = max(score, minimax(depth+1, false));
                    game_area[i][j] = " "; 
                }
            }
        }
        return score;
    }
    else{
        //cout<<"min"<<endl;
        int score = 1000;

        for(int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (game_area[i][j]==" "){
                    game_area[i][j] = "O";
                    score = min(score, minimax(depth+1, true));
                    game_area[i][j] = " ";
                }
            }
        }
        return score;
    }

}

void bestMove(){
    
    int x, y;
    int bestscore = -1000;
    int score;

    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(game_area[i][j] == " "){
               game_area[i][j] = "O";
               score = minimax(0, true);
               game_area[i][j] = " ";
                if(score>bestscore){
                   //cout<<"here"<<endl;
                   bestscore = score;
                   cout<<"score: "<<score<<endl;
                   x=i;
                   y=j;
                   cout<<x<<" "<<y<<endl;
                }
            } 
        }
    }
    game_area[x][y] = "O";
}


int main(){

    int winner;
    bool running = true;
    //printing empty board
    system("clear");
    print_game_area();

    while (running){

        //human turn 
        humanturn();
        system("clear");
        print_game_area();
        int ret1 = check_win();
        if(ret1!=0){
            winner = ret1;
            running=false; 
            break;  
        }

        if(isFinished()){
            running=false;
            winner = 0;
        }

        //AI turn 
        bestMove();
        system("clear");
        print_game_area();
        int ret2 = check_win();
        if(ret2!=0){
            winner = ret2;
            running=false;
            break;
        }

        if(isFinished()){
            running=false;
            winner = 0;
        }
        
    }


    cout<<"the winner is "<<winner<<"!"<<endl;

    return 0;
}
