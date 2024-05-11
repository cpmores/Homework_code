/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : MS_SR_flip_flop                                              **
 **                                                                          **
 *****************************************************************************/

module MS_SR_flip_flop( Q,
                        Qbar,
                        R,
                        S,
                        clk,
                        mid_Q );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input R;
   input S;
   input clk;

   /*******************************************************************************
   ** The outputs are defined here                                               **
   *******************************************************************************/
   output Q;
   output Qbar;
   output mid_Q;

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire s_logisimNet0;
   wire s_logisimNet1;
   wire s_logisimNet2;
   wire s_logisimNet3;
   wire s_logisimNet4;
   wire s_logisimNet5;
   wire s_logisimNet6;
   wire s_logisimNet7;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimNet0 = S;
   assign s_logisimNet2 = clk;
   assign s_logisimNet3 = R;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign Q     = s_logisimNet5;
   assign Qbar  = s_logisimNet4;
   assign mid_Q = s_logisimNet1;

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // NOT Gate
   assign s_logisimNet7 = ~s_logisimNet2;

   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   C_SR_latch   master_latch (.C(s_logisimNet7),
                              .Q(s_logisimNet1),
                              .Qbar(s_logisimNet6),
                              .R(s_logisimNet3),
                              .S(s_logisimNet0));

   C_SR_latch   slave_latch (.C(s_logisimNet2),
                             .Q(s_logisimNet5),
                             .Qbar(s_logisimNet4),
                             .R(s_logisimNet6),
                             .S(s_logisimNet1));

endmodule
