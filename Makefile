SRCS=tlp.c
KMOD=freebsd_tlp

ACPI_UTILS_SRCS=acpi_call_utils.c
TLP_UTILS_SRCS=tlp_utils.c

tlp:
	${CC} ${ACPI_UTILS_SRCS} ${TLP_UTILS_SRCS} -I /sys -o tlp

.include <bsd.kmod.mk>
