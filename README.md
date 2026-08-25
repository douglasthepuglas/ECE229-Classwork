# ECE 229 — your lab repository

This is where you write your C programs this semester. It comes set up with the
compiler, the editor settings this course uses, and **Donna**, the course assistant.

> **Labs are submitted on Brightspace.** This repository is where your work *lives* —
> it keeps it safe and versioned — but turning a lab in means uploading the file to
> Brightspace. Committing is not submitting.

## Writing and running a program

1. Open the `.c` file you want to build.
2. Press **Ctrl+Shift+B** (**Cmd+Shift+B** on a Mac) to compile it.
3. Run it from the terminal — the program is next to your source file with an `.exe`
   extension:

   ```
   ./lab01/hello.exe
   ```

The build uses `gcc -Wall -Wextra -std=c99` — the same flags used everywhere else in
this course, so the warnings you see are the warnings your instructor sees. **Warnings
are not noise.** In C they are usually the compiler telling you about a bug that will
bite you later.

## Saving your work

Saving the file in the editor is *not* enough — Codespaces are temporary.

1. **Stage** — Source Control icon on the left, then `+` next to each changed file.
2. **Commit** — write a short description, press Commit.
3. **Sync** — press Sync Changes. *Now* it's on GitHub.

Do this at the end of every session. It takes ten seconds and it has saved a lot of
people's labs.

## Donna

Ask her anything about C or the course. She explains, reads your code, and translates
compiler errors — she will **not** write your lab for you, which is the point: the
exams are on paper, and the only way to be ready is to have written the code yourself.

**In the terminal:**

```
donna "what does 'expected declaration specifiers' mean?"
gcc -Wall lab03/main.c 2>&1 | donna      # explain what the compiler just said
donna compile lab03/main.c               # compile it and ask her about the result
```

**In the sidebar:** click her icon in the left-hand activity bar. You can drag her
panel wherever you like. **If you close her and can't find her again**, click
**Donna** in the status bar along the bottom, or press **Ctrl+Alt+D**.

**In your browser or on Discord:** she's the same assistant at
<https://ece229.billwestrick.com> and in the class Discord server.

### Connect your account (once)

So she remembers one conversation everywhere:

1. Sign in at <https://ece229.billwestrick.com>.
2. Type **`link`** in the chat with her there — she replies with a 6-character code.
3. Back here, run:

   ```
   donna link ABC123
   ```

Until you do, she'll still help — she just won't know that the person in the terminal
is the same person who asked her something on the website last week.

## Notes on this setup

- **GitHub Copilot is turned off for C in this repository.** Not to make life harder:
  Copilot will write a whole intro-C lab from a comment, which feels like progress and
  teaches nothing. Donna is here instead, and she asks questions rather than answering
  them for you.
- Compiled programs (`*.exe`) are ignored by git on purpose — only your source code
  belongs in the repository.
