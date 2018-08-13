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

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?
Passing large structs by value is slow and can take up alot of memory.
We pass before and after by reference (instead of by value) to the
function "calculate" because passing large structs by value is slow and
takes up a lot of memory.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.
The for loop is the c = fgetc(fp) function call where fgetc
gets the next character from fp and advances the
position indicator in fp until (EOF). After that it goes through multiple if and else statments
The first is If the character is an alphabetical character or an apostrophe that is not at index 0 of the
word, the character is appended to the word array. The second Else if statement is if the
character is numerical, the word is ignored and we skip ahead to the
next word. Thirdly, the else if we hit a space or punctuation, we must have found a word, so it ends with a /0.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?
I think that the fscanf with a format string like "%s" will read each word at a time until it reaches white space.
If we used that besides fgetc, it would not work due to every charcter within the file not being an arrangement of words.
If a longer string than expected was read using fscanf, it can cause a segmentation fault and possibly delete important memory.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?
the 'const' variable type is just reffering to making something constant and unchangeable anywhere else in your program.
For example, The parameters for check (const char* word)
and load (const char* dictionary) are declared as const pointers because
we want to prevent changes to a read word and the dictionary.
