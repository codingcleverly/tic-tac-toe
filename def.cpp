#include <iostream>
#include "dec.h"
//globally defined
using namespace std;
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "}; 
int player = 1;   
int position = 0;  

void introduction()
{
	cout<<"Press [Enter] to begin: ";
	getchar(); //haults the screen  
	cout<<"\n";
	
	 cout<<"\n";
  cout<<"***********\n";
  cout<<"Tic-Tac-Toe\n";
  cout<<"***********\n";
  
  cout<<"Player 1) X\n";
  cout<<"Player 2) O\n";
  
  cout<<"The 3x3 grid is shown below:\n\n";
  
  cout << "     |     |      \n";
  cout << "  1  |  2  |  3   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  4  |  5  |  6   \n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  7  |  8  |  9   \n";
  cout << "     |     |      \n\n";
  
}



bool is_winner()
{
	bool winner = false;
	//checking the rows
	if((board[0]==board[1]) && (board[1]==board[2]) && board[0] != " ") 
	{
		winner = true;
	}
	else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ") 
	{
    winner = true;
    } 
	 
	else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ") 
	{
    winner = true;
  	} 

	//checking the columns
	
	else if((board[0]==board[3]) && (board[3]==board[6]) && board[0] != " ")
	{
		winner = true;
	}
	
	else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
	{
    winner = true;
 	 } 
	
	else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ") 
	{
    winner = true;
  	}

	//checking the diagonals
	
	else if ((board[0]==board[4]) && (board[4]==board[8]) && board[0] != " ")
	{
		winner = true;
	}
	
	else if ((board[2]==board[4]) && (board[4]==board[6]) && board[2] != " ")
	{
		winner = true;
	}
	
	return winner;
	
}

bool filled_up()
{
	bool filled = true;
	
	for(int i = 0; i<9; i++)
	{
		if(board[i]==" ")
		{
			filled = false;
		}
	}
	
	return filled;
}




void draw()
{
  cout<<  "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";

}



void set_position()
{
	cout<<"Player "<<player<<"'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
	while(!(cin>>position))
	{
		cout<<"Please enter a valid number between (1-9)"<<endl;
		cin.clear();  //flushing the buffer
    	cin.ignore();  
	}
	cout<<endl;
	
	while (board[position -1] != " "){
    cout<<"Oops, that position is already filled\nTry again\n";
    cout << "Player " << player << "'s Turn (Enter 1-9): ";
    cin>>position;
    cout<<"\n";

	
}

}


void update_board()
{
  
  if (player % 2 == 1){
    board[position - 1] = "X";   //1-9        0-8
  }
  else
  {
    board[position - 1] = "O";
  }
}


void change_player() {
  if (player == 1){
    player++;
  }
  else{
    player--;
  }
}


void take_turn()
{
	while(!is_winner() && !filled_up())  
	{
		//invoking the functions
		set_position();
		update_board();
		change_player();
		draw();
	}
}

void end_game()
{
	if(is_winner())
	{
		cout<<"There is a winner!"<<endl;
		
	}
	
	else if(filled_up())
	{
		cout<<"There is a tie!"<<endl;
	}
}

