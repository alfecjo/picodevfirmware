#ifndef _LWIPOPTS_H
#define _LWIPOPTS_H

#ifdef MQTT_CERT_INC
#define MEM_SIZE 8000
#endif

#include "lwipopts_examples_common.h"

#define MEMP_NUM_SYS_TIMEOUT        (LWIP_NUM_SYS_TIMEOUT_INTERNAL+1)

#ifdef MQTT_CERT_INC
#define LWIP_ALTCP               1
#define LWIP_ALTCP_TLS           1
#define LWIP_ALTCP_TLS_MBEDTLS   1
#ifndef NDEBUG
#define ALTCP_MBEDTLS_DEBUG  LWIP_DBG_ON
#endif


#undef TCP_WND
#define TCP_WND  16384
#endif 

#define MQTT_REQ_MAX_IN_FLIGHT 5

#endif
