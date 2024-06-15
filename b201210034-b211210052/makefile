all: derle bagla calistir

derle:
	g++  -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++  -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++  -c -I "./include" ./src/YukariYonluBagliListe.cpp -o ./lib/YukariYonluBagliListe.o
	g++  -c -I "./include" ./src/AsagiYonluBagliListe.cpp -o ./lib/AsagiYonluBagliListe.o

	

bagla:
		g++  ./lib/main.o ./lib/Dugum.o ./lib/YukariYonluBagliListe.o ./lib/AsagiYonluBagliListe.o -o ./bin/program
		
calistir:
		./bin/program
	