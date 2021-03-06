/*
 * Copyright (c) 2013 Nicira, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include_next <stdio.h>

#if !defined STDIO_H_WRAPPER
#define STDIO_H_WRAPPER 1

#ifdef _WIN32

#include <stdarg.h>
#include <stddef.h>
#include <sys/types.h>

/* Windows libc has defective snprintf() and vsnprintf():
 *
 *     - They return -1 if the output won't fit.
 *
 *     - They don't null-terminate the output if it won't fit.
 *
 * We need working versions so here we define substitutes. */
#undef snprintf
#define snprintf ovs_snprintf
int ovs_snprintf(char *, size_t, const char *, ...);

#undef vsnprintf
#define vsnprintf ovs_vsnprintf
int ovs_vsnprintf(char *, size_t, const char *, va_list);

int fseeko(FILE *stream, off_t offset, int whence);
#endif /* _WIN32 */

#endif /* stdio.h wrapper */
