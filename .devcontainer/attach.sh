#!/usr/bin/env bash
# Runs each time you attach to this Codespace. Installs the Donna panel.
#
# This is separate from setup.sh because the `code` CLI only works once the
# editor has attached -- during postCreateCommand it silently fails, which is
# why the panel used to be missing. Best-effort either way: the `donna`
# terminal command is installed by setup.sh and works regardless.

set -u

vsix=$(ls /workspaces/*/tools/donna-ece229-*.vsix tools/donna-ece229-*.vsix 2>/dev/null | tail -1)
[ -z "${vsix:-}" ] && exit 0
command -v code >/dev/null 2>&1 || exit 0

# The marker records WHICH version was installed, so bumping the .vsix
# reinstalls instead of being skipped forever.
marker="$HOME/.donna-extension-installed"
want=$(basename "$vsix")
[ -f "$marker" ] && [ "$(cat "$marker" 2>/dev/null)" = "$want" ] && exit 0

if code --install-extension "$vsix" --force >/dev/null 2>&1; then
  printf '%s' "$want" > "$marker"
  echo "Donna is installed. Her icon is in the left sidebar; if you ever close her,"
  echo "click 'Donna' in the status bar at the bottom, or press Ctrl+Alt+D."
else
  echo "The Donna panel didn't install; the 'donna' terminal command still works."
fi
