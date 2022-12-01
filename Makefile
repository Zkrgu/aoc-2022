CC=g++
DAY=01

run: day${DAY}.exe
	./day${DAY}.exe

day${DAY}.exe: day${DAY}.cpp
	${CC} -o day${DAY}.exe day${DAY}.cpp
