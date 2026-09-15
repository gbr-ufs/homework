.PHONY: all clean

all:
	iverilog -g2012 -o sim src/components/*.v src/core/*.v src/top.v src/tests/testbench.v
	vvp -n sim

clean:
	rm -f sim
