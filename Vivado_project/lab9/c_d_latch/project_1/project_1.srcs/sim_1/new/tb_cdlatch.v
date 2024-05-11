`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/05/09 16:13:23
// Design Name: 
// Module Name: tb_cdlatch
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_cdlatch(

    );
 reg D;
 reg C;
 wire Qbar;
 wire Q;
 C_D_latch cdlatch(
    .D(D),
    .C(C),
    .Qbar(Qbar),
    .Q(Q)
 );

 initial begin
     C = 1'b0; D = 1'b0;
     #10; D = 1'b1;
     #10; C = 1'b1; D = 1'b0;
     #10; D = 1'b1;
 end
endmodule
