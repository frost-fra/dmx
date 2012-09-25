# build dmx_usb_pro_test executable when user executes "make"

dmx_usb_pro_test: dmx_usb_pro_test.o
	$(CC) $(LDFLAGS) dmx_usb_pro_test.o -o dmx_usb_pro_test
dmx_usb_pro_test.o: dmx_usb_pro_test.c conio.h
	$(CC) $(CFLAGS) -c dmx_usb_pro_test.c

# remove object files and executable when user executes "make clean"
clean:
	rm *.o dmx_usb_pro_test
