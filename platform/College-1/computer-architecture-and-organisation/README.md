<ol type="1">
    <li> Write an OpenMP Program to:
        <ol type="a">
            <li> Print "Hello World" in multiple threads.
                <ul>
                    <li> `#pragma omp parallel { ... }`: This fundamental construct starts parallel execution. </li>
                </ul>
            </li>
            <li> Find number of threads running currently. </li>
                <ul>
                    <li> `omp_get_num_threads()` -> int: This routine returns the number of threads in the current team. </li>
                </ul>
            <li> Find maximum number of threads. </li>
                <ul>
                    <li> `omp_get_max_threads()` -> int: This routine returns the maximum number of threads available in the system. </li>
                </ul>
            <li> Find the Thread ID. </li>
                <ul>
                    <li> `omp_get_thread_num()` -> int: This routine returns the thread number (ID) of the currently running thread. </li>
                </ul>            
            <li> Find the number of processor cores in the system. </li>
                <ul>
                    <li> `omp_get_num_procs()` -> int: This routine returns the number of processor cores available to the program. </li>
                </ul>
            <li> Set the number of threads to be executed. </li>
                <ul>
                    <li> `omp_set_num_threads(numberOfThreads) ` -> boolean: This routine sets the number of threads to be executed within the parallel scope of the program. </li>
                </ul>
            <li> Test `is_parallel` function. </li>
                <ul>
                    <li> `omp_in_parallel()` -> boolean: This routine returns `true` if the call to the routine is enclosed by an active parallel region; otherwise, it returns `false`. </li>
                </ul>
            <li> Parallelize a simple `for` loop. </li>
                <ul>
                    <li> `#pragma omp parallel for`: The parallel loop construct is a shortcut for specifying a parallel construct containing one or more associated loops and no other statements. </li>
                </ul>          
        </ol>
    </li>
</ol>