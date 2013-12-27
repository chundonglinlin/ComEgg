#include "CSem.h"

#include <sys/errno.h>

CSem::CSem(ub_4 value) {
    if (-1 == sem_init(&_sem, 0, value))
        __fatal("CSem::CSem: failed to call sem_init");
}

CSem::~CSem() {
    if (-1 == sem_destroy(&_sem))
        __fatal("CSem::~CSem: failed to call sem_destroy");
}

bool_ CSem::lock(bool_ check) {
    b_4 ret = 0;

    if (check) {
        ret = sem_trywait(&_sem);
    } else {
        ret = sem_wait(&_sem);
    }

    if (-1 == ret) {
        if (EBUSY == errno && check) {
            return false_v;
        }

        if (check) {
            __fatal("CSem::lock: failed to call sem_trywait");
        } else {
            __fatal("CSem::lock: failed to call sem_wait");
        }

        return false_v;
    }

    return true_v;
}

void CSem::unlock() {
    if (-1 == sem_post(&_sem)) {
        __fatal("CSem::unlock: failed to call sem_post");
    }
}

ub_4 CSem::getValue() {
    b_4 n = 0;

    if (-1 == sem_getvalue(&_sem, &n)) {
        __fatal("CSem::getValue: failed to call sem_getvalue");
    }

    return (ub_4) n;
}
