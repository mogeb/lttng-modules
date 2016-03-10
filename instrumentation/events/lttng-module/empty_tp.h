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
	TP_PROTO(char payload[8]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 8)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_16b,
	TP_PROTO(char payload[16]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 16)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_32b,
	TP_PROTO(char payload[32]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 32)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_64b,
	TP_PROTO(char payload[64]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 64)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_128b,
	TP_PROTO(char payload[128]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 128)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_192b,
	TP_PROTO(char payload[192]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 192)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_256b,
	TP_PROTO(char payload[256]),
	TP_ARGS(payload),

	TP_FIELDS(
		ctf_array(char, payload, payload, 256)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_512b,
	TP_PROTO(char p1[256], char p2[256]),
	TP_ARGS(p1, p2),

	TP_FIELDS(
		ctf_array(char, p1, p1, 256)
		ctf_array(char, p2, p2, 256)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_768b,
	TP_PROTO(char p1[256], char p2[256],
			 char p3[256]),
	TP_ARGS(p1, p2, p3),

	TP_FIELDS(
		ctf_array(char, p1, p1, 256)
		ctf_array(char, p2, p2, 256)
		ctf_array(char, p3, p3, 256)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_1kb,
	TP_PROTO(char p1[256], char p2[256],
			 char p3[256], char p4[256]),
	TP_ARGS(p1, p2, p3, p4),

	TP_FIELDS(
		ctf_array(char, p1, p1, 256)
		ctf_array(char, p2, p2, 256)
		ctf_array(char, p3, p3, 256)
		ctf_array(char, p4, p4, 256)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_1p5kb,
	TP_PROTO(char p1[256], char p2[256],
			 char p3[256], char p4[256],
			 char p5[256], char p6[256]),
	TP_ARGS(p1, p2, p3, p4, p5, p6),

	TP_FIELDS(
		ctf_array(char, p1, p1, 256)
		ctf_array(char, p2, p2, 256)
		ctf_array(char, p3, p3, 256)
		ctf_array(char, p4, p4, 256)
		ctf_array(char, p5, p5, 256)
		ctf_array(char, p6, p6, 256)
	)
)

LTTNG_TRACEPOINT_EVENT(empty_ioctl_2kb,
	TP_PROTO(char p1[256], char p2[256],
			 char p3[256], char p4[256],
			 char p5[256], char p6[256],
			 char p7[256], char p8[256]),
	TP_ARGS(p1, p2, p3, p4, p5, p6, p7, p8),

	TP_FIELDS(
		ctf_array(char, p1, p1, 256)
		ctf_array(char, p2, p2, 256)
		ctf_array(char, p3, p3, 256)
		ctf_array(char, p4, p4, 256)
		ctf_array(char, p5, p5, 256)
		ctf_array(char, p6, p6, 256)
		ctf_array(char, p7, p7, 256)
		ctf_array(char, p8, p8, 256)
	)
)
#endif /* LTTNG_TRACE_EMPTY_MOD_H */

/* This part must be outside protection */
#include "../../../probes/define_trace.h"
