#ifndef ACPI_CALL_UTILS_H
#define ACPI_CALL_UTILS_H

#if __FreeBSD__ >= 8
#include <contrib/dev/acpica/include/acpi.h>
#else
#include <contrib/dev/acpica/acpi.h>
#endif
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/types.h>
#include <stdio.h>
#include "acpi_call_io.h"

#define	MAX_ACPI_PATH 1024
#define MAX_ACPI_ARGS 7

int acpi_call_ioctl(struct acpi_call_descr);

#endif
