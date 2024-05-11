`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/05/09 15:04:57
// Design Name: 
// Module Name: tb_csr
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


module tb_csr(

    );
reg R;
reg C;
reg S;
wire Qbar;
wire Q;
C_SR_latch csrlatch( 
    .R(R),
    .C(C),
    .S(S),
    .Q(Q),
    .Qbar(Qbar)
);

initial begin
    C = 1'b0; R = 1'b0; S = 1'b1;
    #10; R = 1'b0; S = 1'b0;
    #10; R = 1'b1; S = 1'b0;
    #10; R = 1'b1; S = 1'b1;
    #10;
    C = 1'b1; R = 1'b0; S = 1'b1;
    #10; R = 1'b0; S = 1'b0;
    #10; R = 1'b1; S = 1'b0;
    #10; R = 1'b1; S = 1'b1;

end
endmodule
