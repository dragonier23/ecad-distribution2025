module updowncounter
  (
   input logic        clk,
   input logic        rst,
   input logic        up,
   output logic [3:0] count
   );

   // insert your code here
  always_ff @(posedge clk or posedge rst) begin
    if (rst)
      count <= 0; 
    else begin 
      if (up)
        count <= count + 1;
      else 
        count <= count - 1;
    end
  end


endmodule
