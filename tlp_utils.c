#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "acpi_call_utils.h"
#include "acpi_call_io.h"

void parse_opts(int, char**);
void show_help(FILE*);

ACPI_OBJECT args[2][MAX_ACPI_ARGS];
char BATTERY_PATH_MAX_CHARGE[MAX_ACPI_PATH];
char BATTERY_PATH_MIN_CHARGE[MAX_ACPI_PATH];

int main(int argc, char* argv[]) {
	struct acpi_call_descr params_min_threshold;
	struct acpi_call_descr params_max_threshold;

	bzero(&params_min_threshold, sizeof(params_min_threshold));
	bzero(&params_max_threshold, sizeof(params_max_threshold));

	parse_opts(argc, argv);

	/* Min charge level */
	strcat(BATTERY_PATH_MIN_CHARGE, ".BCCS");
	params_min_threshold.path = BATTERY_PATH_MIN_CHARGE;
	params_min_threshold.args.Count = 1;
	params_min_threshold.args.Pointer = args[0];

	acpi_call_ioctl(params_min_threshold);

	/* Max charge level */
	strcat(BATTERY_PATH_MAX_CHARGE, ".BCSS");
	params_max_threshold.path = BATTERY_PATH_MAX_CHARGE;
	params_max_threshold.args.Count = 1;
	params_max_threshold.args.Pointer = args[1];

	acpi_call_ioctl(params_max_threshold);

	free(&params_min_threshold);
	free(&params_max_threshold);

	return 0;
}

void parse_opts(int argc, char* argv[]) {
	char c;

	while((c = getopt(argc, argv, "h:p:n:m:")) != -1) {
		switch(c) {
			case 'h':
				show_help(stdout);
				exit(0);
				break;
			case 'p':
				strlcpy(BATTERY_PATH_MIN_CHARGE, optarg, MAX_ACPI_PATH);
				strlcpy(BATTERY_PATH_MAX_CHARGE, optarg, MAX_ACPI_PATH);
				break;
			case 'n':
				args[0][0].Type = ACPI_TYPE_INTEGER;
				args[0][0].Integer.Value = strtol(optarg, NULL, 10);
				break;
			case 'm':
				args[1][0].Type = ACPI_TYPE_INTEGER;
				args[1][0].Integer.Value = strtol(optarg, NULL, 10);
				break;
			default:
				show_help(stdout);
				exit(0);
				break;
		}
	}
}

void show_help(FILE* file) {
	fprintf(file, "Help:\n");
	fprintf(file, "\t-h        - Show this help\n");
	fprintf(file, "\t-p path   - Specify the path to the battery\n");
	fprintf(file, "\t-n number - Specify the minimum charging point\n");
	fprintf(file, "\t-m number - Specify the maximum charging point\n");
}

