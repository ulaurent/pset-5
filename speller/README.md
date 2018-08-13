# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

A word that means a lung disease caused by inhaling very fine ash and sand dust

## According to its man page, what does `getrusage` do?

getrusage - get information about resource utilization
The getrusage() function shall provide measures of the resources used by the current process or its terminated
and waited-for child processes. If the value of the who argument is RUSAGE_SELF,
information shall be returned about resources used by the current process.
If the value of the who argument is RUSAGE_CHILDREN, information shall be returned about resources used by the terminated
and waited-for children of the current process. If the child is never waited for
(for example, if the parent has SA_NOCLDWAIT set or sets SIGCHLD to SIG_IGN),
the resource information for the child process is discarded and not included in the resource information provided by getrusage().

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 members in a variable of type struct rusage.