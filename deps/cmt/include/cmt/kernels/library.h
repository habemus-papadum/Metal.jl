/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_library_h
#define cmt_library_h
#ifdef __cplusplus
extern "C" {
#endif

#include "cmt/common.h"
#include "cmt/types.h"
#include "cmt/enums.h"
#include "cmt/error.h"

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtNewDefaultLibrary(MtDevice *device);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtNewLibraryWithFile(MtDevice *device, const char *filepath, NsError **error);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.13), mt_ios(11.0))
MtLibrary*
mtNewLibraryWithURL(MtDevice *device, const char *url, NsError **error);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtNewLibraryWithSource(MtDevice *device, const char *source, MtCompileOptions *Opts, NsError **error);

MT_EXPORT
MtLibrary*
mtNewLibraryWithData(MtDevice *device, const void* buffer, size_t size, NsError **error);

MT_EXPORT
MtDevice*
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
mtLibraryDevice(MtLibrary *lib);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
const char*
mtLibraryLabel(MtLibrary *lib);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
void
mtLibraryLabelSet(MtLibrary *lib, const char *label);

MT_EXPORT
void
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
mtLibraryFunctionNames(MtLibrary *lib, size_t* count, const char **names);


#ifdef __cplusplus
}
#endif
#endif /* cmt_library_h */
