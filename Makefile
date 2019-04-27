build: clean
	@mkdir -p build
	@make builder

builder: Request.o Response.o Headers.o 
	g++ build/Request.o build/Response.o build/Headers.o main.cpp -o main.out -lcurl
	@chmod +x main.out
	@cowsay "Moaaaaa, build completed."

Request.o: 
	g++ -c Request/Request.cpp -o build/Request.o
Response.o: 
	g++ -c Request/Response.cpp -o build/Response.o
Headers.o: 
	g++ -c Request/Headers.cpp -o build/Headers.o
clean:	
	rm -rf build/*.o