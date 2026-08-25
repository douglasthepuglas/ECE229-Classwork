#!/usr/bin/env bash
# Runs once, when your Codespace is first created. Installs Donna.
#
# Nothing here is required for writing C -- if a step fails, your compiler and
# your labs still work exactly as normal.

set -u

echo ""
echo "Setting up your ECE 229 workspace..."

# ---- the `donna` command -------------------------------------------------
if [ -f tools/donna ]; then
  if install -m 0755 tools/donna /usr/local/bin/donna 2>/dev/null \
     || sudo install -m 0755 tools/donna /usr/local/bin/donna 2>/dev/null; then
    echo "  [ok] 'donna' command installed - try:  donna \"what is a pointer?\""
  else
    # Fall back to the user's own bin directory rather than giving up.
    mkdir -p "$HOME/.local/bin"
    cp tools/donna "$HOME/.local/bin/donna" && chmod +x "$HOME/.local/bin/donna"
    case ":$PATH:" in
      *":$HOME/.local/bin:"*) ;;
      *) echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc" ;;
    esac
    echo "  [ok] 'donna' installed to ~/.local/bin (open a new terminal to use it)"
  fi
fi

echo ""
echo "Ready. Labs are submitted on Brightspace - see README.md."
echo ""
