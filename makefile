CC = gcc

objs    =set_ttyS1.o call_number.o send_message.o gprs_main.o
srcs    =set_ttyS1.c call_number.c send_message.c gprs_main.c

gprs_bin: $(objs)
	$(CC) -o gprs_bin $(objs)
	@make clean

gprs_main.o: $(srcs) gprs.h
	$(CC) -c  $(srcs)

set_ttyS1.o: set_ttyS1.c gprs.h
	$(CC) -c  set_ttyS1.c

call_number.o: call_number.c gprs.h
	$(CC) -c  call_number.c

send_message.o: send_message.c  gprs.h
	$(CC) -c  send_message.c 

clear:
	@rm  gprs_bin

.PHONY: clean
clean:  
	@rm *.o 
