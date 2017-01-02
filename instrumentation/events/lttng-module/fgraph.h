#undef TRACE_SYSTEM
#define TRACE_SYSTEM fgraph

#if !defined(LTTNG_TRACE_FGRAPH_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_FGRAPH_H

#include <probes/lttng-tracepoint-event.h>

LTTNG_TRACEPOINT_EVENT(fgraph_entry,
	TP_PROTO(unsigned long ip),
	TP_ARGS(ip),
	TP_FIELDS(
		ctf_integer_hex(unsigned long, ip, ip)
	)
)

// FIXME: fgraph_return has no payload. How can we define a tracepoint
// without argument? TP_PROTO() and TP_PROTO(void) failed to compile
LTTNG_TRACEPOINT_EVENT(fgraph_return,
	TP_PROTO(unsigned long ip,
        unsigned long long calltime,
        unsigned long long rettime),
	TP_ARGS(ip, calltime, rettime),
	TP_FIELDS(
        ctf_integer_hex(unsigned long, ip, ip)
        ctf_integer(unsigned long long, calltime, calltime)
        ctf_integer(unsigned long long, rettime, rettime)
    )
)

#endif /* LTTNG_TRACE_FGRAPH_H */

/* This part must be outside protection */
#include <probes/define_trace.h>
