.PHONY: all clean

all:
        # "-g2012" é usado para suporte ao SystemVerilog.
	iverilog -g2012 -o sim src/components/*.v src/core/*.v src/top.v src/tests/testbench.v
	vvp -n sim

clean:
	rm -f sim
