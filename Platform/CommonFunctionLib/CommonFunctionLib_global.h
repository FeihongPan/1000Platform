#ifndef COMMONFUNCTIONLIB_GLOBAL_H
#define COMMONFUNCTIONLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COMMONFUNCTIONLIB_LIBRARY)
#  define COMMONFUNCTIONLIB_EXPORT Q_DECL_EXPORT
#else
#  define COMMONFUNCTIONLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // COMMONFUNCTIONLIB_GLOBAL_H