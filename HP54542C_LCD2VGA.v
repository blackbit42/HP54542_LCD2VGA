`default_nettype none

module HP54542C_LCD2VGA(
	input wire iw_clk,
	input wire iw_sync,
	input wire iw_r0,
	//input wire iw_r1,
	//input wire iw_r2,
	input wire iw_g0,
	//input wire iw_g1,
	//input wire iw_g2,
	input wire iw_b0,
	//input wire iw_b1,
	//input wire iw_b2,
	//output wire ow_hsync,
	//output wire ow_vsync,
	output wire ow_r0,
	//output wire ow_r1,
	//output wire ow_r2,
	output wire ow_g0,
	//output wire ow_g1,
	//output wire ow_g2,
	output wire ow_b0,
	//output wire ow_b1,
	//output wire ow_b2,
	output wire ow_hsync,
	output wire ow_vsync,
	output wire D1, // up
	output wire D2, // right
	output wire D3, // down
	output wire D4, // left
	output wire D5 // center
);

localparam p_hpixels_active = 640 - 1;
localparam p_vga_hfp = 16;
localparam p_vga_hsp = 96;
localparam p_vga_hbp = 48;
localparam p_vga_hpixels = p_hpixels_active + p_vga_hfp + p_vga_hsp + p_vga_hbp; // 800

localparam p_vpixels_active = 480;
localparam p_vga_vfp = 10;
localparam p_vga_vsp = 2;
localparam p_vga_vbp = 33;
localparam p_vga_vpixels = p_vpixels_active + p_vga_vfp + p_vga_vsp + p_vga_vbp; // 525

// localparam srl = 300; // shift register length


reg r_found_start = 0;
//reg r_active_area = 0;
//reg r_hsync;
//reg r_vsync;
reg reset = 0;
// total number of pixels in one frame, including porches and sync: 420000
// smallest counter large enough to support that: 2 ** 19 == 524288

// xxx-verilator says this should be 32 bit wide
// %Warning-WIDTH: HP54542C_LCD2VGA.v:94:24: Operator GTE expects 32 bits on the LHS, but LHS's VARREF 'r19_clk_counter' generates 19 bits.
reg [31:0] r32_clk_counter = 32'b0;
// TODO: doesn't have to be that large
reg [31:0] r32_last_sync_pulse = 32'b0;
reg [31:0] r32_ticks_between_sync = 32'b0;

reg [24:0] clock_blinker = 25'b0;
reg clock_led = 0;
//reg [14:0] sync_blinker = 15'b0;
reg sync_led = 0;

reg [9:0] hpos = 10'b0;
reg [9:0] vpos = 10'b0;

// reg [srl-1:0] sr_r = 300'b0;
// reg [srl-1:0] sr_g = 300'b0;
// reg [srl-1:0] sr_b = 300'b0;

// iw_[rgb][012] should be asserted to 0 during porches anyways, but let's
// make sure...
//assign ow_r0 = r_active_area ? iw_r0 : 0;
assign ow_r0 = iw_r0;
//assign ow_r1 = r_active_area ? iw_r1 : 0;
//assign ow_r2 = r_active_area ? iw_r2 : 0;
//assign ow_g0 = r_active_area ? iw_g0 : 0;
assign ow_g0 = iw_g0;
//assign ow_g1 = r_active_area ? iw_g1 : 0;
//assign ow_g2 = r_active_area ? iw_g2 : 0;
//assign ow_b0 = r_active_area ? iw_b0 : 0;
assign ow_b0 = iw_b0;
//assign ow_b1 = r_active_area ? iw_b1 : 0;
//assign ow_b2 = r_active_area ? iw_b2 : 0;
assign ow_hsync = !((hpos > (p_hpixels_active + p_vga_hfp)) && (hpos < (p_hpixels_active + p_vga_hfp + p_vga_hsp)));
assign ow_vsync = !((vpos > (p_vpixels_active + p_vga_vfp)) && (vpos < (p_vpixels_active + p_vga_vfp + p_vga_vsp)));

assign D1 = r_found_start ? 1 : 0;
assign D2 = clock_led;
assign D3 = sync_led;
assign D4 = 0;
assign D5 = 1;

always @(posedge iw_clk)
begin
	r32_clk_counter <= reset ? 0 : r32_clk_counter + 1;

	// sr_r <= {sr_r[srl-2:0], iw_r0};
	// sr_g <= {sr_g[srl-2:0], iw_g0};
	// sr_b <= {sr_b[srl-2:0], iw_b0};

	if (reset)
	begin
		hpos <= 0;
		vpos <= 0;
		reset <= 0;
	end
	else if (hpos < p_vga_hpixels)
		hpos <= hpos + 1'b1;
	else
	begin
		hpos <= 0;
		if (vpos < p_vga_vpixels)
			vpos <= vpos + 1'b1;
		else
			vpos <= 0;
	end

	if (iw_sync)
	begin
		r32_ticks_between_sync <= r32_clk_counter - r32_last_sync_pulse;
		r32_last_sync_pulse <= r32_clk_counter;
		if (r32_ticks_between_sync > 1000)
			reset <= 1;
	end

	// Start generating sync pulses and RGB data only after successful
	// detection of frame boundary
	if (r_found_start)
	begin
	end

	if (clock_blinker == 25000000)
	begin
		clock_led <= clock_led ? 0 : 1;
		clock_blinker <= 25'b0;
	end
	else
		clock_blinker <= clock_blinker + 1;
end

// always @(posedge iw_sync)
// begin
// 	// 1000 is arbitrary, everything greater than 800 should work
// 	// The sync signal is low during vertical front porch, sync pulse and
// 	// back porch. That's 36000 clock pulses.
// 	if ((r32_clk_counter - r32_last_sync_pulse) > 1000)
// 	begin
// 		reset <= 1;
// 		if (!r_found_start)
// 			r_found_start <= 1;
// 	end
// 	else
// 	begin
// 		r32_last_sync_pulse <= r32_clk_counter;
// 		reset <= 0;
// 	end
// 
// 
// 	if (sync_blinker == 32000)
// 	begin
// 		sync_led <= sync_led ? 0 : 1;
// 		sync_blinker <= 15'b0;
// 	end
// 	else
// 		sync_blinker <= sync_blinker + 1;
// end

endmodule
