#if !defined(LTTNG_TRACE_EMPTY_MOD_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_EMPTY_MOD_H

#include "../../../probes/lttng-tracepoint-event.h"
#include <linux/version.h>

#undef TRACE_SYSTEM
#define TRACE_SYSTEM empty_tp

LTTNG_TRACEPOINT_EVENT(empty_ioctl_1b,
			TP_PROTO(int payload),
	    TP_ARGS(payload),

	TP_FIELDS(
		ctf_integer(int, payload, payload)
	)
)

#endif /* LTTNG_TRACE_EMPTY_MOD_H */

/* This part must be outside protection */
#include "../../../probes/define_trace.h"
