PCB=pcb
FILEBASE=haxpong
BOMFILE=${FILEBASE}.bom.txt
XYFILE=${FILEBASE}.xy.txt

default: gerber

gerber:
	${PCB} -x gerber --gerberfile ${FILEBASE} ${FILEBASE}.pcb
	mv *.gbr *.cnc ./haxpong-gerbers

# backend bom and bom2 need a file "attribs" in the local folder
bom:
	#gnetlist -g partslist3 -o $(FILEBASE).bom $(FILEBASE).sch
	#gnetlist -g partslist1 -o $(FILEBASE).bom $(FILEBASE).sch
	#gnetlist -g bom -o $(FILEBASE).bom $(FILEBASE).sch
	gnetlist -g bom2 -o $(FILEBASE).bom $(FILEBASE).sch

pcb:
	gsch2pcb --use-files --elements-dir ~/footprints $(FILEBASE).sch

pdf: $(FILEBASE).pdf

%.pdf: %.ps
	ps2pdf $< $@

%.ps: %.sch
	gschem -p -o $@ -s /usr/local/share/gEDA/scheme/print.scm $<

# use the following command to generate colored ps file
# gschem -p -o $(FILEBASE).ps -s /usr/share/gEDA/scheme/print.scm $(FILEBASE).sch

# ps to png workflow
# ps --(ps2epsi)--> epsi --(eps2png)--> png
#
png: $(FILEBASE).epsi
	./eps2png -width 1800 $(FILEBASE).epsi

drc:
	gnetlist -g drc2 -o - $(FILEBASE).sch

clean:
	rm -f *.gbr *.bom *.cnc *.pdf ${BOMFILE} ${XYFILE}

