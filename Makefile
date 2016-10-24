SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o
$(OBJ)/pruebacronologia.o: $(OBJ)/Cronologia.o $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp
$(OBJ)/Cronologia.o: $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
