#!usr/bin/env bats

main() {
  if [ $# -eq 0 ]; then
    echo "Usage: error_handling.sh <person>"
    exit 1
  fi

  if [ $# -gt 1 ]; then
    echo "Usage: error_handling.sh <person>"
    exit 1
  fi

  if [ -z "${1}" ]; then
    echo "Hello, "
    exit 0
  fi

  echo "Hello, $1"
}

main "$@"
