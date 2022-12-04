include .env
CC=g++
YEAR=2022
DAYS=${patsubst src/day%.cc,%, ${wildcard src/day*.cc}}
DAY=$(lastword ${DAYS})
RUN=${foreach day,${DAYS},run${day}}
TEST=${foreach day,${DAYS},test${day}}

.PHONY: latest test all tests clean ${TEST} ${RUN}

latest: run${DAY}

test: test${DAY}

all: ${RUN}

tests: ${TEST}

${TEST}: test% : bin/day% test/day%
	cat test/day$* | ./$<
	@echo "\n"

${RUN}: run% : bin/day% input/day%
	cat input/day$* | ./$<
	@echo "\n"

bin/day%: src/day%.cc
	${CC} $< -o $@

input/day%:
	curl -s -b session=${AOC_SESSION} -a "github.com/Zkrgu/aoc-2022 by xyzkrgu@gmail.com" https://adventofcode.com/${YEAR}/day/${patsubst 0%,%,$*}/input -o $@

clean:
	rm bin/*
