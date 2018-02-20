Qube - a simple text game.

 Created at the beginning as a simple structural porogram, and then as you acquire knowledge
 transformed into an increasingly advanced object program.
 at https://github.com/Mighn/qube_txt/commits/master I put all the development of the code.
 I also use this program to learn the basic functionalities of Github.

Entry point is main() function inside main.cpp file

first stage (prototype) of this program is here: https://github.com/Mighn/qube_txt-prototype

At this moment I working on event system (enemy, ally, and chest) and next one will be key system: You can 
find a key while encouter, and use to open a single door 


Files:

mian
Main file of game... I think is too big, and I will try move some code to class files.

qube (class)
A class describing the basic game cell at once with data on the status of the door, description of the cell, game parameters and its number.
The ultimate masking automation of activities related to the creation of a room / area and the possibility of collision-free adding new functions

player (class)
A class describing the player's parameters and the current state of the game
ultimately, the minimization of setters and getters and the introduction of more complex and comprehensive methods
(withdrawal of part of the operation from the main program function)

ScoreBoard (class)
Maintain a game score table: read scores from file, write to array, sort and display. 
Next check actual position and write current score to end of file if need.

eventQ  (class)
***** In first stage of development...
Create an enemy, friend or crate that have some of the common features and part of their own
In plan all event affects health and/or time and can give a key - necessary item to open a lock door.