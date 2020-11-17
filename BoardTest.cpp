#include <iostream>
#include "Board.h"
#include "BoardPosition.h"
#include "Player.h"
#include "Enum.h"

using namespace std;
//Forming mill test
/*Given an ongoing game in the first phase, when a player makes a mill
 by forming 3 pieces on a connecting line, then the textbox should
 display “Player X has made a mill. Select a piece to capture.”
*/
void formMillTest() {
	Board gameboard;

	Player player1(1, false);
	Player player2(2, false);
	gameboard.addPlayers(player1);
	gameboard.addPlayers(player2);
	gameboard.setState(phase1);
	gameboard.setCurrPlayerVar(1);

	gameboard.doMovePhase1('a', 1, gameboard.getCurrentPlayer());
	gameboard.doMovePhase1('d', 1, gameboard.getCurrentPlayer());
	gameboard.doMovePhase1('g', 1, gameboard.getCurrentPlayer());
	gameboard.checkAndChangeState(gameboard.getPlayers().at(0), gameboard.getPlayers().at(1));

	if (gameboard.getState() == mill)
		cout << "Result: " << gameboard.getCurrentPlayer().getPlayerID() << " has made a Mill! Select a piece to remove: " << endl;
	else
		cout << "Result: Test Failed" << endl;

	cout << "Expected Result: " << gameboard.getCurrentPlayer().getPlayerID() << " has made a Mill! Select a piece to remove: " << endl;
	system("pause");
}
//Valid/Invalid move test
//Given an ongoing game in the first phase, when a player makes a legal move (empty spot), the piece is drawn on that spot
//Given an ongoing game in the first phase, when a player makes an illegal move
//(non-empty spot), the piece is returned to their stack of pieces and they can redo their turn
void moveValidityTest() {
	Board gameboard;
	Player player1(1, false);
	gameboard.addPlayers(player1);
	gameboard.setState(phase1);
	gameboard.setCurrPlayerVar(1);
	//A valid move
	if (!gameboard.phase1Check('a', 1))
		cout << "Result: move invalid, test failed" << endl;
	else
		cout << "Result: Valid move" << endl;
	cout << "Expected Result: Valid move" << endl;

	//An invalid move that is out of bounds
	if (!gameboard.phase1Check('z', 9))
		cout << "Result: move invalid" << endl;
	else
		cout << "Result: Valid move" << endl;
	cout << "Expected Result: move invalid" << endl;

	//Invalid move, space is occupied
	gameboard.doMovePhase1('a', 1, gameboard.getCurrentPlayer());
	if (!gameboard.phase1Check('a', 1))
		cout << "Result: move invalid" << endl;
	else
		cout << "Result: Valid move" << endl;
	cout << "Expected Result: move invalid" << endl;
	system("pause");
}

//Phase 2 movement test
void FlightMovementTest() {
	Board gameboard;
	Player player1(1, false);
	gameboard.addPlayers(player1);
	gameboard.setState(phase1);
	gameboard.setCurrPlayerVar(1);
	gameboard.doMovePhase1('a', 1, gameboard.getCurrentPlayer());
	gameboard.doMovePhase1('d', 1, gameboard.getCurrentPlayer());
	//Testing a valid move
	gameboard.setState(phase2);
	if (gameboard.isValidLocation('d', 1, 'g', 1, gameboard.getCurrentPlayer()) == false)
		cout << "Result: Invalid move" << endl;
	else
		cout << "Result: Valid Move" << endl;
	cout << "Expected Result: Valid Move" << endl;

	//Test for moving to an occupied space.
	if (gameboard.isValidLocation('d', 1, 'a', 1, gameboard.getCurrentPlayer()) == false)
		cout << "Result: Invalid move" << endl;
	else
		cout << "Result: Valid Move" << endl;
	cout << "Expected Result: Invalid move" << endl;
	system("pause");
