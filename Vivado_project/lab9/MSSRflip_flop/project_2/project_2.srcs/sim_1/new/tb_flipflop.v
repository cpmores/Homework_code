`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/05/09 16:33:42
// Design Name: 
// Module Name: tb_flipflop
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


module tb_flipflop(

    );
reg D;
reg clk;
wire Qbar;
wire Q;
wire mid_Q;
ms_sr_flip_flop mssrflipflop(
    .D(D),
    .clk(clk),
    .Qbar(Qbar),
    .Q(Q),
    .mid_Q(mid_Q)
);

initial begin
    clk = 1'b1; D = 1'b1;
    #5; clk = 1'b0; D = 1'b0;
    #5; clk = 1'b0; D = 1'b1;
    #5; clk = 1'b1; D = 1'b0;
end

endmodule
