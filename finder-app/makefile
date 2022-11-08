VAR="default"
TEST="Cross-Compile" 

writer: writer.c 
	
	@if [ $(VAR) = $(TEST) ];\
	then \
		echo $(VAR);\
		aarch64-none-linux-gnu-gcc -g -Wall -o writer writer.c;\
	else \
		echo $(VAR);\
		gcc -g -Wall writer.c -o writer;\
	fi

clean: 
	#rm *.o 
	rm writer
