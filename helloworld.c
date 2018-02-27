#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_helloworld.h"

PHP_FUNCTION(helloworld)
{
    zval *name = NULL;
    ulong num_key;
    zend_string *key = NULL;
    zval *val;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|z", &name) == FAILURE) {
        return;
    }

    zval *zv = emalloc(sizeof(zval));

    if (name != NULL) {
        switch (Z_TYPE_P(name)) {
            case IS_STRING:
                php_printf("Hello %s!\n", Z_STRVAL_P(name));
                break;

            case IS_ARRAY:
                ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(name), num_key, key, val) {
                    if (Z_TYPE_P(val) == IS_STRING) {
                        php_printf("Hello %s!\n", Z_STRVAL_P(val));
                    }
                } ZEND_HASH_FOREACH_END();

                break;
        }
    } else {
        php_printf("Hello World!\n");
    }
}

PHP_MINIT_FUNCTION(helloworld)
{
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(helloworld)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(helloworld)
{
}

const zend_function_entry helloworld_functions[] = {
    PHP_FE(helloworld,	NULL)
    PHP_FE_END
};

zend_module_entry helloworld_module_entry = {
    STANDARD_MODULE_HEADER,
    "helloworld",
    helloworld_functions,
    PHP_MINIT(helloworld),
    PHP_MSHUTDOWN(helloworld),
    NULL,
    NULL,
    PHP_MINFO(helloworld),
    PHP_HELLOWORLD_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HELLOWORLD
ZEND_GET_MODULE(helloworld)
#endif
