module controller (
    input logic [6:0] op,
    input logic [2:0] funct3,
    input logic funct7b5,
    input logic funct7b0,
    input logic Zero,
    output logic [1:0] ResultSrc,
    output logic MemWrite,
    output logic [1:0] PCSrc,
    output logic ALUSrc,
    output logic RegWrite,
    output logic [1:0] Jump,
    output logic [1:0] ImmSrc,
    output logic [2:0] ALUControl
);
  logic [1:0] ALUOp;
  logic       Branch;
  logic       TakeBranch;

  maindec md (
      op,
      ResultSrc,
      MemWrite,
      Branch,
      ALUSrc,
      RegWrite,
      Jump,
      ImmSrc,
      ALUOp
  );

  aludec ad (
      op[5],
      funct3,
      funct7b5,
      funct7b0,
      ALUOp,
      ALUControl
  );

  always_comb
    case (funct3)
      3'b000:  TakeBranch = Zero;  // beq
      3'b001:  TakeBranch = ~Zero;  // bne
      default: TakeBranch = 1'b0;
    endcase

  always_comb
    if (Jump[1]) PCSrc = 2'b10;  // jalr (target = ALUResult)
    else if (Jump[0] | (Branch & TakeBranch))
      PCSrc = 2'b01;  // jal or taken branch (target = PCTarget)
    else PCSrc = 2'b00;  // PC + 4
endmodule
