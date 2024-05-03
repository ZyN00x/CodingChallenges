## Description
My own implementation for the `[cat](https://www.gnu.org/software/coreutils/manual/html_node/cat-invocation.html#cat-invocation)` utility in C++.

## Usage
1. `cccat test.txt` : basic file content viewer.
2. `head -n1 test.txt | cccat -` : prints the first line in the file.
3. `cccat test.txt test2.txt` : concatentate the 2 files.
4. `head -n3 test.txt | cccat -n`: prints the first 3 lines but numbered.
5. `sed G test.txt | cccat -n | head -n4` : prints the lines with blank line between each line and all are numbered.
6. `sed G test.txt | cccat -b | head -n5` : prints the lines with blank line between each line and only non-blank lines are numbered.


## Compilation

```bash
g++ -o cccat cccat.cpp
sudo mv cccat usr/bin
cccat `[options]`
```