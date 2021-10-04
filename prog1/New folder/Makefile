#Jameson Connor Harrington


a.out:	main.cpp OrderedList.o OrderedList.h Student.o Student.h
	g++ main.cpp OrderedList.o Student.o

OrderedList.o:	OrderedList.cpp OrderedList.h Student.o Student.h
		g++ -c OrderedList.cpp Student.o -o OrderedList.o
Student.o:	Student.cpp Student.h
		g++ -c Student.cpp -o Student.o
