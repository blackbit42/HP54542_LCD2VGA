# Conversion of HP 54520C / 54540C oscilloscopes to VGA display(s)

The HP 54520C / 54540C series of oscilloscopes is equipped with color LCD displays, in contrast to their non-C predecessors which had monochrome CRT displays. While the multi-color display is nice in principle, the LCDs that were used unfortunately commonly failed. Those scopes are still quite capable by 2023 standards, hence worth preserving. The content of this repository is a conversion of the scope to VGA through a FPGA bitstream and a PCB design that is using an [UPduino](https://tinyvision.ai/products/upduino-v3-1) as a daughterboard.

Pretty much the same hack has been done before by [Adil Malik](https://hackaday.com/2017/06/01/fpga-rescues-scope-from-the-dumpster/), though now FPGA and PCB designs are made available for other people to reproduce.

# Implementation details

The PCB is designed to have mounting holes placed in distance to be compatible with [VESA MIS-D (75x75)](https://en.wikipedia.org/wiki/Flat_Display_Mounting_Interface), which allows the PCB to be mounted sturdily at the backside of the used VGA TFT inside the scope.

Hirose DF13 connectors are stipulated on the PCB so that the original LCD cables don't have to be modified.

The PCB and UPduino are powered from the LCD connections. The VGA TFT is powered from the scope PSU.

The entire modification of the instrument is non-invasive and can be undone if desired.

## Findings

HP decided to mount the LCD panel upside down. Probably as that was convenient is regards to the position of the connectors. An implication of that is that the internal VGGA monitor is mounted upside down as well (which doesn't make a difference really) and that an external monitor must be rotated as well. If one would desire to change that, a frame buffer must be implemented in the FPGA, which isn't hard to do but required more RAM than the UPduino has.

## Errata

Rev.1 of the PCB design contains an error. The footprint for the UPduino is 0.2" too narrow. I fixed this with infamous offset-pinheaders of shame. Keep this in mind if you intend to get a PCB produced. Patches welcome :-)

## PCBs

As of 10 Jan 2023 I have some spare PCBs in stock. Get in touch via the email address I've used for the commits if you want one.

## Pictures

![1.jpeg](https://github.com/blackbit42/HP54542_LCD2VGA/raw/main/images/1.jpeg)

![2.jpeg](https://github.com/blackbit42/HP54542_LCD2VGA/raw/main/images/2.jpeg)

![3.jpeg](https://github.com/blackbit42/HP54542_LCD2VGA/raw/main/images/3.jpeg)

![4.jpeg](https://github.com/blackbit42/HP54542_LCD2VGA/raw/main/images/4.jpeg)

![5.jpeg](https://github.com/blackbit42/HP54542_LCD2VGA/raw/main/images/5.jpeg)
