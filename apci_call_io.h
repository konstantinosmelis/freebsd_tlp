/*
 *   Copyright (C) 2011 by Maxim Ignatenko
 *   gelraen.ua@gmail.com
 *
 *   All rights reserved.                                                  *
 *                                                                         *
 *   Redistribution and use in source and binary forms, with or without    *
 *    modification, are permitted provided that the following conditions   *
 *    are met:                                                             *
 *     * Redistributions of source code must retain the above copyright    *
 *       notice, this list of conditions and the following disclaimer.     *
 *     * Redistributions in binary form must reproduce the above copyright *
 *       notice, this list of conditions and the following disclaimer in   *
 *       the documentation and/or other materials provided with the        *
 *       distribution.                                                     *
 *                                                                         *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR *
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, *
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT      *
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, *
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY *
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   *
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE *
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *
 *
 */

#ifndef ACPI_CALL_IO_H
#define ACPI_CALL_IO_H

#include <sys/ioccom.h>
#if __FreeBSD__ >= 8
#	include <contrib/dev/acpica/include/actypes.h>
#else
#	include <contrib/dev/acpica/actypes.h>
#endif

/**
 *  _IOWR -> the kernel would read and write data in the user space
 * 'X' -> a block
 * 2nd param -> number to distinguish ioctls from eachother
 * 3rd param -> struct coming and going out of/into the kernel
 */
#define ACPIIO_CALL	_IOWR('X', 0x01, struct acpi_call_descr)

struct acpi_call_descr {
	char 				*path;
	ACPI_OBJECT_LIST	args;
	ACPI_STATUS			retval;
	ACPI_BUFFER			result;
	ACPI_SIZE			reslen; /* Actual length of data returned by AcpiEvaluateObject */
};

#endif // ACPI_CALL_IO_H
