# Get-Next-Line

• Your function must be prototyped as follow :

  • int get_next_line(const int fd, char **line);
  

• We consider that get_next_line has an undefined behavior if, between two calls, the same file descriptor designs two distinct files although the reading from the first file was not completed.

• We consider also that a call to lseek(2) will never take place between two calls of the function get_next_line on the same file descriptor.

• Finally we consider that get_next_line has an undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.

• Global variables are forbidden.

• Static variables are allowed.

• You must only submit two files : get_next_line.c and get_next_line.h

• If you are clever, you will use your libft. If so, submit your folder libft at the root
of your repository.

• There cannot be a main function in your program.

• Do not push a Makefile.

• Your project must be written in accordance with the Norm.

• You have to handle errors carefully. In no way can your program, or in this par- ticular case your function, quit in an unexpected manner (Segmentation fault, bus error, double free, etc).

• All heap allocated memory space must be properly freed when necessary.

• Your project cannot leaks.

• You must submit a file called author containing your username followed by a ’\n’ at the root of your repository:

• If you choose to submit this project using your library libft, it is strictly FORBIDDEN to bypass the limitation of the Norm by adding some specific functions from your get_next_line. That would be considered cheating during your defence. Your get_next_line must hold in 5 functions of 25 lines max. The respect of this instruction will be carefully checked during your defence. There is no need for you ask permission to the staff to add a function to your library. Use your head instead and ask yourself if your function respects this instruction. If you do everything right, you will of course be encouraged to expand your library with generic functions. You’ll discover their usage as you complete this project.

• The libc functions allowed on this project are read, malloc and free.

• Write a function that returns a line read from a file descriptor.

• What we call a “line” is a succession of characters that end with ’\n’ (ascii code
0x0a) or with End Of File (EOF).

• The first parameter is the file descriptor that will be used to read.

• The second parameter is the address of a pointer to a character that will be used
to save the line read from the file descriptor.

• The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.

• Your function get_next_line must return its result without ’\n’.

• Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

• Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc.

• In you header file get_next_line.h you must have at least the prototype of the function get_next_line and a macro that allows to choose the size of the reading buffer for the read function. This value will be modified during the defence to evaluate the strength of your function. That macro must be named BUFF_SIZE.
  
