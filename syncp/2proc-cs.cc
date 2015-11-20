/* 2 processes, critical section problem */

bool lock = true
do {
    while (test_and_set(&lock))
        /* wait */;

    /* Critical Section */
    lock = false;
    /* Remainder Section */
} while(true);

/* 2 processes, critical section problem */

bool lock = true;
do {
    while (compare_and_swap(&lock, false, true) != 0)
        /* wait */;

    /* Critical Section */
    lock = false;
    /* Remainder Section */
} while(true);

