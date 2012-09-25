/*
 * $Id: dmx_usb_test.c 40 2004-09-11 11:16:39Z erwin $ 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "conio.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <termios.h>

int main(int argc, char* argv[])
{
	unsigned char buffer[30];
	int fd;
	int res;
	int i;
	int pd;
	struct termios term;
	bool exit = false;
	int test = 0;
	char c;

	printf("\nTestprogramm fuer Enttec DMXUSB PRO\n");
	printf("USB to DMX Interface\n");

	printf("\nOeffne seriellen USB Port ttyUSB0\n");
	fd = open("/dev/ttyUSB0",O_WRONLY);
	if (fd < 0) {
		printf("\nDer Port konnte nicht geoeffnet werden.\n");
		printf("Die Anwendung wird daher nun beendet\n");
	//	exit(-1);
	}

	//Initialisiere das buffer Array

	for (i = 0; i < 29; i++)
	{
          buffer[i] = 0x00;
        }

	buffer[0] = 0x7E;	 //Startcode einer neuen DMX Nachricht
	buffer[1] = 0x06;	 //Es folgt eine Writeanweisung auf den Bus
	buffer[2] = 0x19 & 0xFF; //LSB Anzahl Datenfelder
	buffer[3] = 0x19 >> 8;   //MSB Anzahl Datenfleder
	buffer[4] = 0x00;	 //DMX Startcode
	buffer[29] = 0xE7;	 //Endcode dieser DMX Nachricht

	printf("\nAbbruch der Schleife ueber Tastendruck\n");
	printf("Abbruch erfolgt nach einem Durchlauf der Schleife\n");

	printf("Wert von ECHO: %#x\n", ECHO);
	printf("Wert von ~ECHO: %#x\n", ~ECHO);

	tcgetattr(pd, &term);
	printf("Inhalt vor ECHO: %#x\n", term.c_lflag);

	//Loechen des ECHO Flags im Terminal
	term.c_lflag &= ~ECHO;
	printf("Inhalt nach ECHO: %#x\n", term.c_lflag);
	//printf("Inhalt nach Loeschen des ECHO Flags: %#x\n", term.c_lflag);
	//term.c_lflag |= ECHO;
	//printf("Inhalt nach Setzen des ECHO Flags: %#x\n", term.c_lflag);
	tcsetattr(pd, TCSANOW, &term);

	c = getchar();
	printf("Eingabe: %c\n", c);
	while(!kbhit())
	{

	  //Schalte LED Nr. 1 ein
	  printf("\nTeste LED Nr.1\n");

	  buffer[5] = 127;
	  write(fd, buffer, 30);
	
	  //Warte 2 Sekunden
	  sleep(2);


	  //Schalte LED Nr.1 aus und Nr.2 ein
	  printf("Teste LED Nr.2\n");

          buffer[5] = 0;
	  buffer[6] = 127;
          write(fd, buffer, 30);

	  //Warte 2 Sekunden
          sleep(2);

          //Schalte LED Nr.2 aus und Nr.3 ein
          printf("Teste LED Nr.3\n");

          buffer[6] = 0;
          buffer[7] = 127;
          write(fd, buffer, 30);

	  //Warte 2 Sekunden
	  sleep(2);
	  buffer[7] = 0;

	}

	//Setzen des ECHO Flags im Terminal
        term.c_lflag |= ECHO;
        tcsetattr(pd, TCSANOW, &term);

	printf("\nDer serielle USB Port wird wieder geschlossen.\n");

	close(fd);

	return 0;
}
