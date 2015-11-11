CXXTEST_HOME = /Users/Jacob/Applications/cxxtest-4.4
CXXTEST_GEN = $(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE = $(CXXTEST_HOME)

.PHONY: all clean

all: runner

SListTestSuite.cpp: SListTestSuite.hpp
	$(CXXTEST_GEN) --error-printer $< -o $@

runner: SListTestSuite.cpp SListTestSuite.hpp SList.hpp
	g++ $< -I$(CXXTEST_INCLUDE) -o $@

clean:
	rm -f runner SListTestSuite.cpp
