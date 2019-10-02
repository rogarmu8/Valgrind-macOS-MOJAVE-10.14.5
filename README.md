# Valgrind-macOS-MOJAVE-10.14.5

## Installation: ##

This is just a suppression file generator mainly designed for C programming language but usable for other languages as well.
Valgrind for macOS MOJAVE sort of works, install the following version:

```brew install --HEAD https://raw.githubusercontent.com/LouisBrunner/valgrind-macos/master/valgrind.rb```


## Suppression File Generation for error suppression:##

After the installation, you will notice some errors in your valgrind tests, this is why I designed the file mentioned before.
With this file you will be capable of creating suppression files easily.

**First of all:**
Execute code with valgrind that you are completely sure that doesn't have errors.
Something like:
```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	return 0;
}
```
To execute it use:

```valgrind --leak-check=full --show-reachable=yes --error-limit=no --gen-suppressions=all --log-file=suppressions.log ./exe```

This will generate a log file called "suppressions.log"

**Secondly:**

Compile "SuppressionFileGenerator.c" file using gcc or any other C compilers and execute it as follows:

```./exe suppressions.log suppressions.supp```

This will generate your suppressions.supp file that can be used to run Valgrind as follows:

```valgrind --leak-check=full --suppressions=./suppresions.supp ./exe```

## Make the suppressions default: ##

When you are completely sure about the flawlessness of the suppression file, you can make the suppressions default, being no needed to use "--suppressions=" flag.

To do so, just copy the content of the suppression file and paste it at the end of the "default.supp" file under:

"usr/local/lib/valgrind/default.supp"

And you are ready to go!

PD: All the credits to Louis Brunner, just adding some hopefully useful information.
