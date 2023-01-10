`default_nettype none

module HP54542C_LCD2VGA(
	input wire iw_clk,
	input wire iw_sync,
	input wire iw_r0,
	input wire iw_g0,
	input wire iw_b0,
	output wire ow_r0,
	output wire ow_g0,
	output wire ow_b0,
	output wire ow_hsync,
	output wire ow_vsync,
	// output wire D_up,
	// output wire D_right,
	// output wire D_down,
	// output wire D_left,
	// output wire D_center
	output wire led_r,
	output wire led_g,
	output wire led_b
);

localparam p_hpixels_active = 640 - 1;
localparam p_vga_hfp = 16;
localparam p_vga_hsp = 96;
localparam p_vga_hbp = 48;
localparam p_vga_hpixels = p_hpixels_active + p_vga_hfp + p_vga_hsp + p_vga_hbp; // 800

localparam p_vpixels_active = 480 - 1;
localparam p_vga_vfp = 10;
localparam p_vga_vsp = 2;
localparam p_vga_vbp = 33;
localparam p_vga_vpixels = p_vpixels_active + p_vga_vfp + p_vga_vsp + p_vga_vbp; // 525

reg r_found_start = 1;
reg reset = 0;

reg [31:0] r32_clk_counter = 32'b0;
reg [31:0] r32_last_sync_pulse = 32'b0;

reg [9:0] hpos = 10'b0;
reg [9:0] vpos = 10'b0;

// assign D_up = 0;
// assign D_right = 0;
// assign D_down = 0;
// assign D_left = 0;
// assign D_center = r_found_start;

assign led_r = 1;
assign led_g = 1;
assign led_b = r_found_start;

// iw_[rgb][012] should be asserted to 0 during porches anyways, but let's
// make sure...
assign ow_r0 = (hpos < p_hpixels_active) && (vpos < p_vpixels_active) && r_found_start ? iw_r0 : 0;
assign ow_g0 = (hpos < p_hpixels_active) && (vpos < p_vpixels_active) && r_found_start ? iw_g0 : 0;
assign ow_b0 = (hpos < p_hpixels_active) && (vpos < p_vpixels_active) && r_found_start ? iw_b0 : 0;

assign ow_hsync = !((hpos > (p_hpixels_active + p_vga_hfp)) && (hpos < (p_hpixels_active + p_vga_hfp + p_vga_hsp)));
assign ow_vsync = !((vpos > (p_vpixels_active + p_vga_vfp)) && (vpos < (p_vpixels_active + p_vga_vfp + p_vga_vsp)));

always @(posedge iw_clk)
begin
	r32_clk_counter <= reset ? 0 : r32_clk_counter + 1;

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
		r32_last_sync_pulse <= 0;
	else
		r32_last_sync_pulse <= r32_last_sync_pulse + 1;

		if (r32_last_sync_pulse == (p_vga_hpixels) * ((p_vga_vfp + p_vga_vsp + p_vga_vbp - 1)) + 1003) // <- magic number!
		begin
			reset <= 1;
			if (!r_found_start)
				r_found_start <= 0;
		end
end

endmodule
