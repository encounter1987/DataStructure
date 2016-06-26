CC=g++
INCLUDE=../DsUtils
CPP=../DsUtils
OBJ=*.o
OP=binary


exec: \
	compile
	@echo "==OUTPUT OF THE PROGRAM:_______________________________________________________________\n"
	@./binary <$(INPUT)

compile: \
	makeobjectfiles
	@echo "==COMPILING____________________________________________________________________________"
	@$(CC) -o $(OP) $(SRC) *.o  -I $(INCLUDE)

makeobjectfiles:
	@echo "==MAKING OBJECT FILES__________________________________________________________________"
	@$(CC) -c $(CPP)/*.cpp -I $(INCLUDE)

clean:
	@echo "==MAKE CLEAN___________________________________________________________________________"
	@rm *.o $(OP)
	@rm $(INCLUDE)/*.gch
