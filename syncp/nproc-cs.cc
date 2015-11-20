/* n processes, critical section problem. */
bool waiting[n], lock = false, key;
std::fill(waiting, waiting + n, false);
do {
    waiting[i] = true;
    key = true;
    while (waiting[i] && key)
        key = test_and_set(&lock);
    waiting[i] = false;
    /* critical section */
    j = (i + 1) % n;
    while ((j != i) && !waiting[j])
        j = (j + 1) % n;
    if (j == i)  /* no one is waiting */
        lock = false;  /* revoke ownership of lock, so that someone will claim it. */
    else
        waiting[j] = false;  /* transfer the ownership of lock to the jth process */
    /* remainder section */
} while (true);



