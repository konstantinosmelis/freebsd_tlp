#include "acpi_call_utils.h"
#include "acpi_call_io.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioccom.h>

int acpi_call_ioctl(struct acpi_call_descr params) {
	int fd;
	char dev_path[MAX_ACPI_PATH];

	strcpy("/dev/acpi", dev_path);

	fd = open(dev_path, O_RDWR);
	if(fd < 0) {
		perror("fopen:");
		return 1;
	}
	if(ioctl(fd, ACPIIO_CALL, &params) == -1) {
		perror("oictl:");
		return 1;
	}

	return params.retval;
}

