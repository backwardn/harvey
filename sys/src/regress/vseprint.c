
/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <u.h>
#include <libc.h>
void
testvseprint(char *buf, int n, char *fmt, ...)
{
	va_list arg;

	va_start(arg, fmt);
	vseprint(buf, buf+n, fmt, arg);
	va_end(arg);
}

void
main()
{
	char buf[1024];
	char *str = "message";
	double dbl = 4.5;
	testvseprint(buf, sizeof(buf), "This is a really long %s %d %d %d %f", str, 1, 2, 3, dbl);
	if (strcmp(buf, "This is a really long message 1 2 3 4.500000")) {
		print("FAIL - incorrect string: '%s'\n", buf);
		exits("FAIL");
	}

	print("PASS\n");
	exits("PASS");
}
