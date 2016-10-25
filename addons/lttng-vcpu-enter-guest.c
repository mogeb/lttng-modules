/*
 * addons/lttng-virtio-kick.c
 *
 * FIXME: Random experiment
 *
 * Copyright (C) 2015 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
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
#include <linux/kprobes.h>
#include <net/sock.h>
#include <linux/spinlock.h>
#include <linux/vhost.h>
#include "../wrapper/tracepoint.h"
#include "../lttng-abi.h"
#include <linux/kvm_host.h>

#include "../instrumentation/events/lttng-module/x86.h"
#include "../instrumentation/events/lttng-module/kvm_cache_regs.h"
#define LTTNG_INSTRUMENTATION
#include "../instrumentation/events/lttng-module/addons.h"

DEFINE_TRACE(addons_vcpu_enter_guest);

static int
lttng_vcpu_enter_guest_probe(struct kvm_vcpu *vcpu)
{
   //unsigned long sptmp = vcpu->arch.regs[VCPU_REGS_RSP];
   unsigned long iptmp = kvm_register_read(vcpu, VCPU_REGS_RIP); 
   unsigned long cr3tmp = kvm_read_cr3(vcpu);
   unsigned int vcpuID = vcpu->vcpu_id; 
   unsigned long sptmp= kvm_register_read(vcpu, VCPU_REGS_RSP);	
   trace_addons_vcpu_enter_guest(vcpuID,cr3tmp, sptmp,iptmp);
   jprobe_return();
   return 0;
}

static struct jprobe vcpu_enter_guest_jprobe = {
		.entry = lttng_vcpu_enter_guest_probe,
		.kp = {
			.symbol_name = "vcpu_enter_guest",
		},
};

static int __init lttng_addons_vcpu_enter_guest_init(void)
{
	int ret;

//	(void) wrapper_lttng_fixup_sig(THIS_MODULE);
	ret = register_jprobe(&vcpu_enter_guest_jprobe);
	if (ret < 0) {
		printk("register_jprobe failed, returned %d\n", ret);
		goto out;
	}

	printk("vcpu_enter_guest loaded\n");
out:
	return ret;
}
module_init(lttng_addons_vcpu_enter_guest_init);

static void __exit lttng_addons_vcpu_enter_guest_exit(void)
{
	unregister_jprobe(&vcpu_enter_guest_jprobe);
	printk("vcpu_enter_guest removed\n");
}
module_exit(lttng_addons_vcpu_enter_guest_exit);

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Hani Nemati <hani.nemati@gmail.com>");
MODULE_DESCRIPTION("LTTng vcpu_enter_guest event");

