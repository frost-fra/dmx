/*
 * $Id: dmx_usb_test.c 40 2004-09-11 11:16:39Z erwin $ 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned char buffer[31];
	int fd;
	int res;
	int i;

	printf("\nTestprogramm fuer Enttec DMXUSB PRO\n");
	printf("USB to DMX Interface\n");

	printf("\nOeffne seriellen USB Port ttyUSB0\n");
	fd = open("/dev/ttyUSB0",O_WRONLY);
	if (fd < 0) {
		printf("\nDer Port konnte nicht geoeffnet werden.\n");
		printf("Die Anwendung wird daher nun beendet\n");
		exit(-1);
	}

	for (i = 5; i < 29;i++) {
                buffer[i] = 0x78;
        }

	buffer[0] = 0x7E; //Startcode einer neuen Nachricht
	buffer[1] = 0x06; //Es folgt eine Writeanweisung auf den Bus
	buffer[2] = 0x19 & 0xFF; //Anzahl aller zu schreibenden Daten
	buffer[3] = 0x19 >> 8;  //
	buffer[4] = 0x00; //DMX Startcode


	buffer[29] = 0xE7; //Endcode dieser Nachricht

	write(fd, buffer, 30);
	
	printf("\nDer serielle USB Port wird wieder geschlossen.\n");

	close(fd);

	return 0;
}
