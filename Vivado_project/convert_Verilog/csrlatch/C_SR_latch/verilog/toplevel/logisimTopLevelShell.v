/******************************************************************************
 ** Logisim-evolution goes FPGA automatic generated Verilog code             **
 ** https://github.com/logisim-evolution/                                    **
 **                                                                          **
 ** Component : logisimTopLevelShell                                         **
 **                                                                          **
 *****************************************************************************/

module logisimTopLevelShell(  );

   /*******************************************************************************
   ** The wires are defined here                                                 **
   *******************************************************************************/
   wire s_C;
   wire s_Q;
   wire s_Qbar;
   wire s_R;
   wire s_S;

   /*******************************************************************************
   ** The module functionality is described here                                 **
   *******************************************************************************/

   /*******************************************************************************
   ** All signal adaptations are performed here                                  **
   *******************************************************************************/
   assign s_C = 1'b0;
   assign s_R = 1'b0;
   assign s_S = 1'b0;

   /*******************************************************************************
   ** The toplevel component is connected here                                   **
   *******************************************************************************/
   C_SR_latch   CIRCUIT_0 (.C(s_C),
                           .Q(s_Q),
                           .Qbar(s_Qbar),
                           .R(s_R),
                           .S(s_S));
endmodule
