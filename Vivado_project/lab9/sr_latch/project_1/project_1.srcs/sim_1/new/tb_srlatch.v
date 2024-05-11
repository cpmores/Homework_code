`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/05/09 14:24:12
// Design Name: 
// Module Name: tb_srlatch
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


module tb_srlatch(
    
    );
    
reg  R;
    reg  S;
     wire Q;
     wire Qbar;
     SR_latch sr_latch(
    .R(R), .S(S), .Q(Q), .Qbar(Qbar)
);


initial begin 
    R = 1'b0; S = 1'b1;
    #10; R = 1'b0; S = 1'b0;
    #10; R = 1'b1; S = 1'b0;
    #10; R = 1'b1; S = 1'b1;

end

endmodule
