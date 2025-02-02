/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_function_h
#define cmt_function_h
#ifdef __cplusplus
extern "C" {
#endif

#include "cmt/common.h"
#include "cmt/types.h"
#include "cmt/enums.h"

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtFunction*
mtNewFunctionWithName(MtLibrary *lib, const char *name);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.12), mt_ios(10.0))
MtFunction*
mtNewFunctionWithNameConstantValues(MtLibrary *lib, const char *name, MtFunctionConstantValues *constantValues, NsError **error);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtDevice*
mtFunctionDevice(MtFunction* fun);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.12), mt_ios(10.0))
const char*
mtFunctionLabel(MtFunction* fun);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.12), mt_ios(10.0))
void
mtFunctionLabelSet(MtFunction *fun, const char* label);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtFunctionType
mtFunctionType(MtFunction* fun);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
const char*
mtFunctionName(MtFunction* fun);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.12), mt_ios(10.0))
MtAttribute**
mtFunctionStageInputAttributes(MtFunction* fun);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(11.0), mt_ios(14.0))
MtFunctionDescriptor*
mtNewFunctionDescriptor(void);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(11.0), mt_ios(14.0))
const char*
mtFunctionDescriptorName(MtFunctionDescriptor *desc);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(11.0), mt_ios(14.0))
void
mtFunctionDescriptorNameSet(MtFunctionDescriptor *desc, const char *name);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(11.0), mt_ios(14.0))
const char*
mtFunctionDescriptorSpecializedName(MtFunctionDescriptor *desc);

MT_EXPORT
MT_API_AVAILABLE(mt_macos(11.0), mt_ios(14.0))
void
mtFunctionDescriptorSpecializedNameSet(MtFunctionDescriptor *desc, const char *specializedName);

#ifdef __cplusplus
}
#endif
#endif /* cmt_function_h */
