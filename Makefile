CC=g++
DAY=02

run: day${DAY}
	./day${DAY}

day${DAY}: day${DAY}.cc
	${CC} -o day${DAY} day${DAY}.cc
