build: clean Request.o Response.o Headers.o 
	g++ Request.o Response.o Headers.o main.cpp -o main.out -lcurl
	chmod +x main.out
	@cowsay "Moaaaaa, build completed."

Request.o: 
	g++ -c Request.cpp -o Request.o
Response.o: 
	g++ -c Response.cpp -o Response.o
Headers.o: 
	g++ -c Headers.cpp -o Headers.o
clean:	
	rm -rf *.o