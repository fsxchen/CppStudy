OBJ=input.o primer.o

input.o:input.c
	@gcc -c -fpic input.c
primer.o:primer.c
	@gcc -c -fpic primer.c
libdemo.so:$(OBJ)
	gcc -shared -olibdemo.so input.o primer.o
demo:libdemo.so demo.c
	gcc demo.c -ldemo -L. -odemo
.PHONY:clean install
clean:
	rm -fr *.o *.so *.a main demo





# compile:input.c primer.c
# 	@gcc -c -fpic input.c
# 	@gcc -c -fpic primer.c
# link:compile
# 	gcc -shared -olibdemo.so input.o primer.o
# # demo:link
# # 	gcc demo.c -ldemo -L. -omain
# clean:
# 	rm -fr *.o *.so *.a main
