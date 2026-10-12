module testbench ();
  logic clk;
  logic reset;
  logic [31:0] WriteData, DataAdr;
  logic MemWrite;

  // Instantiate device to be tested.
  top dut (
      clk,
      reset,
      WriteData,
      DataAdr,
      MemWrite
  );

  // Initialize test.
  initial begin
    reset <= 1;
    #22;
    reset <= 0;
  end

  // Generate clock to sequence tests.
  always begin
    clk <= 1;
    #5;
    clk <= 0;
    #5;
  end

  // Timeout safeguard.
  initial begin
    #500000;
    $display("Simulation timed out!");
    $stop;
  end

  task check_matrix;
    logic [31:0] expected[0:15];
    int errors;
    expected = '{
        250,
        260,
        270,
        280,
        618,
        644,
        670,
        696,
        986,
        1028,
        1070,
        1112,
        1354,
        1412,
        1470,
        1528
    };
    errors = 0;
    for (int i = 0; i < 16; i++) begin
      if (dut.dmem.RAM[32+i] !== expected[i]) begin
        $display("Mismatch at C[%0d]: expected %0d, got %0d", i, expected[i], dut.dmem.RAM[32+i]);
        errors = errors + 1;
      end
    end
    if (errors == 0) begin
      $display("Simulation succeeded");
      $stop;
    end else begin
      $display("Simulation failed");
      $stop;
    end
  endtask

  // Check results.
  always @(negedge clk) begin
    if (MemWrite) begin
      if (DataAdr === 192 & WriteData === 1) begin
        check_matrix();
      end
    end
  end
endmodule
