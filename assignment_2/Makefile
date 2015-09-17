PROGRAMS = Arith Assign Choose Compute Countdown Ending Example Multiply Negative Odd OddEven

all: $(PROGRAMS)

%: %.cpp
	g++ $< -o $@

clean:
	rm -f $(PROGRAMS)
