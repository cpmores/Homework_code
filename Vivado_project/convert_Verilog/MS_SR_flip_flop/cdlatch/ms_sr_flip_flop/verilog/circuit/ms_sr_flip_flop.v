/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : ms_sr_flip_flop                                              **
 **                                                                          **
 *****************************************************************************/

module ms_sr_flip_flop( D,
                        Q,
                        Qbar,
                        clk,
                        mid_Q );

   /*******************************************************************************
   ** The inputs are defined here                                                **
   *******************************************************************************/
   input D;
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

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** Here all input connections are defined                                     **
   *******************************************************************************/
   assign s_logisimNet0 = clk;
   assign s_logisimNet1 = D;

   /*******************************************************************************
   ** Here all output connections are defined                                    **
   *******************************************************************************/
   assign Q     = s_logisimNet3;
   assign Qbar  = s_logisimNet2;
   assign mid_Q = s_logisimNet4;

   /*******************************************************************************
   ** Here all in-lined components are defined                                   **
   *******************************************************************************/

   // NOT Gate
   assign s_logisimNet5 = ~s_logisimNet0;

   /*******************************************************************************
   ** Here all sub-circuits are defined                                          **
   *******************************************************************************/

   C_D_latch   slave_latch (.C(s_logisimNet0),
                            .D(s_logisimNet4),
                            .Q(s_logisimNet3),
                            .Qbar(s_logisimNet2));

   C_D_latch   master_latch (.C(s_logisimNet5),
                             .D(s_logisimNet1),
                             .Q(s_logisimNet4),
                             .Qbar());

endmodule
