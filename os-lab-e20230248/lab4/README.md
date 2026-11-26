# Lab 4 — Redirection and Pipelines: individual report

Follow the [instruction](lab4-instruction.md). Copy this template into your own `lab4/README.md`. No script is required. Prediction/debrief/checkpoint answers stay in `oslab` records.

- Name / student ID: Chea Piseth / e20230248
- Linux account: gic-chea-piseth
- Personal status and other word: status = `sent`, other = `clear`

## Commands I Used

Save your actual commands, one per line, in `evidence/commands.txt`. Do not execute that file as a script.

| Stage | My command | Input received | Output produced |
|---|---|---|---|
| Select exact first field | `grep '^sent,' data/events.csv \| tee evidence/selected.txt` | `data/events.csv` (header + 6 records) | 3 exact `sent,...` rows printed to stdout and saved to `evidence/selected.txt` |
| Extract field 2 | `grep '^sent,' data/events.csv \| cut -d, -f2 \| tee evidence/fields.txt` | 3 matching CSV rows from `grep` via stdin | 3 second-column quantities printed to stdout and saved to `evidence/fields.txt` |
| Count selected records | `grep '^sent,' data/events.csv \| wc -l > evidence/normal.txt` | 3 matching CSV rows from `grep` via stdin | Line count `3` written to `evidence/normal.txt` |
| Save stdout and stderr separately | `cat data/missing.csv > evidence/stdout.txt 2> evidence/stderr.txt` | Missing file `data/missing.csv` | Empty `evidence/stdout.txt`; error message saved to `evidence/stderr.txt` |
| Save exit status immediately | `echo $? > evidence/status.txt` | Exit status of `cat` from shell variable `$?` | Nonzero exit status `1` saved to `evidence/status.txt` |

## What My Tests Show

| Test | Expected | Observed | Mistake it would catch |
|---|---|---|---|
| Original records | 3 exact matches | 3 exact `sent,...` rows in `selected.txt`, 3 quantities in `fields.txt`, count `3` in `normal.txt` | Prefix matching (`sent-late`) or including the CSV header row in the count |
| No match | 0 records | `0` written to `evidence/edge.txt` | Hardcoding a nonzero result or accidentally matching the `clear,2` row |
| One added match plus a look-alike | 4 records | `4` appended to `evidence/edge.txt` (resulting in lines `0` and `4`) | Prefix matching (`sent-late,99`), summing quantities (`+7` instead of `+1`), or overwriting `edge.txt` with `>` instead of `>>` |
| Missing input | empty stdout, diagnostic on stderr, nonzero status | `stdout.txt` is empty (0 bytes); `stderr.txt` contains `cat: data/missing.csv: No such file or directory`; `status.txt` contains `1` | Mixing error text into normal output, ignoring missing-file errors, or relying on a pipeline exit status (`0`) |

## Explain the Commands

1. **Why does the comma in `grep '^WORD,'` matter?**
   The trailing comma marks the exact boundary at the end of the first CSV field. Without it, `^sent` would match prefix look-alikes such as `sent-late,99`.
2. **Why does `wc -l` count records here, rather than add quantities?**
   `wc -l` counts newline characters (lines) arriving on standard input. Because each matching CSV row occupies one line, counting lines returns the number of matching records rather than summing the numbers in column 2.
3. **Where did you use `>>`, and what would `>` do instead?**
   I used `>>` in Core 2 (`grep '^sent,' data/changed.csv | wc -l >> evidence/edge.txt`) and in the guided practice (`evidence/practice.txt`). Using `>` would overwrite and truncate `evidence/edge.txt`, erasing the `0` recorded from the `no-match.csv` test.
4. **What does `tee` do that `>` alone does not?**
   `tee` duplicates standard input, writing it to a file while simultaneously passing it to standard output (the terminal or next pipe stage). Using `>` alone redirects output only to the file and displays nothing on screen.
5. **Why must `echo $?` immediately follow the command being checked?**
   The shell updates `$?` after every foreground command finishes. Running any command in between—even inspecting a file with `cat`—overwrites `$?` with that new command's exit status.
6. **Why can `cat missing-file | wc -l` report pipeline status 0?**
   By default, a pipeline returns the exit status of its rightmost command (`wc -l`). When `cat` fails on a missing file, it writes its error to stderr and sends 0 bytes to stdout; `wc -l` successfully counts `0` lines from empty input and exits with status `0`.

## Limits and Evidence

These commands assume simple comma-separated text without quoted commas. Saved results describe one run; they do not prove every future input works or who typed a command.

Check the submission tree in the instruction: include `checkpoint.txt` and all required evidence files, including the empty `stdout.txt`. No `report.sh` is required.
