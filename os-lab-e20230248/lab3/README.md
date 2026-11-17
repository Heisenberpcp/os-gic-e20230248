# Lab 3 — Wildcards, Hard Links and Symbolic Links: individual report

- Student name/ID: Chea Piseth / e20230248
- Ubuntu username: gic-chea-piseth
- My values (`oslab values lab3`): name = tiger, tag = backup, v1 = 566, v2 = 642
- Files: `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | `version 566` | `version 566` | `tiger.txt` |
| After the rename, before the repair | `version 566` | `cat: tiger-soft.txt: No such file or directory` | `tiger.txt` |
| After a new file took the old name | `version 566` | `version 642` | `tiger.txt` |
| After my repair | `version 566` | `version 566` | `tiger-backup.txt` |

My repair (the two commands I wrote):

```bash
rm -- tiger-soft.txt
ln -s tiger-backup.txt tiger-soft.txt
```

## Explanation

A symbolic link (`tiger-soft.txt`) stores the target path `tiger.txt` as text rather than pointing to an inode, so it always opens whichever file currently uses that name. When a new `tiger.txt` was created with inode `[inode of tiger.txt]`, `tiger-soft.txt` resolved to that new file and read `version 642`. In contrast, the hard link (`tiger-hard.txt`) points directly to the original file's inode (`[inode of tiger-backup.txt]`), which it shares with `tiger-backup.txt`. Because renaming `tiger.txt` to `tiger-backup.txt` kept its original inode number, `tiger-hard.txt` continued reading `version 566`.

## What My Tests Do Not Prove

Running `cat` only outputs the data bytes inside a file, so it cannot prove whether two names share the same inode or are separate copies with identical text. Only `ls -li` shows the inode numbers and link counts needed to prove that two names refer to the exact same file.

