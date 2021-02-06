# Fillit

Your executable must take only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format : every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino are separated by an newline each.

If the number of parameters sent to your executable is not 1, your program must display its usage and exit properly. If you don’t know what a usage is, execute the command cp without arguments in your Shell. It will give you an idea. Your file should contain between 1 and 26 Tetriminos.

The description of a Tetriminos must respect the following rules :

    • Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).

    • A Tetrimino is a classic piece of Tetris composed of 4 blocks.

    • Each character must be either a block character(’#’ ) or an empty character (’.’).

    • Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).



• Your project must be written in C and must respect the Norme coding standard.

• The allowed functions are : exit, open, close, write, read, malloc and free.

• Your Makefile must compile your code without relinks.

• It must contain the following rules : all, clean ,fclean and re.

• You must compile your binary with the Wall, Wextra and Werror flags. Any other flag are forbidden , especially those for optimising purposes.

• The binary must be named fillit and located in the root directory of your repos- itory.

• You must submit a file called author containing your username followed by a ’\n’ at the root of your repository:

• Your project cannot have memory leaks.
