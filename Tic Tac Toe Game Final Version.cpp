//Tic Tac Toe Game in C++

//Importing the libraries
#include<iostream>
#include<fstream>
using namespace std;

//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board
void displayBoard(char brd[][3]);

//Function to get the player input and update the board
void playerTurn(char brd[][3]);

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE
bool gameOver(char brd[][3]);

//Driver Program
int main(){
	int input;
	//Creating Clearing Previous Data on File.
	ofstream createFile;
   	createFile.open("Record.txt", ios::out);
   	createFile<<"*********************************\n\n";
   	createFile.close();
  
	do{
    	cout<<"\tT I C K -- T A C -- T O E -- G A M E";
    	cout<<"\n\n\t\t    FOR 2 PLAYERS\n\n";
    	cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    	cout<<"\nNote: Carefully Choose a Valid Position to Mark!"<<endl;
	
		//Initializing a 2D Array for the Board
	    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

		while(gameOver(board)){
        	displayBoard(board);
        	playerTurn(board);
        	gameOver(board);
    	}
    	displayBoard(board);
    	
	   	//Writing to File
		ofstream writeRecord;
    	writeRecord.open("Record.txt", ios::in | ios::app);
    	writeRecord<<"\n*********************************\n\n";
    	writeRecord.close();
    	
		if(turn == 'O' && draw == false){
       		cout<<"\n\nCongratulations! Player 1 has won the game\n\n";
    	}
    	else if(turn == 'X' && draw == false){
        	cout<<"\n\nCongratulations! Player 2 has won the game\n\n";
    	}
    	else
    	cout<<"\n\nGAME DRAW !!!\n\n";
    	cout<<"To Play Again : 1\nTo View Moves Record : 2\nTo Exit : 3\n";
    	while(!(cin>>input)){
				cout<<"\nPlease Choose a Valid Option\n"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
		}
		
		//Resetting Board
		if(input == 1){
		char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
		}

		//Reading From File
		else if(input == 2){
    	ifstream readRecord;
    	readRecord.open("Record.txt", ios::in);
    	string data;
    	while(getline(readRecord, data)){
    		cout<<data<<endl;
			}
		readRecord.close();
		cout<<"To Play Again : 1\nTo Exit : 2"<<endl;
		while(!(cin>>input)){
			cout<<"\nPlease Choose a Valid Option\n"<<endl;
			cin.clear();
			cin.ignore(123, '\n');
		}

		}
	}while(input == 1);
	
	    system("pause");
}
//Functions Definitions

void displayBoard(char board[][3]){

    //Render Game Board LAYOUT
    cout<<"\n\n\t\t|`````|`````|`````|\n";
    cout<<"\t\t|  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  |\n";
    cout<<"\t\t|_____|_____|_____|\n";
    cout<<"\t\t|     |     |     |\n";
    cout<<"\t\t|  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  |\n";
    cout<<"\t\t|_____|_____|_____|\n";
    cout<<"\t\t|     |     |     |\n";
    cout<<"\t\t|  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  |\n";
    cout<<"\t\t|_____|_____|_____|\n";
}

void playerTurn(char board[][3]){
    if(turn == 'X'){
        cout<<"\n\nPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\nPlayer - 2 [O] turn : ";
    }
    //Taking input from user
	while(!(cin>>choice)){
		cout<<"\nChoose a Valid Position From 1 to 9\n"<<endl;
		cin.clear();
		cin.ignore(123, '\n');
	}

	//Write Moves on Record File
	ofstream writeMoves;
	writeMoves.open("Record.txt", ios::out | ios::app);		
		if(turn == 'X'){
		writeMoves<<"Player 1 Marked Position : "<<choice<<"\n"<<endl;
		}
		else
		writeMoves<<"Player 2 Marked Position : "<<choice<<"\n"<<endl;

    //switch case to get row & column position according to user input
    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
        cout<<"\nInvalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }
	else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }
	else{
        //if input position already filled
        cout<<"\n\nPlease choose another position!!\n";
        playerTurn(board);
    }
    
    writeMoves.close();
    /* Ends */}

bool gameOver(char board[][3]){
    	
    for(int i=0; i<3; i++){
    	//Checking win for Straight Rows and Columns
    	if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    	return false;
    
    	//Checking win for both Diagonals
    	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    	return false;
    }
		//Checking if game is in continue mode or not
    for(int i=0; i<3; i++){
	   	for(int j=0; j<3; j++){
    		if(board[i][j] != 'X' && board[i][j] != 'O')
    		return true;
    	}
	}	
    	//Checking if game is drawn
    	draw = true;
    	return false;
    
}

