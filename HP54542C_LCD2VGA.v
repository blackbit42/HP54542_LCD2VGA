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
);

parameter p_hpixels_active = 640;
parameter p_vga_hfp = 16;
parameter p_vga_hsp = 96;
parameter p_vga_hbp = 48;
parameter p_vga_hpixels = p_hpixels_active + p_vga_hfp + p_vga_hsp + p_vga_hbp; // 800

parameter p_vpixels_active = 480;
parameter p_vga_vfp = 10;
parameter p_vga_vsp = 2;
parameter p_vga_vbp = 33;
parameter p_vga_vpixels = p_vpixels_active + p_vga_vfp + p_vga_vsp + p_vga_vbp; // 525

reg r_found_start = 0;
reg r_active_area = 0;
reg r_hsync;
reg r_vsync;
reg reset = 0;
// total number of pixels in one frame, including porches and sync: 420000
// smallest counter large enough to support that: 2 ** 19 == 524288
reg [18:0] r19_clk_counter = 18'b0;
// TODO: doesn't have to be that large
reg [18:0] r19_last_sync_pulse = 18'b0;

// iw_[rgb][012] should be asserted to 0 during porches anyways, but let's
// make sure...
assign ow_r0 = r_active_area ? iw_r0 : 0;
//assign ow_r1 = r_active_area ? iw_r1 : 0;
//assign ow_r2 = r_active_area ? iw_r2 : 0;
assign ow_g0 = r_active_area ? iw_g0 : 0;
//assign ow_g1 = r_active_area ? iw_g1 : 0;
//assign ow_g2 = r_active_area ? iw_g2 : 0;
assign ow_b0 = r_active_area ? iw_b0 : 0;
//assign ow_b1 = r_active_area ? iw_b1 : 0;
//assign ow_b2 = r_active_area ? iw_b2 : 0;

integer i;

always @(posedge iw_clk)
begin
	r19_clk_counter <= reset ? 0 : r19_clk_counter + 1;

	// Start generating sync pulses and RGB data only after successful
	// detection of frame boundary
	if (r_found_start)
	begin
		for (i = 0; i < p_vpixels_active; i = i + 1)
			if (r19_clk_counter >= (i * p_hpixels_active) && (r19_clk_counter < (i * p_hpixels_active + p_vga_hfp + p_vga_hsp + p_vga_hbp)))
				r_active_area <= 1;
			else
				r_active_area <= 0;

		for (i = 0; i < p_vga_vpixels; i = i + 1)

			if (r19_clk_counter >= (i * p_hpixels_active + p_vga_hfp) && (r19_clk_counter < (i * p_hpixels_active + p_vga_hfp + p_vga_hsp)))
				r_hsync <= 0;
			else
				r_hsync <= 1;

		if (r19_clk_counter >= (p_vga_hpixels * (p_vpixels_active + p_vga_vfp)) && (r19_clk_counter < (p_vga_hpixels * (p_vpixels_active + p_vga_vfp + p_vga_vsp))))
			r_vsync <= 0;
		else
			r_vsync <= 1;
	end
end

always @(posedge iw_sync)
begin
	// 1000 is arbitrary, everything greater than 800 should work
	// The sync signal is low during vertical front porch, sync pulse and
	// back porch. That's 36000 clock pulses.
	if ((r19_clk_counter - r19_last_sync_pulse) > 1000)
	begin
		reset <= 1;
		if (!r_found_start)
			r_found_start <= 1;
	end
	else
		r19_last_sync_pulse = r19_clk_counter;
end

endmodule
