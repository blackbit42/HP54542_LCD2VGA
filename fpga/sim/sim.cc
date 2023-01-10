#include <iostream>
#include <iomanip>
#include <vector>

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "VHP54542C_LCD2VGA.h"

void tick(unsigned int tickcount, VHP54542C_LCD2VGA *v, VerilatedVcdC *tfp);

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);
	VHP54542C_LCD2VGA *v = new VHP54542C_LCD2VGA;

	Verilated::traceEverOn(true);
	VerilatedVcdC *tfp = new VerilatedVcdC;

	v->trace(tfp, 99);
	tfp->open("trace.vcd");

	static const unsigned int hpixels_active = 640;
	static const unsigned int vga_hfp = 16;
	static const unsigned int vga_hsp = 96;
	static const unsigned int vga_hbp = 48;
	static const unsigned int vga_hpixels = hpixels_active + vga_hfp + vga_hsp + vga_hbp;

	static const unsigned int vpixels_active = 480;
	static const unsigned int vga_vfp = 10;
	static const unsigned int vga_vsp = 2;
	static const unsigned int vga_vbp = 33;
	static const unsigned int vga_vpixels = vpixels_active + vga_vfp + vga_vsp + vga_vbp;

	unsigned int pixelclock = 0;
	unsigned int last_1 = 0;
	unsigned int last_0 = 0;
	unsigned int frameclock = 0;
	std::vector<unsigned int> vec_1;
	std::vector<unsigned int> vec_0;

	v->iw_r0 = 2;
	v->iw_g0 = 4;
	v->iw_b0 = 8;
	v->iw_sync = 0;

	// one frame is 420k pixel (800 * 525)
	// let's do 3 frames
	for (unsigned int i = 0; i < 3 * 420 * 1000; i++) {
		tick(++pixelclock, v, tfp);

		if (pixelclock < 420000)
			frameclock++;
		else
			frameclock = 0;


		if (frameclock < vga_hpixels * vpixels_active) {
			if (pixelclock == !(pixelclock % (vga_hpixels + hpixels_active))) {
				v->iw_sync = 1;
				//printf("last 1: %u\n", pixelclock - last_1);
				vec_1.push_back(pixelclock - last_1);
				last_1 = pixelclock;
			}

			if (!(pixelclock % vga_hpixels)) {
				v->iw_sync = 0;
				//printf("last 0: %u\n", pixelclock - last_0);
				vec_0.push_back(pixelclock - last_0);
				last_0 = pixelclock;
			}
		}

	}

	for (unsigned int i: vec_1)
		std::cout << "last_1: " << i << std::endl;

	for (unsigned int i: vec_0)
		std::cout << "last_0: " << i << std::endl;

	return 0;
}

void tick(unsigned int pixelclock, VHP54542C_LCD2VGA *v, VerilatedVcdC *tfp)
{
	v->eval();
	if (tfp)
		tfp->dump(pixelclock * 10 - 2);

	v->iw_clk = 1;
	v->eval();
	std::cout << "pixelclock: " << std::setw(8) << pixelclock
		  << ", iw_clk: " << static_cast<unsigned int>(v->iw_clk)
		  << ", iw_sync: " << static_cast<unsigned int>(v->iw_sync)
		  << ", ow_hsync: " << static_cast<unsigned int>(v->ow_hsync)
		  << ", ow_vsync: " << static_cast<unsigned int>(v->ow_vsync)
		  << std::endl;
	if (tfp)
		tfp->dump(pixelclock * 10);

	v->iw_clk = 0;
	v->eval();
	if (tfp) {
		tfp->dump(pixelclock * 10 + 5);
		tfp->flush();
	}
}
