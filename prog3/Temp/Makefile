#Jameson Connor Harrington

FLAGS=-fno-elide-constructors
a.out:	main.cpp OrderedList.h Student.o Student.h
	g++ $(FLAGS) -g main.cpp Student.o

Student.o:	Student.cpp Student.h
		g++ -g $(FLAGS) -c Student.cpp -o Student.o
