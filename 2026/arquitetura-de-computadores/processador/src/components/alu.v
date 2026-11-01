module alu (
    input  logic [31:0] a,
    b,
    input  logic [ 2:0] alucontrol,
    output logic [31:0] result,
    output logic        zero
);
  // Conditional invert of B.
  logic [31:0] condinvb;
  logic [31:0] sum;
  logic v;
  logic isAddSub;
  logic slt;

  // If alucontrol[0], then we have a subtraction, so we have to two's complement b.
  assign condinvb = alucontrol[0] ? ~b : b;
  // Result of addition or subtraction.
  assign sum = a + condinvb + alucontrol[0];
  // Overflow detection only for arithmetic operations.
  assign isAddSub = (~alucontrol[2] & ~alucontrol[1]) | (~alucontrol[1] & alucontrol[0]);
  // Overflow flag.
  assign v = ~(alucontrol[0] ^ a[31] ^ b[31]) & (a[31] ^ sum[31]) & isAddSub;
  // Set on Less Than. The "^" is used to handle potential overflows.
  assign slt = sum[31] ^ v;

  always_comb
    case (alucontrol)
      3'b000:  result = sum;          // Addition.
      3'b001:  result = sum;          // Subtraction.
      3'b010:  result = a & b;        // Bitwise AND.
      3'b011:  result = a | b;        // Bitwise OR.
      3'b100:  result = a << b[4:0];  // Shift left.
      3'b101:  result = {31'b0, slt}; // Set on Less Than.
      3'b110:  result = a >> b[4:0];  // Shift right.
      3'b111:  result = a * b;        // Multiplication.
      default: result = 32'bx;        // Don't care.
    endcase

  assign zero = (result == 32'b0);
endmodule
