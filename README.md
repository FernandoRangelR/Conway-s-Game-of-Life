# Conway-s-Game-of-Life
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

The Game of Life was developed by British mathematician John Horton Conway. In Life, a board represents the world and each cell a single location. A cell may be either empty or inhabited. The game has three simple rules, which relate to the cell’s eight nearest neigbours:

1. Survival 
An inhabited cell remains inhabited if exactly 2 or 3 of its neighbouring cells are inhabited.

2. Death 
An inhabited cell becomes uninhabited if fewer than 2, or more than 3 of its neighbours are inhabited.

3. Birth 
An uninhabited cell becomes inhabited if exactly 3 of its neighbours are inhabited.

The next board is derived solely from the current one. The current board remains unchanged while computing the next board. In the simple case shown here, the boards alternate infinitely between these two states.

This program initialises the board, randomly setting the cells to be inhabited.
