PROJ = HP54542C_LCD_to_VGA
DEVICE = 1k
FOOTPRINT = tq144

FILES = HP54542C_LCD_to_VGA.v

.PHONY: all clean burn

all:
	#yosys -q -p "synth_ice40 -blif $(PROJ).blif" $(FILES)
	yosys -q -p "synth_ice40 -top $(PROJ) -json $(PROJ).json" $(FILES)
	#arachne-pnr -d $(DEVICE) -P $(FOOTPRINT) -p $(PROJ).pcf -o $(PROJ).txt $(PROJ).blif
	nextpnr-ice40 --hx1k --package $(FOOTPRINT) --json $(PROJ).json --pcf $(PROJ).pcf --asc $(PROJ).asc
	#icepack $(PROJ).txt $(PROJ).bin
	icepack $(PROJ).asc $(PROJ).bin

burn:
	iceprog $(PROJ).bin

clean:
	$(RM) $(PROJ).blif $(PROJ).txt $(PROJ).bin