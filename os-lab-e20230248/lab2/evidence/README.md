
# Lab 2 — Linux Navigation and File Management

- **Student name:** Chea Piseth
-  **ID  :** e20230248
- **Ubuntu username:** gic-chea-piseth
- **My values (`oslab values lab2`):** `file1 = "sales north.txt"`, `file2 = "travel claims.txt"`, `owner = Sales`, `reader = Marketing`, `third = HR`
- **Files:** `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv "sales north.txt" ../reports/` | `~/oslab-work/lab2/incoming` |
| Move the second file (absolute paths) | `mv "$OSLAB_WORKSPACE/lab2/incoming/travel claims.txt" "$OSLAB_WORKSPACE/lab2/reports/"` | `~/oslab-work/lab2` |
| Read the report from my reader department (relative path) | `cat "../../reports/sales north.txt"` | `~/oslab-work/lab2/TechCorp/Marketing` |
| The path error I made on purpose, and its message | **Command:** `cat "reports/sales north.txt"`<br>**Message:** `cat: 'reports/sales north.txt': No such file or directory` | `~/oslab-work/lab2/TechCorp/Marketing` |
| The relative path that fixed it | `../../reports/sales north.txt` | `~/oslab-work/lab2/TechCorp/Marketing` |

## Explanation

A correct file name can still result in a "No such file or directory" error if you use a relative path from the wrong starting folder. A relative path starts from your current directory (`pwd`), so if the folders you list don't exist exactly where you currently are, the system cannot find the file. The difference between the two commands is that `mv` (move) removes the file from its original location and places it in the new one, while `cp` (copy) leaves the original untouched and creates a duplicate. For example, when I used `mv` on my incoming files, they were no longer in `incoming/`, but when I used `cp` to put `sales north.txt` into `TechCorp/Sales/`, the original remained in `reports/`. 

## What My Tests Do Not Prove

Seeing a file name listed by `ls` only proves that the file exists, but it does not prove that its contents are correct or uncorrupted. To truly prove that the file was copied perfectly without changing any data, you must use the `cmp` command to compare the original and the copy byte by byte.
