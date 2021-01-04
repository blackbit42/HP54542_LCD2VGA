PROJ = HP54542C_LCD2VGA
DEVICE = 1k
FOOTPRINT = tq144
RES = 2048
VINC = /usr/share/verilator/include

FILES = rtl/$(PROJ).v

.PHONY: all clean burn png

	#yosys -q -p "synth_ice40 -blif $(PROJ).blif" $(FILES)
	#arachne-pnr -d $(DEVICE) -P $(FOOTPRINT) -p $(PROJ).pcf -o $(PROJ).txt $(PROJ).blif
	#icepack $(PROJ).txt $(PROJ).bin
all:
	verilator -Wall --lint-only $(FILES)
	yosys -q -l log/$(PROJ)-yosys.log -p "synth_ice40 -top $(PROJ) -json tmp/$(PROJ).json" $(FILES)
	nextpnr-ice40 -q -l log/$(PROJ)-nextpnr.log --hx1k --package $(FOOTPRINT) --json tmp/$(PROJ).json --pcf rtl/$(PROJ).pcf --asc tmp/$(PROJ).asc --placed-svg images/$(PROJ)-placed.svg --routed-svg images/$(PROJ)-routed.svg
	icepack tmp/$(PROJ).asc bitstream/$(PROJ).bin

sim: sim/sim.cc
	verilator -Wall --trace -cc $(FILES)
	$(MAKE) -C rtl/obj_dir -f V$(PROJ).mk
	g++ \
		-Wall \
		-I $(VINC) \
		-I rtl/obj_dir/ \
		$(VINC)/verilated.cpp \
		$(VINC)/verilated_vcd_c.cpp \
		sim/sim.cc \
		rtl/obj_dir/V$(PROJ)__ALL.a \
		-o sim/sim
burn:
	iceprog bitstream/$(PROJ).bin

png: images/$(PROJ)-placed.svg images/$(PROJ)-routed.svg
	inkscape -w $(RES) -h $(RES) images/$(PROJ)-placed.svg --export-filename images/$(PROJ)-placed.png
	inkscape -w $(RES) -h $(RES) images/$(PROJ)-routed.svg --export-filename images/$(PROJ)-routed.png
clean:
	$(RM) $(PROJ).blif $(PROJ).txt $(PROJ).bin
