module imem (
    input  logic [31:0] a,
    output logic [31:0] rd
);
  logic [31:0] RAM[127:0];

  initial $readmemh("src/tests/matrix_multiply.txt", RAM);

  assign rd = RAM[a[31:2]];  // Word aligned.
endmodule
