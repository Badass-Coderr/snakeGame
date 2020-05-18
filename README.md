# snakeGame
The conventional snake game as you play

You must have played this game before, and had lof of fun.

But go through the controls as for now.
  1. "w" is to be pressed for forward movement
  2. "a" is to be pressed for leftward movemrnt
  3. "d" is to be pressed for rightward movement 
  4. "s" is to be pressed for downward movement
  5. Also do not assign the playground size to be larger than 30X20, although if you do so, the game will successfully run but u'll not have a good experience while playing it.
  
New features added:
  1. Added response for game over conditions( if the snake touches the walls or itself ) in positionCalc functon.
  2. Added function to check whether the direction entered by the user is accessible by the snake or not.(bool directionAccessibility(char input);
  3. Added a gameover display screen which shows the score.
  4. Modified the input function to allow movement only in accessible direction.

patch 1.11
  1. Added functionality for using arrow keys for movement.
