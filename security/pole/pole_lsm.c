/*
 *  test Linux Security Module Pole
 *
 *  This file contains the pole hook function implementations.
 *
 *  Authors:
 *	totem <kyarioka7946@gmail.com>
 *
 *  Copyright (C) 2016 totem
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2,
 *      as published by the Free Software Foundation.
 */

#include <linux/security.h>

struct security_operations pole_ops = {
	.name = "pole"
};

/*
 * pole_init - initialize the pole system
 * Returns 0
 */
static __init int pole_init(void) {
	/* register with LSM */
	if(register_security(&polr_ops))
		panic("pole: Unable to register with kernel.\n");

	printk(KERN_INFO "POLE: Hello sandbox!\n");
	return 0;
}
