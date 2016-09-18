/*
 * addons/lttng-vmsync-guest.c
 *
 * Periodic hypercall for VM trace synchronization - guest component
 *
 * Copyright (C) 2013 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; only
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/hrtimer.h>
#include <linux/random.h>
#include <linux/time.h>
#include <linux/kprobes.h>

#include <lttng-events.h>

#include "../wrapper/tracepoint.h"
#include "../lttng-abi.h"
#define LTTNG_INSTRUMENTATION


#define VMSYNC_HRTIMER_INTERVAL (10LL * NSEC_PER_MSEC)
#define RATE_LIMIT 3

static unsigned int count = 0;
static unsigned int rate_count = 0;
static unsigned long vm_uid = 0;
static int cpu = -1;

void fork_handler(struct task_struct *parent, struct task_struct *child)
{
	if (!strcmp(child->comm, "ruby"))
		printk("fork happened %s - %llu\n", child->comm, child->pid);
}

void exit_handler(void *__data, struct task_struct *p)
{
//	if (!strcmp(p->comm, "ruby"))
//		printk("exit happened %s - %llu\n", p->comm, p->pid);
	printk("%s\n", p->comm);
}

static int __init lttng_addons_vmsync_init(void)
{
	int ret;
	count = 0;
	rate_count = 0;

	get_random_bytes(&vm_uid, sizeof(vm_uid));

	(void) wrapper_lttng_fixup_sig(THIS_MODULE);

	ret = lttng_wrapper_tracepoint_probe_register("sched_process_fork",
			fork_handler, NULL);
	if (ret) {
		printk("tracepoint_probe_register sched_process_fork failed\n");
		return -1;
	}

	ret = lttng_wrapper_tracepoint_probe_register("sched_process_exit",
			exit_handler, NULL);
	if (ret) {
		printk("tracepoint_probe_register sched_process_exit failed\n");
		return -1;
	}

	printk("loaded on cpu %d with vm_uid %lu\n", cpu, vm_uid);
	return 0;
}
module_init(lttng_addons_vmsync_init);

static void __exit lttng_addons_vmsync_exit(void)
{
	lttng_wrapper_tracepoint_probe_unregister("sched_process_fork",
			fork_handler, NULL);
	lttng_wrapper_tracepoint_probe_unregister("sched_process_exit",
			exit_handler, NULL);

}
module_exit(lttng_addons_vmsync_exit);

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Mohamad Gebai <mohamad.gebai@polymtl.ca>");
MODULE_DESCRIPTION("LTTng vmsync guest events");
