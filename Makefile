PROJ = HP54542C_LCD2VGA
DEVICE = 1k
FOOTPRINT = tq144

FILES = $(PROJ).v

.PHONY: all clean burn

all:
	#yosys -q -p "synth_ice40 -blif $(PROJ).blif" $(FILES)
	yosys -q -l $(PROJ)-yosys.log -p "synth_ice40 -top $(PROJ) -json $(PROJ).json" $(FILES)
	#arachne-pnr -d $(DEVICE) -P $(FOOTPRINT) -p $(PROJ).pcf -o $(PROJ).txt $(PROJ).blif
	nextpnr-ice40 -q -l $(PROJ)-nextpnr.log --hx1k --package $(FOOTPRINT) --json $(PROJ).json --pcf $(PROJ).pcf --asc $(PROJ).asc
	#icepack $(PROJ).txt $(PROJ).bin
	icepack $(PROJ).asc $(PROJ).bin

burn:
	iceprog $(PROJ).bin

clean:
	$(RM) $(PROJ).blif $(PROJ).txt $(PROJ).bin
