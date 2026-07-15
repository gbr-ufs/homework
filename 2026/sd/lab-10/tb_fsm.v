`include "fsm_estrutural.v"

`timescale 1ns/1ps

module fsm_tb;

    // Entradas
    reg CLK;
    reg RST;
    reg BTN;

    // Saídas
    wire VE_G;
    wire VE_R;
    wire PE_G;
    wire PE_R;

    // Clock de 1 Hz (período de 1s = 1_000_000_000ns)
    always #500_000_000 CLK = ~CLK;

    // Instanciação do DUT com parâmetros
    fsm_estrutural estrutural (
        .CLK(CLK),
        .RST(RST),
        .BTN(BTN),
        .VE_G(VE_G),
        .VE_R(VE_R),
        .PE_G(PE_G),
        .PE_R(PE_R)
    );

    initial begin
        // Inicializa sinais
        CLK = 0;
        RST = 1;
        BTN = 0;

        // Geração do arquivo VCD
        $dumpfile("fsm_sim.vcd");
        $dumpvars(0, fsm_tb);

        // Libera reset após 2s
        #2_000_000_000;
        RST = 0;

        // Aguarda 5 ciclos e pressiona botão
        #5_000_000_000;
        BTN = 1;

        // Mantém botão pressionado por 2s
        #2_000_000_000;
        BTN = 0;

        // Tempo total para completar um ciclo completo da FSM
        #60_000_000_000;

        $finish;
    end

endmodule

