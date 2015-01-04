demo:input.c primer.c
	@gcc -c -fpic input.c
	@gcc -c -fpic primer.c
	gcc -shared -olibdemo.so input.o primer.o
	gcc demo.c -ldemo -L. -omain
