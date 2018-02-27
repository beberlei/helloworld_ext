#ifndef PHP_HELLOWORLD_H
#define PHP_HELLOWORLD_H

extern zend_module_entry helloworld_module_entry;
#define phpext_helloworld_ptr &helloworld_module_entry

#define PHP_HELLOWORLD_VERSION "0.1.0"

#if defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_HELLOWORLD_API __attribute__ ((visibility("default")))
#else
#	define PHP_HELLOWORLD_API
#endif

#endif	/* PHP_HELLOWORLD_H */
