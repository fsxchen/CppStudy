demo:iotool.c graphic.c main.c
	gcc iotool.c -c -fpic
	gcc graphic.c -c -fpic
	gcc iotool.o graphic.o -shared -olibdemo.so
	gcc main.c -ldemo -omain -L.
