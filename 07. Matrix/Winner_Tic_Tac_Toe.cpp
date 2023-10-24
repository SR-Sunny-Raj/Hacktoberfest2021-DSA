/*
Problem StatementTic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

 

Example 1:


Input: n=5, moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
Example 2:


Input: n=6, moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
Example 3:


Input: n=8, moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
Example 4:


Input: n=2, moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
 

Constraints:

1 <= moves.length <= 9
moves[i].length == 2
0 <= rowi, coli <= 2
There are no repeated elements on moves.
moves follow the rules of tic tac toe.
*/

//Main Driver
#include <bits/stdc++.h>

using namespace std;

string tictactoe(int mo[][2],int n) {
	vector<vector<string>>ma(3,vector<string>(3,"."));
	for(int i=0;i<n;i++){
		if(i%2==0)ma[mo[i][0]][mo[i][1]]="A";
		else ma[mo[i][0]][mo[i][1]]="B";
	}
	if(n<3)return "Pending";
	for(int i=0;i<3;i++){
		if((ma[i][0]==ma[i][1] && ma[i][1]==ma[i][2]) && ma[i][0]!=".")return ma[i][0];
		if((ma[0][i]==ma[1][i] && ma[1][i]==ma[2][i]) && ma[0][i]!=".")return ma[0][i];
	}
	if((ma[0][0]==ma[1][1] && ma[1][1]==ma[2][2] || ma[0][2]==ma[1][1] && ma[1][1]==ma[2][0]) && ma[1][1]!=".")return ma[1][1];
	if(n==9)
		return "Draw";
	else return "Pending";
}
int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;cin>>n;
		int mo[n][2];
		for(int i=0;i<n;i++)
			cin>>mo[i][0]>>mo[i][1];
		cout<<tictactoe(mo,n)<<endl;
	}
}
