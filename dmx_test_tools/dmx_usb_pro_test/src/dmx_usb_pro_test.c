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
	unsigned char buffer[513];
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

	printf("\nDer serielle USB Port wird wieder geschlossen.\n");

	close(fd);

	return 0;
}
