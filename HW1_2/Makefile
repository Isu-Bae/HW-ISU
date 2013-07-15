obj-m	= ex1.o

KDIR	:= /usr/src/linux-headers-3.5.0-23-generic 
PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean :
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf *.cmd
	rm -rf *.o
