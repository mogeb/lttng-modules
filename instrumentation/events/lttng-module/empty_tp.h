#if !defined(LTTNG_TRACE_EMPTY_MOD_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_EMPTY_MOD_H

#include "../../../probes/lttng-tracepoint-event.h"
#include <linux/version.h>

#undef TRACE_SYSTEM
#define TRACE_SYSTEM empty_tp

LTTNG_TRACEPOINT_EVENT(empty_ioctl_4b,
			TP_PROTO(int payload),
		TP_ARGS(payload),

	TP_FIELDS(
		ctf_integer(int, payload, payload)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_8b,
			TP_PROTO(int p1, int p2),
		TP_ARGS(p1, p2),

	TP_FIELDS(
		ctf_integer(int, p1, p1)
		ctf_integer(int, p2, p2)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_16b,
			TP_PROTO(int p1, int p2, int p3, int p4),
		TP_ARGS(p1, p2, p3, p4),

	TP_FIELDS(
		ctf_integer(int, p1, p1)
		ctf_integer(int, p2, p2)
		ctf_integer(int, p3, p3)
		ctf_integer(int, p4, p4)
	)
)

#endif /* LTTNG_TRACE_EMPTY_MOD_H */

/* This part must be outside protection */
#include "../../../probes/define_trace.h"
