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
#include <linux/lsm_hooks.h>

/*
struct security_operations pole_ops = {
	.name = "pole"
};
*/


/*
struct pole_audit_info {
#ifdef CONFIG_AUDIT
	struct comon_audit_data a;
	struct pole_audit_data sad;
#endif
}
*/


/*
 * pole_init - initialize the pole system
 * Returns 0
 */

/*
static void pole_ad_init(struct pole_audit_info *a, const char *func,
			       char type)
{
	memset(&a->sad, 0, sizeof(a->sad));
	a->a.type = type;
	a->a.smack_audit_data = &a->sad;
	a->a.smack_audit_data->function = func;
}
*/

static int pole_file_open (struct file * f, const struct cred *cred) {
	const char * filename = f->f_path.dentry->d_name.name;
	
	if(strcmp(filename, "denyMe"))
		return 0;	

	return -EACCES;
}

static struct security_hook_list pole_hooks[] = {
	LSM_HOOK_INIT(file_open,pole_file_open)
};

static __init int pole_init(void) {
	/* register with LSM */

	security_add_hooks(pole_hooks, ARRAY_SIZE(pole_hooks));
	printk(KERN_INFO "POLE: Hello sandbox!\n");
	return 0;
}


security_initcall(pole_init);

