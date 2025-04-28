C = /home/user/utils/riscv/bin/riscv64-unknown-linux-gnu-gcc
CFLAGS = -Os -nostdlib 
LD_GLAGS = -Tld/ch32v307.ld
OPT = -march=rv32imac -mabi=ilp32
OUT = firmware.bin
ISP = /home/user/utils/wchisp/wchisp
SOURCES = main.c ch32v307.c

build:
	${C} ${OPT} ${CFLAGS} ${LD_GLAGS} ${SOURCES} -o ${OUT}
	file ${OUT}

clean:
	rm ${OUT}

flash:
	${ISP} flash ${OUT}

info:
	${ISP} info





