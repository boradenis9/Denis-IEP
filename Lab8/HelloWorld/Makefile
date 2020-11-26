obj-m += helloWorld.o

all:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean: 
		make -C /lib/modulse/$(shell uname -r)/build M=$(PWD) clean
		 