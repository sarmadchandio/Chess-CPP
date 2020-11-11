# Chess-Cs200-proj
One of the very first projects! There is a room for a lot of improvements.
I made console-based chess game using Inheritence. The main code for the chess board is in Source.cpp where as each of the chess pieces have their own class.

### Compiling
You can compile and run the game using

```
g++ source.cpp -o game  
game.exe
```

### Game Mechanics
This is how the start screen looks like
![Start](/Imgs/StartScreen.png)
You can move the units using the blocks of the board A0, A1 etc
If you try to make an invalid move it will give an error.

After each move, the condition for **check** and **check mate** is checked. And in case it is detected the user is warned on the screen.
![Start](/Imgs/Check.png)


Once you are **checked** by your opponent you can't make an illegal move (a move that will make your king die).
![Start](/Imgs/InvalidCheck.png)

Finally. The game ends when one of the players is given a check mate.
![Start](/Imgs/CheckMate.png)
