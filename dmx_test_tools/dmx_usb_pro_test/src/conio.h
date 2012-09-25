#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <string.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
  struct termios oldattr, newattr;
  int ch;

  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
  return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
  struct termios oldattr, newattr;
  int ch;

  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
  return ch;
}


int kbhit(void)
{
  struct termios term, oterm;
  int fd = 0;
  int c = 0;

  printf("Funktion kbhit() wird ausgefuehrt");
  tcgetattr(fd, &oterm);
  memcpy(&term, &oterm, sizeof(term));
  term.c_lflag = term.c_lflag & (!ICANON);
  term.c_cc[VMIN] = 0;
  term.c_cc[VTIME] = 1;
  tcsetattr(fd, TCSANOW, &term);
  c = getchar();
  printf("/nDer Keycode lautet: %#x/n", c);
  printf("Der Buchstabe lautet: %c/n", c);
  tcsetattr(fd, TCSANOW, &oterm);
  if (c != -1)
  ungetc(c, stdin);
  return ((c != -1) ? 1 : 0);
}
