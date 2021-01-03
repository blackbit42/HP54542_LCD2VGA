PROJ = HP54542C_LCD2VGA
DEVICE = 1k
FOOTPRINT = tq144
RES = 2048

FILES = $(PROJ).v

.PHONY: all clean burn

	#yosys -q -p "synth_ice40 -blif $(PROJ).blif" $(FILES)
	#arachne-pnr -d $(DEVICE) -P $(FOOTPRINT) -p $(PROJ).pcf -o $(PROJ).txt $(PROJ).blif
	#icepack $(PROJ).txt $(PROJ).bin
all:
	verilator -Wall -cc $(FILES)
	yosys -q -l $(PROJ)-yosys.log -p "synth_ice40 -top $(PROJ) -json $(PROJ).json" $(FILES)
	nextpnr-ice40 -q -l $(PROJ)-nextpnr.log --hx1k --package $(FOOTPRINT) --json $(PROJ).json --pcf $(PROJ).pcf --asc $(PROJ).asc --placed-svg $(PROJ)-placed.svg --routed-svg $(PROJ)-routed.svg
	icepack $(PROJ).asc $(PROJ).bin

burn:
	iceprog $(PROJ).bin

png:
	inkscape -w $(RES) -h $(RES) $(PROJ)-placed.svg --export-filename $(PROJ)-placed.png
	inkscape -w $(RES) -h $(RES) $(PROJ)-routed.svg --export-filename $(PROJ)-routed.png
clean:
	$(RM) $(PROJ).blif $(PROJ).txt $(PROJ).bin
