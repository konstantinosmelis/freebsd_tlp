#include <stdio.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/module.h>
#include <sys/systm.h>
#include <sys/param.h>
#include <sys/kernel.h>
#if __FreeBSD__ >= 8
#	include <contrib/dev/acpica/include/acpi.h>
#else
#	include <contrib/dev/acpica/acpi.h>
#endif
#include <dev/acpica/acpiio.h>
#include "acpi_call_io.h"

static int tlp_loader(struct module *module, int event, void* args) {
	int retval = 0;

	switch(event) {
		case MOD_LOAD:
			printf("freebsd_tlp loaded");
			break;
		case MOD_UNLOAD:
			printf("freebsd_tlp unloaded");
			break;
		default:
			retval = EOPNOTSUPP;
			break;
	}

	return retval;
}

static moduledata_t tlp_mod = {
	"freebsd_tlp",
	tlp_loader,
	NULL
};

DECLARE_MODULE(freebsd_tlp, tlp_mod, SI_SUB_EXEC, SI_ORDER_ANY);
MODULE_DEPEND(freebsd_tlp, acpi, 1, 1, 1);

