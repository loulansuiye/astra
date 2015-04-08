#ifndef SENSEKIT_TYPES_H
#define SENSEKIT_TYPES_H

#include <stdint.h>
#include <stddef.h>

const unsigned MAX_STRING_FIELD_LENGTH = 256;
const uint8_t SENSEKIT_MAX_READER_STREAMS = 16;

const int SENSEKIT_TIMEOUT_FOREVER = -1;
const int SENSEKIT_TIMEOUT_RETURN_IMMEDIATELY = 0;

typedef struct _sensekit_stream* sensekit_stream_t;

typedef int32_t sensekit_stream_type_t;
typedef int32_t sensekit_stream_subtype_t;
typedef int32_t sensekit_frame_index_t;

const sensekit_stream_subtype_t ANY_SUBTYPE = -1;

struct sensekit_stream_desc_t {
    sensekit_stream_type_t type;
    sensekit_stream_subtype_t subType;
};

typedef struct _sensekit_streamset* sensekit_streamset_t;
typedef struct _sensekit_streamconnection_handle* sensekit_streamconnection_handle_t;

typedef struct _sensekit_streamconnection* sensekit_streamconnection_t;

typedef struct _sensekit_frame_ref sensekit_frame_ref_t;
typedef struct _sensekit_frame sensekit_frame_t;

typedef struct _sensekit_reader* sensekit_reader_t;
typedef sensekit_reader_t sensekit_reader_frame_t;

typedef struct _sensekit_parameter_data sensekit_parameter_data_t;
typedef int32_t sensekit_parameter_id;

typedef struct _sensekit_bin* sensekit_bin_t;

typedef enum _sensekit_status {
    SENSEKIT_STATUS_SUCCESS = 0,
    SENSEKIT_STATUS_INVALID_PARAMETER = 1,
    SENSEKIT_STATUS_DEVICE_ERROR = 2,
    SENSEKIT_STATUS_TIMEOUT = 3
} sensekit_status_t;

typedef struct _sensekit_device_desc {
    char uri[MAX_STRING_FIELD_LENGTH];
    char vendor[MAX_STRING_FIELD_LENGTH];
    char name[MAX_STRING_FIELD_LENGTH];
    uint16_t usbVendorId;
    uint16_t usbProductId;
} sensekit_device_desc_t;

typedef size_t sensekit_callback_id_t;

typedef struct _sensekit_reader_callback_id* sensekit_reader_callback_id_t;

typedef void(*sensekit_frame_ready_callback_t)(sensekit_reader_t reader,
                                               sensekit_reader_frame_t frame, 
                                               void* clientTag);

#endif /* SENSEKIT_TYPES_H */
