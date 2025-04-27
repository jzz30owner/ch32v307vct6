C = /home/user/develpoment/libs/riscv_path/bin/riscv64-unknown-elf-gcc
CFLAGS = -Os -nostdlib 
LD_GLAGS = -Tld/ch32v307.ld
OPT = -march=rv32imac -mabi=ilp32
OUT = firmware.bin
ISP = /home/user/develpoment/tools/wchisp/target/release/wchisp
SOURCES = main.c

build:
	${C} ${OPT} ${CFLAGS} ${LD_GLAGS} ${SOURCES} -o ${OUT}
	file ${OUT}

clean:
	rm ${OUT}

flash:
	${ISP} flash ${OUT}

info:
	${ISP} info





