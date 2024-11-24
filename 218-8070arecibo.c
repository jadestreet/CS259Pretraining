#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MESSAGE_WIDTH  23
#define MESSAGE_HEIGHT 73
#define MESSAGE_BITS   MESSAGE_WIDTH * MESSAGE_HEIGHT
#define MESSAGE_BYTES  (MESSAGE_BITS + 1) / 8
#define COLOR_POINTS   65
#define SLEEP          2000
#define CHARACTER      "\u25A0"
#define START_COLOR    "\e[1;%dm"

enum {
	NRM = 0x00,
	RED = 0x1F,
	GRN, YEL, BLU, PUR, CYA, WHT
};

static int message[MESSAGE_BYTES] = {
	0x02, 0xA8, 0x00, 0x50, 0x50, 0x12, 0x22, 0x25, 0x95, 0x55,
	0x52, 0x40, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x0D, 0x00,
	0x00, 0x1A, 0x00, 0x00, 0x54, 0x00, 0x00, 0xF8, 0x00, 0x00,
	0x00, 0x06, 0x1C, 0x61, 0x88, 0x00, 0x32, 0x1A, 0x31, 0x86,
	0xBE, 0xFB, 0xEF, 0x80, 0x00, 0x00, 0x10, 0x00, 0x04, 0x00,
	0x00, 0x00, 0x20, 0x00, 0x0F, 0xC0, 0x01, 0xF0, 0x00, 0x00,
	0x18, 0x61, 0xC6, 0x20, 0x20, 0x08, 0x68, 0x63, 0x9A, 0xFB,
	0xEF, 0xBE, 0x00, 0x00, 0x00, 0x40, 0xC0, 0x10, 0x01, 0x80,
	0x00, 0x83, 0x00, 0x3F, 0x06, 0x07, 0xC0, 0x0C, 0x00, 0x10,
	0x08, 0x04, 0x10, 0x30, 0x10, 0x18, 0x60, 0x40, 0x0C, 0x43,
	0x00, 0x01, 0x98, 0x00, 0x31, 0x0C, 0x01, 0x86, 0x04, 0x04,
	0x08, 0x04, 0x10, 0x18, 0x04, 0x40, 0x30, 0x08, 0x80, 0x20,
	0x20, 0x80, 0x80, 0x80, 0x80, 0x06, 0x00, 0xC0, 0x30, 0x04,
	0x75, 0x80, 0x08, 0x08, 0x00, 0x10, 0x7C, 0x00, 0x21, 0x74,
	0xB6, 0x04, 0xE4, 0xFE, 0xE1, 0xC1, 0xB8, 0x02, 0x83, 0xB2,
	0x05, 0x07, 0xE4, 0x0A, 0x0C, 0x08, 0x36, 0x00, 0x00, 0x00,
	0x00, 0x38, 0x20, 0x00, 0x75, 0x15, 0x54, 0xE0, 0x0A, 0xA0,
	0x00, 0x14, 0x00, 0x0F, 0x80, 0x00, 0x7F, 0xC0, 0x03, 0x80,
	0xE0, 0x0C, 0x00, 0x60, 0x34, 0x01, 0x60, 0xCC, 0x06, 0x61,
	0x14, 0x14, 0x42, 0x24, 0x48, 0x80, 0x45, 0x10, 0x00, 0x84,
	0x20, 0x01, 0x00, 0x40, 0x00, 0x94, 0x00, 0x79, 0xF4, 0xF0
};

static int color_points[COLOR_POINTS] = {
	0x0000, 0x007F, 0x00FD, 0x0260, 0x026B,
	0x0277, 0x0288, 0x028E, 0x029A, 0x02A5,
	0x02AD, 0x02BC, 0x02CB, 0x02D4, 0x02DD,
	0x02EA, 0x02F3, 0x0301, 0x0309, 0x0319,
	0x031E, 0x032F, 0x0333, 0x0347, 0x034C,
	0x035D, 0x0365, 0x0374, 0x037D, 0x038B,
	0x0395, 0x03A2, 0x03AC, 0x03BA, 0x03C2,
	0x03D0, 0x03D8, 0x0415, 0x0417, 0x042C,
	0x043B, 0x0441, 0x0452, 0x0457, 0x0460,
	0x046D, 0x0478, 0x0487, 0x048F, 0x049E,
	0x04A6, 0x04AE, 0x04B5, 0x04BD, 0x04C5,
	0x04CC, 0x04D4, 0x04DC, 0x04E2, 0x050A,
	0x056C, 0x0668, 0x0679, 0x067F, 0x0688
};

static int colors[COLOR_POINTS] = {
	WHT, PUR, GRN, WHT, GRN, WHT, GRN, WHT, GRN, WHT, GRN, WHT, BLU,
	WHT, BLU, WHT, BLU, WHT, BLU, WHT, BLU, WHT, BLU, WHT, BLU, WHT,
	BLU, WHT, BLU, WHT, BLU, WHT, BLU, WHT, BLU, WHT, BLU, RED, BLU,
	RED, BLU, RED, BLU, RED, WHT, RED, WHT, RED, WHT, RED, WHT, BLU,
	RED, WHT, BLU, RED, WHT, BLU, RED, YEL, PUR, WHT, BLU, WHT, BLU
};

static void usage(char *exec) {
	printf("%s [options] [<rate>]\n\n", exec);
	printf("Options:\n");
    printf("    -c,--color  Show message part colorings\n");
    printf("    -h,--help   Print this help message\n");
}

int main(int argc, char *argv[]) {
	int rc = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, byte = 0, bit = 0;
	int bit_counter = 0, color_counter = 0, show_colors = 0, sleep = SLEEP;

	if (argc > 1) {
		for (i = 1, l = argc; i < l; i++) {
			if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
				usage(argv[0]);

				rc = 1;
				goto end_transmission;
			} else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--color") == 0) {
				show_colors = 1;
			} else if (i == argc - 1) {
				sleep = atoi(argv[argc - 1]);
			}
		}
	}

	for (i = 0, j = MESSAGE_BYTES; i < j; i++) {
		byte = message[i];

		for (k = 0, l = 8; k < l; k++) {
			bit = (byte >> (7 - k)) & 0x01;

			if (show_colors != 0) {
				for (m = 0, n = COLOR_POINTS; m < n; m++) {
					if (bit_counter == color_points[m]) {
						printf(START_COLOR, colors[color_counter]);
						color_counter++;
						break;
					}
				}
			}

			printf("%s", bit == 1 ? CHARACTER : " ");

			if ((bit_counter + 1) % MESSAGE_WIDTH == 0) {
				printf("\n");
			}

			if (bit_counter == MESSAGE_BITS) {
				goto end_transmission;
			}

			bit_counter++;

			if (sleep > 0) {
				usleep(sleep);
			}
		}
	}

end_transmission:
	printf(START_COLOR, NRM);

	return rc;
}