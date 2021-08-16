
Finder winner (Normal game) and Keepers looser(Miser game) are two popular games in the world
of game theory.
Properties of above games are:
1> The games are sequential. The players take turns one after the other , and there is no passing.
2> The games are impartial . Given a state of the game , the set of available moves does not 
depend on whether you are a player 1 or player 2.
For example , Chess is a partisan game(moves are not same).
3> Both players have perfect information about the game. There is no secrecy involved.
4> The games are guarenteed to in a finite number of moves.
5> Impartial games can be solved using Sprague - Grundy theorem which reduces every such game
to game of NIM.

Nim game:

Q> There are n piles (which may be of different heights) of stones. A and B play a game on that.
A plays first turn and each player has to take at least one stone from a single pile only . Find
who will win.

Sol> If A plays first and if take xor of all piles stone then , if xor is zero then B wins 
otherwise A wins.
This is because if intially xor is non zero that means that odd number of bits are present at least
at one position.

Balanced state - xor = 0 
Unbalanced state - xor != 0 

Piles size also Known as Grundy number.

NIM game is the special case of Sprague Grundy.


//------------------------------------------------------------------------------------------------------//

Sprague Grundy theory:

1>mex({a1 , a2 , a3}) = Smallest positive integer in the set which is not present in the set.

2> Grundy number , g(n) = mex( {g(n - p) , g(n - 2) , g(n - 3) , g(n - 4) , ... , g(n - k)}) where p ans k are the constraints
on the number of coins allowed to take in one move.

3> If A makes first move then and at least p coins and at most k coins are allowed to pick in one move , for n piles of stones if xor of Grundy numbers of all the n piles is zero then A wins 
otherwise B wins.

