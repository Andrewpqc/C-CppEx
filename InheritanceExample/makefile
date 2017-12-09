main.exe:student.o teacher.o main.o human.o
	g++ -o main.exe student.o teacher.o main.o human.o
human.o:human.cpp human.h
student.o:student.cpp student.h  
	g++ -c student.cpp student.h 
teacher.o:teacher.cpp teacher.h 
	g++ -c teacher.cpp teacher.h 
main.o:main.cpp
	g++ -c main.cpp

cleanall:
	rm main.exe student.o teacher.o main.o human.o student.h.gch teacher.h.gch
cleansome:
	rm student.o teacher.o main.o human.o student.h.gch teacher.h.gch