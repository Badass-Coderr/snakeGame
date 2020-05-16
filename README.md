# snakeGame
The conventional snake game as you play
patch 1.01
  1. Added response for game over conditions( if the snake touches the walls or itself ) in positionCalc functon. (73-84)
  2. Added function to check whether the direction entered by the user is accessible by the snake or not.(bool directionAccessibility(char input); 111-139)
         - detailed description commented before the function in the cpp file.
  3. Added a gameover display screen which shows the score.(gameOverDisplay(); 217-225)
  4. Modified the input function to allow movement only in accessible direction.
