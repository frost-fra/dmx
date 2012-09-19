# build helloworld executable when user executes "make"
dmx_usb_test: dmx_usb_test.o
	$(CC) $(LDFLAGS) dmx_usb_test.o -o dmx_usb_test
dmx_usb_test.o: dmx_usb_test.c
	$(CC) $(CFLAGS) -c dmx_usb_test.c

# remove object files and executable when user executes "make clean"
clean:
	rm *.o dmx_usb_test
