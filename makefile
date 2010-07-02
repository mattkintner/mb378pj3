cs:
	@echo `pwd`
	@rsync -r -t -u -v --delete \
	--include "*.html"          \
	--exclude "*"               \
	. downing@$(CS):cs/projects/date/

OS       := $(shell uname)
VALGRIND := $(shell which valgrind)

ifeq ($(OS), Darwin)
	BOOST :=
else
	BOOST := -I/public/linux/include/boost-1_38
endif

.PRECIOUS: %.c++.app
.PRECIOUS: %.class

TestDate.c++.app: TestDate.c++ Date.h
	g++ -ansi -pedantic $(BOOST) -lcppunit -ldl -Wall $< -o TestDate.c++.app

TestDate.class: TestDate.java Date.java
	javac -Xlint TestDate.java

TestDate.c++x: TestDate.c++.app
	$(VALGRIND) TestDate.c++.app

TestDate.javax: TestDate.class
	java -ea TestDate

TestDate.pyx:
	TestDate.py

clean:
	rm -f *.app
	rm -f *.class
	rm -f *.pyc

list:
	ls -al *.app
	ls -al *.class

test:
	make TestDate.c++x
	make TestDate.javax
	make TestDate.pyx
