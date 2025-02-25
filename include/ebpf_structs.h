// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

// This file contains eBPF definitions common to eBPF programs, core execution engine
// as well as eBPF API library.

#pragma once

#include <stdint.h>
#include "../external/ebpf-verifier/src/ebpf_base.h"

typedef enum bpf_map_type
{
    BPF_MAP_TYPE_UNSPECIFIED = 0, ///< Unspecified map type.
    BPF_MAP_TYPE_HASH = 1,        ///< Hash table.
    BPF_MAP_TYPE_ARRAY = 2,       ///< Array, where the map key is the array index.
    BPF_MAP_TYPE_PROG_ARRAY =
        3, ///< Array of program fds usable with bpf_tail_call, where the map key is the array index.
    BPF_MAP_TYPE_PERCPU_HASH = 4,
    BPF_MAP_TYPE_PERCPU_ARRAY = 5,
    BPF_MAP_TYPE_HASH_OF_MAPS = 6,
    BPF_MAP_TYPE_ARRAY_OF_MAPS = 7,
} ebpf_map_type_t;

typedef enum ebpf_map_option
{
    // Create a new element or update an existing element.
    EBPF_ANY,
    // Create a new element only when it does not exist.
    EBPF_NOEXIST,
    // Update an existing element.
    EBPF_EXIST
} ebpf_map_option_t;

/**
 * @brief eBPF Map Definition.
 */
typedef struct _ebpf_map_definition
{
    uint32_t size;
    ebpf_map_type_t type;
    uint32_t key_size;
    uint32_t value_size;
    uint32_t max_entries;
    uint32_t inner_map_idx;
} ebpf_map_definition_t;
